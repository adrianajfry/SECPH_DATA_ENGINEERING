<?php
$current_page = basename($_SERVER['PHP_SELF']);
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <title>Course Registration System</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link href="css/bootstrap.min.css" rel="stylesheet">
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body>

<nav class="navbar navbar-expand-lg bg-primary" data-bs-theme="dark">
  <div class="container-fluid">
    <img src="img/utm.png" alt="UTM" style="height: 80px;">
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarColor01" aria-controls="navbarColor01" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarColor01">
      <ul class="navbar-nav me-auto">
        <li class="nav-item">
          <a class="nav-link <?= ($current_page == 'lecturer.php') ? 'active' : '' ?>" href="lecturer.php">Dashboard</a>
          </a>
        </li>
        <li class="nav-item">
           <a class="nav-link <?= ($current_page == 'assignedcourse.php') ? 'active' : '' ?>" href="assignedcourse.php">View Assigned Course</a>
        </li>
        <li class="nav-item">
           <a class="nav-link <?= ($current_page == 'viewstudent.php') ? 'active' : '' ?>" href="viewstudent.php">View Students</a>
        </li>
        <li class="nav-item">
           <a class="nav-link <?= ($current_page == 'logout.php') ? 'active' : '' ?>" href="logout.php">Logout</a>
        </li>
      </ul>
    </div>
  </div>
</nav>