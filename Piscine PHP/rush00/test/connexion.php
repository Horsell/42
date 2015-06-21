<html lang="en">
<head>
	<meta charset="utf-8">
	<title>WildCorp</title>
	<link href="my.css" rel="stylesheet">
<body>
	<div class="row">
		<hr>
		<div class="col-4 head">
			<h2>WildCorp</h2>
		</div>
		<hr>
	</div><!--/row-->


	<div class="row">
		<hr>
		<div class="col-1">
			<form action="#" method="post"><br />
				*login : <input type="text" name="login_user" required="required"><br />
				*Password : <input type="password" name="mdp_user" required="required"><br/>
				Nom : <input type="text" name="nom_user"><br />
				Prenom : <input type="text" name="prenom_user"><br />
				Adresse : <input type="text" name="adresse_user"><br />
				<input type="submit" name="clicked" value="Sign up" class="button">
			</form>
		</div>
	</div>
	
</body>
</html>

<?php
include ('config.php');

$mysqli = mysqli_connect($mysqli_host, $mysqli_user, $mysqli_pass, $mysqli_db);

echo "Started";
if (isset($_POST['clicked']))
{
	echo "Click";
    if ($_POST['login_user'] != "" && $_POST['mdp_user'] != "")
    {
        $user = $_POST['login_user'];
		echo $user;
        $passwd = $_POST['mdp_user'];
		echo $passwd;
        $name = $_POST['nom_user'];
		echo $name;
        //$prenom = $_POST('prenom_user');
		//echo $prenom;
        //$adresse = $_POST('adresse_user');
	//	echo $adresse;
        $req = "INSERT INTO `project`.`user`(`login_user`, `mdp_user`, `nom_user`) VALUES ('$user', '$passwd', '$name')";
		echo "lol";
        mysqli_query($mysqli, $req);
        echo "Bienvenue Mr $name !";
        $_SESSION['Logged'] = TRUE;
        $_SESSION['nom_user'] = $name;
        $_SESSION['login_user'] = $user;
        header('Refresh: 2');
    }
    else
    {
        echo "Please fill all the fields.<br />";
    }
}
mysqli_close($mysqli);
?>
