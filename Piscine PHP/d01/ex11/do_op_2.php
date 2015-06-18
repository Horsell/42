#!/usr/bin/php
<?php
	function ft_split($s)
	{
		$s = trim($s);
		$split = explode(" ", $s);
		$split = array_filter($split);
		$split = array_values($split);
		return($split);
	}
	if (count($argv) != 2)
		echo "Incorrect Parameters\n";
	else
	{
		$s = ft_split($argv[1]);
		if (!is_numeric($s[0]) || !is_numeric($s[2]))
			$res = "Syntax Error";
		if ($s[1] == "+")
			$res = $s[0] + $s[2];
		else if ($s[1] == "-")
			$res = $s[0] - $s[2];
		else if ($s[1] == "*")
			$res = $s[0] * $s[2];
		else if ($s[1] == "/")
			$res = $s[0] / $s[2];
		else if ($s[1] == "%")
			$res = $s[0] % $s[2];
		else
			$res = "Syntax Error";
		echo $res."\n";
	}
?>
