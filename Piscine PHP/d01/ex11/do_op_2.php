#!/usr/bin/php
<?php
	if (count($argv) != 2)
		echo "Incorrect Parameters\n";
	else
	{
		$num1 = $argv[1];
		$op = $argv[2];
		$num2 = $argv[3];
		$num1 = trim($num1);
		$op = trim($op);
		$num2 = trim($num2);
		if (!is_numeric($num1) || !is_numeric($num2))
			$param_error = 1;
		$res = ($op == "+" ? $num1 + $num2 : 0);
		$res = ($op == "-" ? $num1 - $num2 : 0);
		$res = ($op == "*" ? $num1 * $num2 : 0);
		$res = ($op == "/" ? $num1 / $num2 : 0);
		$res = ($op == "%" ? $num1 % $num2 : 0);
		echo $res."\n";
	}
?>
