#!/usr/bin/php
<?php
	if ($argv[1])
	{
		$str = preg_replace("/[ \t]+/", " ", $argv[1]);
		$str = trim($str);
		echo $str."\n";
	}
?>
