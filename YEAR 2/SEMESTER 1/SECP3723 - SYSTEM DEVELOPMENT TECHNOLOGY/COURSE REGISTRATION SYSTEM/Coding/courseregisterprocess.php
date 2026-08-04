<?php 
include('crssession.php');
if(!session_id()) 
{
  session_start();
}
include 'db_connect.php';

// Retrieve data from form
$uic = $_SESSION['funame'];
$fcourse = $_POST['fcourse'];
$fsem = $_POST['fsem'];

// Check the current number of registrations for the selected course
$count_query = "SELECT COUNT(*) AS total FROM tb_registration WHERE r_course = '$fcourse'";
$result = mysqli_query($con, $count_query);
$row = mysqli_fetch_assoc($result);
$current_count = $row['total'];

// Get the maximum allowed registrations (c_max) from tb_course
$max_query = "SELECT c_max FROM tb_course WHERE c_code = '$fcourse'";
$max_result = mysqli_query($con, $max_query);
$max_row = mysqli_fetch_assoc($max_result);
$c_max = $max_row['c_max'];

if ($current_count < $c_max) {
    // Allow registration
    $sql = "INSERT INTO tb_registration (r_student, r_course, r_sem, r_status)
            VALUES ('$uic', '$fcourse', '$fsem', '2')";

    if (mysqli_query($con, $sql)) {
        header('Location: courseview.php');
        exit();
    } else {
        $_SESSION['error_message'] = "Error: " . mysqli_error($con);
        header('Location: courseregister.php');
        exit();
    }
} else {
    // Reject registration if course is full
    $_SESSION['warning_message'] = "The course is full. Please select another course.";
    header('Location: courseregister.php');
    exit();
}

// Close connection
mysqli_close($con);
?>
