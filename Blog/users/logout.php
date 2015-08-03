<?php
session_start();
session_destroy();

printf("Successfully logged out");

/* Redirect to main page */
header("location:../index.php");

?>