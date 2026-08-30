<?php 
include('crssession.php');
if(!session_id()) {
    session_start();
}

include 'headerstudent.php';
include 'db_connect.php';

$uic = $_SESSION['funame']; // Get user ID
$current_semester = "2024/2025-2"; // Current semester allowed for modification

// Handle course modification (Semester is not editable)
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['update_registration'])) {
    $r_tid = $_POST['r_tid'];
    $new_course = $_POST['new_course'];
    
    $update_sql = "UPDATE tb_registration SET r_course = '$new_course' WHERE r_tid = '$r_tid' AND r_student = '$uic' AND r_sem = '$current_semester' AND r_status = 1";
    mysqli_query($con, $update_sql);
    echo "<script>alert('Course updated successfully!'); window.location='courseview.php';</script>";
}

// Handle course cancellation
if (isset($_GET['cancel_tid'])) {
    $r_tid = $_GET['cancel_tid'];
    $delete_sql = "DELETE FROM tb_registration WHERE r_tid = '$r_tid' AND r_student = '$uic' AND r_status = 1";
    mysqli_query($con, $delete_sql);
    echo "<script>alert('Registration canceled successfully!'); window.location='courseview.php';</script>";
}

// Get selected semester filter
$selected_semester = isset($_GET['semester']) ? $_GET['semester'] : '';

// Fetch registered courses filtered by semester
$sql = "SELECT * FROM tb_registration
        LEFT JOIN tb_course ON tb_registration.r_course = tb_course.c_code
        LEFT JOIN tb_status ON tb_registration.r_status = tb_status.s_id
        WHERE r_student = '$uic'";

if (!empty($selected_semester)) {
    $sql .= " AND r_sem = '$selected_semester'";
}

$result = mysqli_query($con, $sql);
$no_results = mysqli_num_rows($result) == 0;

// Fetch courses for dropdown
$courses_query = "SELECT c_code, c_name FROM tb_course";
$courses_result = mysqli_query($con, $courses_query);
$courses = [];
while ($row = mysqli_fetch_assoc($courses_result)) {
    $courses[$row['c_code']] = $row['c_name'];
}

// Fetch all distinct semesters for dropdown
$semester_query = "SELECT DISTINCT r_sem FROM tb_registration WHERE r_student = '$uic' ORDER BY r_sem DESC";
$semester_result = mysqli_query($con, $semester_query);
?>

<div class="container"><br>
  <h4>View Your Courses</h4>
  <p class="text-secondary-emphasis" style="font-style: italic; font-weight: bold;">You can only modify next semester course registration.</p>
  <form method="GET" action="courseview.php">
    <label for="semester">Select Semester:</label>
    <select name="semester" id="semester" class="form-select" onchange="this.form.submit()">
      <option value="">--All Semesters--</option>
      <?php 
      while ($sem_row = mysqli_fetch_array($semester_result)) {
        $sem_value = $sem_row['r_sem'];
        $selected = ($sem_value == $selected_semester) ? 'selected' : '';
        echo "<option value='$sem_value' $selected>Semester $sem_value</option>";
      }
      ?>
    </select>
  </form>
  <br>
  <table class="table table-striped table-hover">
    <thead>
      <tr>
        <th>Transaction ID</th>
        <th>Semester</th>
        <th>Course</th>
        <th>Course Name</th>
        <th>Status</th>
        <th>Actions</th>
      </tr>
    </thead>
    <tbody>
      <?php while ($row = mysqli_fetch_array($result)) { ?>
        <tr>
          <td><?php echo $row['r_tid']; ?></td>
          <td><?php echo $row['r_sem']; ?></td>
          <td><?php echo $row['r_course']; ?></td>
          <td><?php echo $row['c_name']; ?></td>
          <td><?php echo $row['s_desc']; ?></td>
          <td>
            <?php if ($row['r_status'] == 2 && $row['r_sem'] == $current_semester) { ?>
              <form method="POST" class="d-none" id="modifyForm<?php echo $row['r_tid']; ?>">
                <input type="hidden" name="r_tid" value="<?php echo $row['r_tid']; ?>">
                <select name="new_course" class="form-select mb-1">
                  <?php foreach ($courses as $code => $name) {
                      $selected = ($row['r_course'] == $code) ? "selected" : "";
                      echo "<option value='$code' $selected>$name</option>";
                  } ?>
                </select>
                <button type="submit" name="update_registration" class="btn btn-success btn-sm">Save</button>
                <button type="button" class="btn btn-secondary btn-sm" onclick="hideModifyForm(<?php echo $row['r_tid']; ?>)">Cancel</button>
              </form>
              <button class="btn btn-warning btn-sm" onclick="showModifyForm(<?php echo $row['r_tid']; ?>)">Modify</button>
              <a href="?cancel_tid=<?php echo $row['r_tid']; ?>" class="btn btn-danger btn-sm" onclick="return confirm('Are you sure you want to cancel this registration?');">Cancel</a>
            <?php } else { ?>
              <span class='text-muted'>Not Editable</span>
            <?php } ?>
          </td>
        </tr>
      <?php } ?>
    </tbody>
  </table> 
</div>
<script>
  function showModifyForm(id) {
      document.getElementById('modifyForm' + id).classList.remove('d-none');
  }
  function hideModifyForm(id) {
      document.getElementById('modifyForm' + id).classList.add('d-none');
  }
</script>

<div class="footer mt-4">
    <p>CRS developed by Adriana @ 2024</p>
</div>
<?php include 'footer.php'; ?>
