<?php
//set DB Parameter
$servername = "localhost:3307";
$username = "root";
$password = "";
$dbname = "db_crs";

//Connect DB
$con = mysqli_connect($servername, $username, $password, $dbname, 3307);  // Add the port if necessary

// Check connection
if (mysqli_connect_errno()) {
    die("Connection failed: " . mysqli_connect_error());
}
?>