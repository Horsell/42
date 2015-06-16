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
	$str = implode(" ", $argv);
	$tab = ft_split($str);
	unset($tab[0]);
	$n = count($tab);
	for ($i = 2; $i <= $n; $i++)
	{
		echo $tab[$i]." ";
	}
	echo $tab[1];
	echo "\n";
?>
