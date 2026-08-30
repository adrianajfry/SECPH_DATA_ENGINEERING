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

// Fetch available semesters
$semester_query = "SELECT DISTINCT r_sem FROM tb_registration";
$semester_result = mysqli_query($con, $semester_query);
$semesters = [];
while ($row = mysqli_fetch_assoc($semester_result)) {
    $semesters[] = $row['r_sem'];
}

// Get selected semester
$selected_semester = isset($_GET['semester']) ? $_GET['semester'] : (isset($semesters[0]) ? $semesters[0] : '');

// Fetch courses assigned to the lecturer
$sql = "SELECT c_code, c_name FROM tb_course WHERE c_lec = '$user_id'";
$result = mysqli_query($con, $sql);

$courses = [];
while ($row = mysqli_fetch_assoc($result)) {
    $courses[$row['c_code']] = $row['c_name'];
}

// Fetch students registered for these courses in the selected semester
$students_by_course = [];
if (!empty($courses) && $selected_semester) {
    $course_codes = implode("','", array_keys($courses));
    $sql = "SELECT r.r_course, u.u_sno, u.u_name, u.u_email, u.u_contact FROM tb_registration r 
            JOIN tb_user u ON r.r_student = u.u_sno
            WHERE r.r_course IN ('$course_codes') AND r.r_sem = '$selected_semester'";
    $result = mysqli_query($con, $sql);
    
    while ($row = mysqli_fetch_assoc($result)) {
        $students_by_course[$row['r_course']][] = $row;
    }
}
?>

<div class="container"><br>
  <h2>Registered Students</h2>
  
  <form method="GET" class="mb-3">
    <label for="semester">Select Semester:</label>
    <select name="semester" id="semester" class="form-control" onchange="this.form.submit()">
      <?php foreach ($semesters as $semester): ?>
        <option value="<?php echo htmlspecialchars($semester); ?>" <?php echo ($semester == $selected_semester) ? 'selected' : ''; ?>>
          <?php echo htmlspecialchars($semester); ?>
        </option>
      <?php endforeach; ?>
    </select>
  </form>

  <div class="accordion" id="accordionExample">
    <?php if (!empty($students_by_course)): ?>
      <?php $i = 1; ?>
      <?php foreach ($students_by_course as $course_code => $students): ?>
        <div class="accordion-item">
          <h2 class="accordion-header" id="heading<?php echo $i; ?>">
            <button class="accordion-button" type="button" data-bs-toggle="collapse" data-bs-target="#collapse<?php echo $i; ?>" aria-expanded="true" aria-controls="collapse<?php echo $i; ?>">
              Course: <?php echo htmlspecialchars($courses[$course_code]); ?> (<?php echo htmlspecialchars($course_code); ?>) - <?php echo count($students); ?> students
            </button>
          </h2>
          <div id="collapse<?php echo $i; ?>" class="accordion-collapse collapse" aria-labelledby="heading<?php echo $i; ?>" data-bs-parent="#accordionExample">
            <div class="accordion-body">
              <table class="table table-striped">
                <thead>
                  <tr>
                    <th scope="col">Student ID</th>
                    <th scope="col">Name</th>
                    <th scope="col">Email</th>
                    <th scope="col">Contact</th>
                  </tr>
                </thead>
                <tbody>
                  <?php foreach ($students as $student): ?>
                    <tr>
                      <td><?php echo htmlspecialchars($student['u_sno']); ?></td>
                      <td><?php echo htmlspecialchars($student['u_name']); ?></td>
                      <td><?php echo htmlspecialchars($student['u_email']); ?></td>
                      <td><?php echo htmlspecialchars($student['u_contact']); ?></td>
                    </tr>
                  <?php endforeach; ?>
                </tbody>
              </table>
            </div>
          </div>
        </div>
        <?php $i++; ?>
      <?php endforeach; ?>
    <?php else: ?>
      <p>No students registered for your courses in this semester.</p>
    <?php endif; ?>
  </div>
</div>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php'; ?>
