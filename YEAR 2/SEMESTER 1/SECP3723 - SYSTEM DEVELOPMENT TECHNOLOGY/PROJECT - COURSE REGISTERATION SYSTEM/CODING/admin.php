<?php
include('crssession.php');
if(!session_id()) {
  session_start();
}

include 'headeradmin.php';
$user_id = isset($_SESSION['funame']) ? $_SESSION['funame'] : 'Guest';

include 'db_connect.php'; // Ensure the database connection is included

// Get the selected semester from the form submission
$selected_c_sem = isset($_POST['c_sem']) ? mysqli_real_escape_string($con, $_POST['c_sem']) : '';

// SQL Query to fetch courses and the number of students registered
$sql = "
SELECT c.c_name, c.c_sem, c.c_max, COUNT(r.r_student) AS registered_students
FROM tb_course c
LEFT JOIN tb_registration r ON c.c_code = r.r_course AND c.c_sem = r.r_sem
WHERE 1=1"; // Base query

// Apply semester filter if a semester is selected
if ($selected_c_sem != '') {
    $sql .= " AND c.c_sem = '$selected_c_sem'";
}

$sql .= " 
GROUP BY c.c_name, c.c_sem, c.c_max
ORDER BY c.c_sem DESC";

$result = mysqli_query($con, $sql);
?>

<div class="container"><br>
  <h1>Welcome, <?php echo htmlspecialchars($user_id); ?>!</h1>
  <br><br>
  <h4>Course Registration Summary</h4>
  <form action="admin.php" method="POST">
    <label for="c_sem" class="form-label">Select Semester:</label>
    <select id="c_sem" name="c_sem" class="form-select" onchange="this.form.submit()">
      <option value="">--All Semester is Displayed--</option>
      <?php
        // Fetch available semesters
        $semesters_query = "SELECT DISTINCT c_sem FROM tb_course ORDER BY c_sem DESC";
        $semesters_result = mysqli_query($con, $semesters_query);
        while ($row = mysqli_fetch_assoc($semesters_result)) {
          $selected = ($row['c_sem'] == $selected_c_sem) ? 'selected' : '';
          echo "<option value='{$row['c_sem']}' $selected>{$row['c_sem']}</option>";
        }
      ?>
    </select>
  </form>
  <br>
  <table class="table table-bordered">
    <thead>
      <tr>
        <th>Course Name</th>
        <th>Semester</th>
        <th>Max Students</th>
        <th>Registered Students</th>
        <th>Progress</th>
      </tr>
    </thead>
    <tbody>
      <?php
      while ($row = mysqli_fetch_assoc($result)) {
        $registered = $row['registered_students'] ? $row['registered_students'] : 0;
        $max_students = $row['c_max'];
        $percentage = ($max_students > 0) ? ($registered / $max_students) * 100 : 0;
        
        echo "<tr>";
        echo "<td>" . htmlspecialchars($row['c_name']) . "</td>";
        echo "<td>" . htmlspecialchars($row['c_sem']) . "</td>";
        echo "<td>" . $max_students . "</td>";
        echo "<td>" . $registered . "</td>";
        echo "<td>
                <div class='progress'>
                  <div class='progress-bar progress-bar-striped progress-bar-animated' role='progressbar' aria-valuenow='$percentage' aria-valuemin='0' aria-valuemax='100' style='width: $percentage%;'></div>
                </div>
              </td>";
        echo "</tr>";
      }
      ?>
    </tbody>
  </table>
</div><br><br>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

</body>
</html>

<?php include 'footer.php'; ?>
