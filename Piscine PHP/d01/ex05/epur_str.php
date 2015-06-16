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
	if ($argc != 2)
		return;
	$tab = ft_split($argv[1]);
	$n = count($tab);
	for ($i = 0; $i < $n; $i++)
	{
		echo $tab[$i];
		if ($i < $n - 1)
			echo " ";
	}
	echo "\n";
?>
