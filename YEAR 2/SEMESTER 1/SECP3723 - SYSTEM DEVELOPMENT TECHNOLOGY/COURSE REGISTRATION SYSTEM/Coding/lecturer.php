<?php
include('crssession.php');
if(!session_id()) 
{
  session_start();
}

include 'headerlecturer.php';
$user_id = isset($_SESSION['funame']) ? $_SESSION['funame'] : 'Guest';
?>

<div class="container"><br>
  
<h1>Welcome, <?php echo htmlspecialchars($user_id); ?>!</h1>

<button type="button" class="btn btn-primary btn-lg">E-Learning</button>
<a href="https://www.utm.my/" class="btn btn-primary btn-lg" target="_blank">
    About UTM
</a>
<button type="button" class="btn btn-primary btn-lg">Activity</button>

</div>
<div class="footer">
  <p>CRS developed by Adriana @ 2024</p>
</div>

</body>
</html> 

<?php include 'footer.php';?>
