<?php include 'headermain.php'; ?>

<div class="container">
  <br><br><br>

  <h4>Please fill all the following details</h4><br>
  <form method="POST" action="registerprocess.php" onsubmit="return validatePassword()">
    <fieldset>
      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please enter your staff or student id</label>
        <input type="text" name="funame" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your staff or student id">
      </div>

      <div>
        <label for="exampleInputPassword1" class="form-label mt-4">Please create your password</label>
        <input type="password" name="fpwd" class="form-control" id="exampleInputPassword1" placeholder="Create password" autocomplete="off" required>
      </div>

      <div>
        <label for="exampleInputPassword2" class="form-label mt-4">Please confirm your password</label>
        <input type="password" name="fconfirm_pwd" class="form-control" id="exampleInputPassword2" placeholder="Confirm password" autocomplete="off" required>
      </div>

      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please enter your full name</label>
        <input type="text" name="fname" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your full name" required>
      </div>

      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please enter your email address</label>
        <input type="text" name="femail" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your email address" required>
      </div>

      <div>
        <label for="exampleInputEmail1" class="form-label mt-4">Please enter your mobile number</label>
        <input type="text" name="fcontact" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your mobile number" required>
      </div>

      <div>
        <label for="exampleSelect1" class="form-label mt-4">Please select your role</label>
        <select name="futype" id="futype">
          <option>--Select role--</option>
          <option value="1">Student</option>
          <option value="2">Lecturer</option>
          <option value="3">Admin</option>
        </select>
      </div>

      <div>
        <label for="exampleSelect1" class="form-label mt-4">Please select your state</label>
        <select class="form-select" name="fstate" id="exampleSelect1" required>
          <option>Select your state</option>
          <option>Johor</option>
          <option>Kedah</option>
          <option>Kelantan</option>
          <option>Melaka</option>
          <option>Negeri Sembilan</option>
          <option>Pahang</option>
          <option>Penang</option>
          <option>Perak</option>
          <option>Perlis</option>
          <option>Sabah</option>
          <option>Sarawak</option>
          <option>Selangor</option>
          <option>Terengganu</option>
          <option>W.P. Kuala Lumpur</option>
          <option>W.P. Labuan</option>
          <option>Putrajaya</option>
        </select>
      </div><br>

      <fieldset>
        <button type="submit" class="btn btn-primary">Submit</button>
        <button type="reset" class="btn btn-warning">Clear Form</button>
        <a href="login.php" class="text-primary text-decoration-underline">Have Account? Log in</a>
        <br><br><br>
      </fieldset>
    </form>
  </div><br>

  <div class="footer">
    <p>CRS developed by Adriana @ 2025</p>
  </div>

  </body>
</html>

<?php include 'footer.php';?>

<script>
// JavaScript function to validate the password fields
function validatePassword() {
    var password = document.getElementById('exampleInputPassword1').value;
    var confirmPassword = document.getElementById('exampleInputPassword2').value;
    
    if (password !== confirmPassword) {
        alert("Passwords do not match. Please try again.");
        return false;
    }
    return true;
}
</script>