<?php

if(isset($_POST['submit'])) {

	$username=$_POST['username'];
	$firstname=$_POST['firstname'];
	$emailid=$_POST['emailid'];
	$password=$_POST['password'];

	/* Connection to database */
	$conn =mysqli_connect("localhost","root","","blog");

	/* Check connection */
	if(mysqli_connect_error()) {
		echo "Connection failed";
		printf("Error : %s",mysqli_connect_error());
	} 

	/* CHECK if same user or email exists or not ? */
	$query="SELECT * FROM user WHERE username='$username' OR emailid='$emailid' ";
	$result=mysqli_query($conn , $query);
	$rows=mysqli_num_rows($result);

	if($rows > 0) {
		unset($_POST['submit']);
		header("location:register.php");
	} 
	else {
		$query="INSERT INTO user (username, firstname, password, emailid) 
				VALUES ('$username','$firstname','$password','$emailid')";
		mysqli_query($conn , $query);
		header("location:login.php");
	}
	
}

/* * * * * Registeration Form * * * * */
else {
	echo "
		<form action='register.php' method='POST' >
			<input type='text' name='username' value='username'></br>
			<input type='password' name='password' value='password'></br>
			<input type='text' name='firstname' value='First Name'></br>
			<input type='text' name='emailid' value='Email'></br>
			<input type='submit' name='submit' value='Register'></br>
		</form>
	";

}


?>