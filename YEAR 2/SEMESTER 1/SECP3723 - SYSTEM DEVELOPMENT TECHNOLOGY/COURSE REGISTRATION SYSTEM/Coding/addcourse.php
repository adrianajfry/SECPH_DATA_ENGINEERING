<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

include('crssession.php');
if (!session_id()) {
  session_start();
}

include 'headeradmin.php';
include 'db_connect.php'; // Connect to DB

// Handle Course Deletion
if (isset($_GET['delete'])) {
  $course_id = $_GET['delete'];
  $delete_sql = "DELETE FROM tb_course WHERE c_code = '$course_id'";
  if (mysqli_query($con, $delete_sql)) {
    echo "<script>alert('Course deleted successfully'); window.location.href='addcourse.php';</script>";
  } else {
    echo "<script>alert('Error deleting course');</script>";
  }
}

// Handle course addition
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['c_code'])) {
  $c_code = mysqli_real_escape_string($con, $_POST['c_code']);
  $c_name = mysqli_real_escape_string($con, $_POST['c_name']);
  $c_credit = mysqli_real_escape_string($con, $_POST['c_credit']);
  $c_lec = mysqli_real_escape_string($con, $_POST['c_lec']);
  $c_max = mysqli_real_escape_string($con, $_POST['c_max']);
  $c_sem = mysqli_real_escape_string($con, $_POST['c_sem']);

  // Check if Lecturer ID starts with 'L'
  if (strpos($c_lec, 'L') !== 0) {
    echo "<script>alert('Lecturer ID must start with the letter L.');</script>";
    exit;
  }

  // Check if the Lecturer ID exists in the users table
  $lec_check_sql = "SELECT * FROM tb_user WHERE u_sno = '$c_lec'";
  $lec_check_result = mysqli_query($con, $lec_check_sql);
  if (mysqli_num_rows($lec_check_result) == 0) {
    echo "<script>alert('Lecturer ID does not exist in the database.');</script>";
    exit;
  }

  // Check if the course code already exists
  $course_check_sql = "SELECT * FROM tb_course WHERE c_code = '$c_code'";
  $course_check_result = mysqli_query($con, $course_check_sql);
  if (mysqli_num_rows($course_check_result) > 0) {
    echo "<script>alert('Course code already exists. Please use a unique course code.');</script>";
    exit;
  }

  // Insert the new course into the database
  $insert_sql = "INSERT INTO tb_course (c_code, c_name, c_credit, c_lec, c_max, c_sem) VALUES ('$c_code', '$c_name', '$c_credit', '$c_lec', '$c_max', '$c_sem')";
  if (mysqli_query($con, $insert_sql)) {
    $_SESSION['course_added'] = true; // Set session variable to indicate success
    header("Location: addcourse.php"); // Redirect to clear POST data
    exit;  // Make sure no further code runs after redirection
  } else {
    echo "<script>alert('Error adding course');</script>";
  }
}

// Get the selected semester
$selected_semester = isset($_POST['semester']) ? mysqli_real_escape_string($con, $_POST['semester']) : '';

// Fetch courses based on semester (if selected)
$sql = "SELECT * FROM tb_course WHERE c_sem LIKE '%$selected_semester%'";
$result = mysqli_query($con, $sql);

// Alert for displaying courses of selected semester
if ($selected_semester) {
    echo '<div class="alert alert-dismissible alert-primary">
            <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
            <strong>Scroll below!</strong> Only the courses of the selected semester are displayed.
          </div>';
}

// Display success message after adding course (only after redirection)
if (isset($_SESSION['course_added']) && $_SESSION['course_added'] === true) {
    echo "<div class='alert alert-dismissible alert-info'>
            <button type='button' class='btn-close' data-bs-dismiss='alert'></button>
            <strong>Heads up!</strong> A new course has been successfully added.
          </div>";
    unset($_SESSION['course_added']); // Clear the session variable
}
?>

<div class="container"><br>
  <h2>Add Courses</h2>
  <!-- Add Course Form -->
  <form action="addcourse.php" method="post">
    <div class="mb-3">
      <label for="c_code" class="form-label">Course Code</label>
      <input type="text" class="form-control" name="c_code" required>
    </div>
    <div class="mb-3">
      <label for="c_name" class="form-label">Course Name</label>
      <input type="text" class="form-control" name="c_name" required>
    </div>
    <div class="mb-3">
      <label for="c_credit" class="form-label">Credit Hours</label>
      <input type="number" class="form-control" name="c_credit" required>
    </div>
    <div class="mb-3">
      <label for="c_lec" class="form-label">Lecturer ID</label>
      <input type="text" class="form-control" name="c_lec" required>
    </div>
    <div class="mb-3">
      <label for="c_max" class="form-label">Max Students</label>
      <input type="number" class="form-control" name="c_max" required>
    </div>
    <div class="mb-3">
      <label for="c_sem" class="form-label">Semester</label>
      <select class="form-select" name="c_sem" required>
        <option value="">-- Select Semester --</option>
        <option value="2024/2025-1">2024/2025-1</option>
        <option value="2024/2025-2">2024/2025-2</option>
      </select>
    </div>
    <button type="submit" class="btn btn-primary">Add Course</button>
    <button type="reset" class="btn btn-warning">Clear</button>
  </form>
  <br><br>

  <!-- View Courses by Semester -->
  <h2>View Existing Courses</h2>
  <form action="addcourse.php" method="POST">
    <label for="semester" class="form-label">Select Semester:</label>
    <select id="semester" name="semester" class="form-select" onchange="this.form.submit()">
      <option value="">--All Semester is Displayed--</option>
      <?php
        $semesters_query = "SELECT DISTINCT c_sem FROM tb_course ORDER BY c_sem DESC";
        $semesters_result = mysqli_query($con, $semesters_query);
        while ($row = mysqli_fetch_assoc($semesters_result)) {
          $selected = $row['c_sem'] == $selected_semester ? 'selected' : '';
          echo "<option value='{$row['c_sem']}' $selected>{$row['c_sem']}</option>";
        }
      ?>
    </select>
  </form>

  <!-- Course Table -->
  <table class="table table-striped table-hover">
    <thead>
      <tr>
        <th scope="col">Course Code</th>
        <th scope="col">Course Name</th>
        <th scope="col">Credit Hours</th>
        <th scope="col">Lecturer</th>
        <th scope="col">Max Students</th>
        <!-- <th scope="col">Actions</th> -->
      </tr>
    </thead>
    <tbody>
      <?php
      if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
          echo "<tr>";
          echo "<td>".$row['c_code']."</td>";
          echo "<td>".$row['c_name']."</td>";
          echo "<td>".$row['c_credit']."</td>";
          echo "<td>".$row['c_lec']."</td>";
          echo "<td>".$row['c_max']."</td>";
          // echo "<td><a href='addcourse.php?delete=".$row['c_code']."' class='btn btn-danger btn-sm' onclick='return confirm(\"Are you sure?\");'>Delete</a></td>";
          echo "</tr>";
        }
      } else {
        echo "<tr><td colspan='6' class='text-center'>No courses available for this semester</td></tr>";
      }
      ?>
    </tbody>
  </table>
</div>
<br>
<br>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php'; ?>
