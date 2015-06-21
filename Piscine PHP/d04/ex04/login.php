<?php
include 'auth.php';
session_start();
if (!empty($_GET['login']) && !empty($_GET['passwd']))
{
	if (auth($_GET['login'], $_GET['passwd']))
		$_SESSION['loggued_on_user'] = $_GET['login'];
	else
		$_SESSION['loggued_on_user'] = "";
}
if (empty($_SESSION['loggued_on_user']))
	echo "ERROR\n";
else
	echo "OK\n";
?>
