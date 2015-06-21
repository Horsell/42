<?php
function auth($login, $passwd)
{
	if (!empty($login) && !empty($passwd))
	{
		$content = file_get_contents('../private/passwd');
		$passwd = hash('whirlpool', $passwd);
		if (!empty($content))
		{
			$content_unserial = unserialize($content);
			foreach ($content_unserial as $value)
			{
				if ($value['login'] == $login && $value['passwd'] == $passwd)
					return (true);
			}
		}
	}
	return (false);
}
?>
