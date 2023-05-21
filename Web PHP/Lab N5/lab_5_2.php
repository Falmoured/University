<?php
require_once __DIR__ . '/database.php';
function redirectToHome():void{
    header(header: 'Location: lab_5_1.php');
    exit();
}
if(false === isset($_POST["email"],$_POST["category"],$_POST["title"],$_POST["description"])){
    redirectToHome();
}

$email = $_POST['email'];
$category = $_POST['category'];
$title = $_POST['title'];
$description = $_POST['description'];

$database = new mysqli("localhost", "login", "password", "web");

if (mysqli_connect_errno()){
    printf('Can not connect to mysql server. Error code %s', mysqli_connect_error());
    exit;
}

$database->query("INSERT INTO ad (email, title, description, category) VALUES ('$email', '$title', '$description', '$category')");
$database->close();
redirectToHome();
?>