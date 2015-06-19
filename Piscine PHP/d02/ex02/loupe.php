#!/usr/bin/php
<?php
	function zoom($matches)
	{
		$up = strtoupper($matches[1]);
		$matches[0] = preg_replace("/$matches[1]/", $up, $matches[0]);
		return ($matches[0]);
	}

	function	test($matches)
	{
		$str = preg_replace_callback("/title=\"(.+)\"/", "zoom", $matches[0]);
		$str = preg_replace_callback("/.*\>(([^<]+))/", "zoom", $str);
		return ($str);
	}

	if ($argv[1])
	{
        $fd = @fopen($argv[1], 'r');
        if ($fd === false)
        {
            echo "Error";
            return;
        }
        $page = @fread($fd, filesize($argv[1]));
		$page = preg_replace_callback("/<a.+(.+)<\/a>/isU", "test", $page);
		echo $page;
		@fclose($fd);
	}
?>
