<?php
session_start();

// Connect to DB
include('db_connect.php');

// Retrieve data from form
$funame = $_POST['funame'];
$fpwd = $_POST['fpwd'];

// SQL query to fetch user details
$sql = "SELECT * FROM tb_user WHERE u_sno = '$funame'";

// Execute SQL
$result = mysqli_query($con, $sql);

// Retrieve data
$row = mysqli_fetch_array($result);

// Count result to check if user exists
$count = mysqli_num_rows($result);

if ($count == 1) { // User exists
    // Verify the hashed password using password_verify
    if (password_verify($fpwd, $row['u_pwd'])) {
        // Set session
        $_SESSION['u_sno'] = session_id();
        $_SESSION['funame'] = $funame;

        // Redirect based on user type
        if ($row['u_utype'] == 1) {
            // Lecturer
            header('Location: student.php');
        }
        if ($row['u_utype'] == 2) {
            // Student
            header('Location: lecturer.php');
        }
        if ($row['u_utype'] == 3) {
            // IT Staff
            header('Location: admin.php');
        }
    } else {
        // Incorrect password
        header('Location: login.php?error=Invalid password');
    }
} else {
    // User not found
    header('Location: login.php?error=User not found');
}

// Close connection
mysqli_close($con);
?>
