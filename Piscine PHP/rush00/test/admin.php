<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="utf-8">
	<title>Titre de la page</title>
	<link rel="stylesheet" href="style.css">
</head>
<body>
	<div id="administration">
	
<?php

include ("./config.php");

$mysqli = mysqli_connect($mysqli_host, $mysqli_user, $mysqli_pass, $mysqli_db);
	
$query = "SELECT * FROM `user` WHERE 1";
$result = mysqli_query($mysqli, $query);
echo "<table>\n";
echo "<tr><th>login</th><th>password</th><th>nom</th><th>prenom</th><th>adresse</th></tr>\n";
while ($row = mysqli_fetch_array($result)) {
	echo "<tr>\n";
	echo "<td>" . $row["login_user"] . "</td>\n";
	echo "<td>" . $row["mdp_user"] . "</td>\n";
	echo "<td>" . $row["nom_user"] . "</td>\n";
	echo "<td>" . $row["prenom_user"] . "</td>\n";
	echo "<td>" . $row["adresse_user"] . "</td>\n";
	echo "</tr>\n";
	}
	echo "</table><br />\n";

?>

	</div>
</body>
</html>
