<?php
function login_exist($id, $content)
{
	foreach ($content as $value)
	{
		if ($value['login'] == $id)
			return (true);
	}
	return (false);
}
$is_good = false;
if (!empty($_POST['submit']) && $_POST['submit'] == 'OK')
{
	if (!empty($_POST['login']) && !empty($_POST['passwd']))
	{
		if (file_exists('../private/passwd'))
		{
			$content_passwd = file_get_contents('../private/passwd');
			if (!empty($content_passwd))
			{
				$old = unserialize($content_passwd);
				if (!login_exist($_POST['login'], $old))
					$is_good = true;
			}
		}
		else
			$is_good = true;
	}
	if ($is_good)
	{
		$login = $_POST['login'];
		$passwd = hash('whirlpool', $_POST['passwd']);
		$table_user = array('login' => $login, 'passwd' => $passwd);
		$old[] = $table_user;
		$content = serialize($old) . "\n";
		if (!file_exists('../private'))
			mkdir('../private');
		file_put_contents('../private/passwd', $content);
		echo "OK\n";
	}
}
if ($is_good == false)
	echo "ERROR\n";
?>
