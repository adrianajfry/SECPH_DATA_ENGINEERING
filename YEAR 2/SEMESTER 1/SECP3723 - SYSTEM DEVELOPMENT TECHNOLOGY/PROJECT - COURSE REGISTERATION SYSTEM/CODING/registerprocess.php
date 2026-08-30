<?php
// Include the database connection
include('db_connect.php');  // Ensure dbconnect.php is in the correct location

// Check if form data is received
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Get form data
    $funame = $_POST['funame']; // Staff/Student Number
    $fpwd = password_hash($_POST['fpwd'], PASSWORD_BCRYPT); // Hash password
    $femail = $_POST['femail']; // Email
    $fname = $_POST['fname']; // Full Name
    $fcontact = $_POST['fcontact']; // Contact Number
    $fstate = $_POST['fstate']; // State
    $futype = $_POST['futype']; // User Type (1 = Lecturer, 2 = Student, 3 = Admin)

    // Insert into tb_user
    $sql_user = "INSERT INTO tb_user (u_sno, u_pwd, u_email, u_name, u_contact, u_state, u_reg, u_utype) 
                VALUES ('$funame', '$fpwd', '$femail', '$fname', '$fcontact', '$fstate', CURRENT_TIMESTAMP(), '$futype')";

    // Check if query is successful
    if (mysqli_query($con, $sql_user)) {
        // Redirect to login page or another page
        header('Location: login.php');
    } else {
        echo "Error: " . mysqli_error($con);
    }
}

// Close connection
mysqli_close($con);
?>
