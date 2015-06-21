<?php
	session_start();
	if (!empty($_GET['submit']) && $_GET['submit'] == "OK")
	{
		if (!empty($_GET['login']))
			$_SESSION['login'] = $_GET['login'];
		if (!empty($_GET['passwd']))
			$_SESSION['passwd'] = $_GET['passwd'];
	}
?>

<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Ex01</title>
</head>
<body>
	<form action="index.php" method="GET">
		Identifiant: <input name="login" value="<?php if (!empty($_SESSION['login'])) echo $_SESSION['login']; ?>" placeholder="Login" /><br />
		Mot de passe: <input name="passwd" value="<?php if (!empty($_SESSION['passwd'])) echo $_SESSION['passwd']; ?>" type="password" placeholder="Mot de passe" />
		<input type="submit" name="submit" value="OK" />
	</form>
</body>
</html>
