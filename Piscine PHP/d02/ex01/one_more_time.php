#!/usr/bin/php
<?php
	if ($argv[1])
	{
		$argv[1] = trim($argv[1]);
		date_default_timezone_set("Europe/Paris");
		$day = array("[Ll]undi", "[Mm]ardi", "[Mm]ercredi", "[Jj]eudi", "[Vv]endredi", "[Ss]amedi", "[Dd]imanche");
		$big_month = array("01" => "[Jj]anvier", "03" => "[Mm]ars", "05" => "[Mm]ai", "07" => "[Jj]uillet", "08" => "[Aa]oi[uû]t", "10" => "[Oo]ctobre", "12" => "[Dd][ée]cembre");
		$small_month = array("04" => "[Aa]vril", "06" => "[Jj]uin", "09" => "[Ss]eptembre", "11" => "[Nn]ovembre"); 
		$big_month = implode("|", array_values($big_month));
		$small_month = implode("|", array_values($small_month));
		$day = implode("|", array_values($day));
		if (preg_match("/($day) (((([0-2]?[0-9])|(3[0-1])) ($big_month))|((([0-2]?[0-9])|30) ($small_month))|([0-2]?[0-9] [Ff][ée]vrier)) [0-9]{4} ((([0-1][0-9])|(2[0-3])):[0-5][0-9]:[0-5][0-9])/", $argv[1]))
			echo time()."\n";
		else
			echo "Wrong format\n";
	}
?>
