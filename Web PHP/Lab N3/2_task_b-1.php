<?php
// Запрос
session_start();
if (!empty($_SESSION)) {
    echo 'Username: ',$_SESSION['name'], "<br>";
    echo 'Surname: ',$_SESSION['surname'], "<br>";
    echo 'Age: ',$_SESSION['age'], "<br>";
}
?>