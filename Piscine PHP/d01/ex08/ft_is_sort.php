<?php
	function ft_is_sort($tab)
	{
		$tmp = $tab;
		sort($tmp);
		return ($tmp === $tab ? 1 : 0);
	}
?>
