<?php 
include('crssession.php');
if(!session_id()) {
  session_start();
}

include 'headerstudent.php';
include 'db_connect.php';

$user_id = isset($_SESSION['funame']) ? $_SESSION['funame'] : 'Guest';

// Fetch the student's data from the tb_user table using the student number
$query = "SELECT u_sno, u_email, u_name, u_contact, u_state, u_reg, u_utype FROM tb_user WHERE u_sno = ?";
$stmt = mysqli_prepare($con, $query);
mysqli_stmt_bind_param($stmt, 's', $user_id);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);
$user_data = mysqli_fetch_assoc($result);

// Check if data exists
if (!$user_data) {
    echo "No user found!";
    exit;
}

// If the form is submitted, update the student's information
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $u_name = mysqli_real_escape_string($con, $_POST['u_name']);
    $u_email = mysqli_real_escape_string($con, $_POST['u_email']);
    $u_contact = mysqli_real_escape_string($con, $_POST['u_contact']);
    $u_state = mysqli_real_escape_string($con, $_POST['u_state']);
    $u_reg = mysqli_real_escape_string($con, $_POST['u_reg']);
    $u_utype = mysqli_real_escape_string($con, $_POST['u_utype']);

    // Update query
    $update_query = "UPDATE tb_user SET u_name = ?, u_email = ?, u_contact = ?, u_state = ?, u_reg = ?, u_utype = ? WHERE u_sno = ?";
    $update_stmt = mysqli_prepare($con, $update_query);
    mysqli_stmt_bind_param($update_stmt, 'sssssss', $u_name, $u_email, $u_contact, $u_state, $u_reg, $u_utype, $user_id);
    mysqli_stmt_execute($update_stmt);

    // If the update is successful
    if (mysqli_stmt_affected_rows($update_stmt) > 0) {
        echo "<div class='alert alert-success'>Profile updated successfully!</div>";
    } else {
        echo "<div class='alert alert-danger'>Failed to update profile. Please try again.</div>";
    }
}
?>

<div class="container"><br>
  <h1>Welcome, <?php echo htmlspecialchars($user_data['u_name']); ?>!</h1>

  <!-- Profile Edit Form -->
  <form method="POST" action="">
    <div class="mb-3">
      <label for="u_name" class="form-label">Full Name</label>
      <input type="text" class="form-control" id="u_name" name="u_name" value="<?php echo htmlspecialchars($user_data['u_name']); ?>" required>
    </div>
    <div class="mb-3">
      <label for="u_email" class="form-label">Email</label>
      <input type="email" class="form-control" id="u_email" name="u_email" value="<?php echo htmlspecialchars($user_data['u_email']); ?>" required>
    </div>
    <div class="mb-3">
      <label for="u_contact" class="form-label">Contact Number</label>
      <input type="text" class="form-control" id="u_contact" name="u_contact" value="<?php echo htmlspecialchars($user_data['u_contact']); ?>" required>
    </div>
    <div class="mb-3">
      <label for="u_state" class="form-label">State</label>
      <input type="text" class="form-control" id="u_state" name="u_state" value="<?php echo htmlspecialchars($user_data['u_state']); ?>" required>
    </div>
    <div class="mb-3">
      <label for="u_reg" class="form-label">Registration Date</label>
      <input type="text" class="form-control" id="u_reg" name="u_reg" value="<?php echo htmlspecialchars($user_data['u_reg']); ?>" required>
    </div>
    <div class="mb-3">
      <label for="u_utype" class="form-label">User Type</label>
      <input type="text" class="form-control" id="u_utype" name="u_utype" value="<?php echo htmlspecialchars($user_data['u_utype']); ?>" required>
    </div>

    <button type="submit" class="btn btn-primary">Update Profile</button>
  </form>
</div><br><br>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

<?php include 'footer.php';?>
