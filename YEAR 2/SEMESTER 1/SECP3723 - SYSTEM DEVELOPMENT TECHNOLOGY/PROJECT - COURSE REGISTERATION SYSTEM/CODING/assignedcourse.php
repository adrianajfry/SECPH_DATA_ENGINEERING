<?php 
include('crssession.php');
if (!session_id()) {
    session_start();
}

include 'headerlecturer.php';
include 'db_connect.php'; // Ensure DB connection

// Get the logged-in lecturer's ID from session
$user_id = isset($_SESSION['funame']) ? $_SESSION['funame'] : 'Guest';

// If no valid user ID, show an error
if ($user_id == 'Guest') {
    die("<div class='container'><p>Error: Lecturer ID not found.</p></div>");
}

// Fetch courses assigned to the lecturer
$sql = "SELECT c_sem, c_code, c_name, c_credit, c_max FROM tb_course WHERE c_lec = '$user_id' ORDER BY c_sem DESC, c_code ASC";
$result = mysqli_query($con, $sql);

// Debugging: Check if query runs successfully
if (!$result) {
    die("<div class='container'><p>Error: " . mysqli_error($con) . "</p></div>");
}

// Store courses by semester
$courses_by_semester = [];
while ($row = mysqli_fetch_assoc($result)) {
    $semester = $row['c_sem'];
    $courses_by_semester[$semester][] = $row;
}

?>

<div class="container"><br>
  <h2>Assigned Courses</h2>
  <br>
  <?php if (!empty($courses_by_semester)): ?>
    <?php foreach ($courses_by_semester as $semester => $courses): ?>
      <h4>Semester: <?php echo htmlspecialchars($semester); ?></h4>
      <table class="table table-striped">
        <thead>
          <tr>
            <th scope="col">Course Code</th>
            <th scope="col">Course Name</th>
            <th scope="col">Credit Hours</th>
            <th scope="col">Max Students</th>
          </tr>
        </thead>
        <tbody>
          <?php foreach ($courses as $course): ?>
            <tr>
              <td><?php echo htmlspecialchars($course['c_code']); ?></td>
              <td><?php echo htmlspecialchars($course['c_name']); ?></td>
              <td><?php echo htmlspecialchars($course['c_credit']); ?></td>
              <td><?php echo htmlspecialchars($course['c_max']); ?></td>
            </tr>
          <?php endforeach; ?>
        </tbody>
      </table>
    <?php endforeach; ?>
  <?php else: ?>
    <p>No courses assigned to you.</p>
  <?php endif; ?>
</div>
<br><br>
<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php'; ?>
