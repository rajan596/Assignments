<?php

session_start();

/* If form is submitted then authenticate it*/
if(isset($_POST['submit'])) {

	$username=$_POST['username'];
	$password=$_POST['password'];

	$conn =mysqli_connect("localhost","root","","blog");

	/* Check connection */
	if(mysqli_connect_error()) {
		echo "Connection failed";
		printf("Error : %s",mysqli_connect_error());
	} 

	/* Check login  correctness*/
	$query="SELECT * FROM user WHERE username='$username' AND password='$password' ";
	$result=mysqli_query($conn , $query);
	$rows=mysqli_num_rows($result);

	if($rows==1) {
		$_SESSION['username']=$username;
		$_SESSION['password']=$password;

		printf("Welcome %s\n",$username);
		printf("Successfully logged in");

		header("location:../index.php");
	} else {
		printf("Username or password is incorrect\n");
		printf("Login Again ");
		echo "<a href='login.php' >Login</a>";

	}
}
/* Login form */
else {
	echo "
		<body>
		<form action='login.php' method='POST'>
		<input type='text' name='username' value='Use Name'><br>
		<input type='password' name='password' value='Password'><br>
		<input type='submit' name='submit' value='Login'><br>
	</form>
	";

}

?>