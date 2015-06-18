#!/usr/bin/php
<?php
	if (count($argv) != 4)
		echo "Incorrect Parameters\n";
	else
	{
		$num1 = $argv[1];
		$op = $argv[2];
		$num2 = $argv[3];
		$num1 = trim($num1);
		$op = trim($op);
		$num2 = trim($num2);
		if ($op == "+")
			$res = $num1 + $num2;
		else if ($op == "-")
			$res = $num1 - $num2;
		else if ($op == "*")
			$res = $num1 * $num2;
		else if ($op == "/")
			$res = $num1 / $num2;
		else if ($op == "%")
			$res = $num1 % $num2;
		echo $res."\n";
	}
?>
