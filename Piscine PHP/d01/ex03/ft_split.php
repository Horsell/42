<?php
	function ft_split($s)
	{
		$s = trim($s);
		$split = explode(" ", $s);
		asort($split);
		$split = array_filter($split);
		$split = array_values($split);
		return($split);
	}
?>
