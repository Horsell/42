<?php
session_start();
if ($_SESSION)
{
	foreach($_SESSION as $k => $v)
		$_SESSION[$k] = NULL;
}
?>
