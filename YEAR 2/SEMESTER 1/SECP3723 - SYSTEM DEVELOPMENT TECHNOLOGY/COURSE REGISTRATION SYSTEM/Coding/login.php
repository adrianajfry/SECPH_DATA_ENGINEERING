<?php include 'headermain.php';?>

<div class="container"> 
  <br><br><br>

  <h4>Please fill all to login</h4><br>
  <form method="POST" action="loginprocess.php">
  <fieldset>
    <div>
      <label for="exampleInputEmail1" class="form-label mt-4">Enter your staff or student id</label>
      <input type="text" name="funame" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter your staff or student id" required>
    </div>

    <div>
      <label for="exampleInputPassword1" class="form-label mt-4">Enter your password</label>
      <input type="password" name="fpwd" class="form-control" id="exampleInputPassword1" placeholder="Enter password" autocomplete="off" required>
    </div><br>

    
    <fieldset>
    <button type="submit" class="btn btn-primary">Login</button>
    <br><br><br>
  </fieldset>
</form>
</div><br>

<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

</body>
</html> 

<?php include 'footer.php';?>