#!/usr/bin/php
<?php
while(1)
{
    echo "Entrez un nombre:";
    if ($buf = fgets(STDIN))
    {
        $buf = rtrim($buf);
        $isnum = 1;
        if (!is_numeric($buf))
        {
            $isnum = 0;
            $buf2 = $buf;
        }
        $buf = intval($buf);
        $limit = 9223372036854775807;
        if ($isnum == 0)
            echo "'".$buf2."' n'est pas un chiffre\n";
        else if ($buf == $limit || $buf == -9223372036854775808)
            echo "Error: le nombre et trop grand.\n";
        else if ($buf % 2 == 0)
            echo "Le chiffre ".$buf." est Pair\n";
        else
            echo "Le chiffre ".$buf." est Impair\n";
    }
    else
    {
        echo "\n";
        return;
    }
}
?>
