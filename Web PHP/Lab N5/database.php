<?php
function Database()
{
    static $database = null;

    if ($database === null)
    {
        $dbHost = option('localhost');
        $dbUser = option('falmoured');
        $dbPassword = option('lenagolovach');
        $dbName = option('w3b');
        $database = mysqli_init();

        $connected = mysqli_real_connect($database, $dbHost, $dbUser, $dbPassword, $dbName);

        if (!$connected)
        {
            $error = mysqli_connect_errno() . ': ' . mysqli_connect_error();
            throw new Exception($error);
        }

        $encodingResult = mysqli_set_charset($database, 'utf8');
        if (!$encodingResult)
        {
            throw new Exception(mysqli_error($database));
        }
    }
    return $database;
}