<!--  HEADER -->

<?php

echo "Welcome to blog <br>";

session_start();

if(isset($_SESSION['username'])) {
	echo $_SESSION['username'];
	//printf("Hello %s\n",$_SESSION['username']);
	echo "
		<a href='users/logout.php' >Logout</a>
	";
}
else {
	echo "
		<a href='users/login.php' >Login</a>
		<a href='users/register.php' >Register</a>
	";
}

echo "<a href='users/newpost.php'> New Post </a>";

?>
