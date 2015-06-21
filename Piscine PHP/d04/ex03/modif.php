<?php
function login_exist_and_passwd($id, $mdp, $content)
{
	foreach ($content as $value)
	{
		if ($value['login'] == $id && $value['passwd'] == $mdp)
			return (true);
	}
	return (false);
}
function modif_passwd($id, $oldmdp, $newmdp, $content)
{
	foreach ($content as $key => $value)
	{
		if ($value['login'] == $id && $value['passwd'] == $oldmdp)
			$content[$key]['passwd'] = $newmdp;
	}
	return ($content);
}
$is_good = false;
if (!empty($_POST['submit']) && $_POST['submit']== 'OK')
{
	if (!empty($_POST['login']) && !empty($_POST['oldpw']) && !empty($_POST['newpw']))
	{
		if (is_readable('../private/passwd'))
		{
			$content_passwd = file_get_contents('../private/passwd');
			if (!empty($content_passwd))
			{
				$old = unserialize($content_passwd);
				if (login_exist_and_passwd($_POST['login'], hash('whirlpool', $_POST['oldpw']), $old))
					$is_good = true;
			}
		}
	}
	if ($is_good)
	{
		$login = $_POST['login'];
		$oldpw = hash('whirlpool', $_POST['oldpw']);
		$newpw = hash('whirlpool', $_POST['newpw']);
		$old = modif_passwd($login, $oldpw, $newpw, $old);
		$content = serialize($old) . "\n";
		file_put_contents('../private/passwd', $content);
		echo "OK\n";
	}
}
if ($is_good == false)
	echo "ERROR\n";
?>
