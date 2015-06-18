#!/usr/bin/php
<?php
	if ($argv[1])
	{
		$argv[1] = trim($argv[1]);
		date_default_timezone_set("Europe/Paris");
		$day = array("[Ll]undi", "[Mm]ardi", "[Mm]ercredi", "[Jj]eudi", "[Vv]endredi", "[Ss]amedi", "[Dd]imanche");
		$month = array("01" => "[Jj]anvier", "02" => "[Ff][ée]vrier", "03" => "[Mm]ars", "04" => "[Aa]vril", "05" => "[Mm]ai", "06" => "[Jj]uin", "07" => "[Jj]uillet", "08" => "[Aa]oi[uû]t", "09" => "[Ss]eptembre", "10" => "[Oo]ctobre", "11" => "[Nn]ovembre", "12" => "[Dd][ée]cembre");
		$day = implode("|", array_values($day));
		$month = implode("|", array_values($month));
		if (preg_match("/($day) (([0-2]?[0-9])|(3[0-1])) ($month) ((([0-1][0-9])|(2[0-3])):[0-5][0-9]:[0-5][0-9])/", $argv[1]))
		{
			echo $argv[1]."\n";
		}
		else
			echo "Wrong format\n";
	}
?>
