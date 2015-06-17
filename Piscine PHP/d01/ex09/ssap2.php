#!/usr/bin/php
<?php
	$tab = implode(" ", $argv);
	$tab = explode(" ", $tab);
	$tab = array_filter($tab, 'strlen');
	unset($tab[0]);
	foreach ($tab as $str)
	{
		if (ctype_alpha($str))
			$alpha[] = $str;
		else if (is_numeric($str))
			$num[] = $str;
		else
			$other[] = $str;
	}
	($alpha ? natcasesort($alpha) : 1);
	($num ? sort($num) : 1);
	($other ? natcasesort($other) : 1);
	$str = array_merge((array)$alpha, (array)$num, (array)$other);
	$str = array_values($str);
	foreach($str as $s)
		echo $s."\n";
?>
