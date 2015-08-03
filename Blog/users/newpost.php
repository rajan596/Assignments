<?php

if(isset($_POST['submit'])) {

	$postTitle=$_POST['title'];
	$postDesc=$_POST['description'];
	$postTag=$_POST['tag'];

	/* Connection to database */
	$conn =mysqli_connect("localhost","root","","blog");

	/* Check connection */
	if(mysqli_connect_error()) {
		echo "Connection failed";
		printf("Error : %s",mysqli_connect_error());
	} 

	/* CHECK if same user or email exists or not ? */
	$query="INSERT INTO posts (postTitle , postDesc , postTag)
			VALUES ('$postTitle' , '$postDesc' , '$postTag') ";
	mysqli_query($conn , $query);

	printf("Successfully posted your post\n");
	
}

/* * * * * POST Form * * * * */
else {
	echo "
		<form action='newpost.php' method='POST' >
			Title : <input type='text' name='title'></br>
			Description : <input type='text' name='description'></br>
			Tags : <input type='text' name='tag'></br>
			<input type='submit' name='submit' value='Publish'></br>
		</form>
	";

}


?>