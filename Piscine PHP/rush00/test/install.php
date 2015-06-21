<?php
include('config.php');

$dbname = "blabla";
$con = mysqli_connect('localhost', 'root', 'baboon');
if (mysqli_connect_errno())
  echo "Failed to connect to MySQL: " . mysqli_connect_error() . "<br />\n";
$sql = "CREATE DATABASE $dbname";
if (mysqli_query($con, $sql))
  echo "Database $dbname created successfully<br />\n";
else
  echo "Error creating database: " . mysqli_error($con)."<br />\n";


// Lecture du fichier .sql dans la variable $sql
$fp = fopen("$file_sql", "r");
$sql2 = "";
while (!feof($fp)) {
  $sql2 .= fgets($fp, 4096);
}
fclose($fp);


// Connexion au serveur

$con = mysqli_connect('localhost', 'root', 'baboon', 'blabla');
if (mysqli_connect_errno())
  echo "Failed to connect to MySQL: " . mysqli_connect_error()."<br />\n";


// Ajout des tables et du contenu ligne par linge
$tab = explode(';', $sql2);
$c = count($tab);
foreach ($tab as $key => $value) {
  if ($key != $c - 1)
  {
    if (mysqli_query($con, $value." ;"))
      echo "cr&eacute;ation des table et contenus OK<br />\n";
    else
      echo "Error creating table: " . mysqli_error($con) . "<br />\n";
  }
}

/*
$mysqli = mysqli_connect('localhost', 'root', 'baboon', 'blabla');
mysqli_query($mysqli, "CREATE DATABASE $mysqli_db DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci");
mysqli_close($mysqli);


$mysqli = mysqli_connect('localhost', 'root', 'baboon', 'blabla');
$req = "CREATE TABLE IF NOT EXISTS `user` (
  `id_user` int(255) NOT NULL AUTO_INCREMENT,
  `nom_user` int(255) NOT NULL,
  `prenom_user` int(255) NOT NULL,
  `adresse_user` int(255) NOT NULL,
  `login_user` int(255) NOT NULL,
  `mdp_user` int(255) NOT NULL,
  `id_commande` int(255) NOT NULL,
  PRIMARY KEY (`id_user`),
  UNIQUE KEY `id_commande` (`id_commande`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;";

mysqli_query($mysqli, $req);
echo "lol";

$req = "CREATE TABLE IF NOT EXISTS `commande` (
  `id_commande` int(255) NOT NULL AUTO_INCREMENT,
  `total_commande` int(255) NOT NULL,
  `id_article` int(255) NOT NULL,
  PRIMARY KEY (`id_commande`),
  UNIQUE KEY `id_article` (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;"

mysqli_query($mysqli, $req);

$req = "CREATE TABLE IF NOT EXISTS `categorie` (
  `id_categorie` int(255) NOT NULL AUTO_INCREMENT,
  `libelle_categorie` int(255) NOT NULL,
  PRIMARY KEY (`id_categorie`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;"

mysqli_query($mysqli, $req);

$req = "CREATE TABLE IF NOT EXISTS `article` (
  `id_article` int(255) NOT NULL AUTO_INCREMENT,
  `nom_article` int(255) NOT NULL,
  `race_article` int(255) NOT NULL,
  `prix_article` int(255) NOT NULL,
  PRIMARY KEY (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;"

mysqli_query($mysqli, $req);

echo "lol";
/*
$req = "CREATE TABLE IF NOT EXISTS `appartenir` (
  `id_app` int(255) NOT NULL AUTO_INCREMENT,
  `id_article` int(255) NOT NULL,
  `id_categorie` int(255) NOT NULL,
  PRIMARY KEY (`id_app`),
  UNIQUE KEY `id_article` (`id_article`,`id_categorie`),
  KEY `id_categorie` (`id_categorie`),
  KEY `id_article_2` (`id_article`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;"

mysqli_query($mysqli, $req);

$req = "ALTER TABLE `appartenir`
  ADD CONSTRAINT `app_categorie` FOREIGN KEY (`id_categorie`) REFERENCES `categorie` (`id_categorie`) ON DELETE CASCADE,
  ADD CONSTRAINT `app_article` FOREIGN KEY (`id_article`) REFERENCES `article` (`id_article`) ON DELETE CASCADE;
"
mysqli_query($mysqli, $req);

$req = "ALTER TABLE `commande`
  ADD CONSTRAINT `commande_article` FOREIGN KEY (`id_commande`) REFERENCES `article` (`id_article`) ON DELETE CASCADE;";

mysqli_query($mysqli, $req);

$req = "ALTER TABLE `user`
  ADD CONSTRAINT `user_commande` FOREIGN KEY (`id_user`) REFERENCES `commande` (`id_commande`) ON DELETE CASCADE;";

echo "Install [OK]";

mysqli_close($mysqli);
*/?>
