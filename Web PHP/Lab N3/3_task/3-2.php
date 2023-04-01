<?php

function goMain():void{
    header(header: 'Location: 3-1.php');
    exit();
}


if(false === isset($_POST['email'],$_POST['category'],$_POST['title'],$_POST['description'])){
    goMain();
}

$email = $_POST['email'];
$category = $_POST['category'];
$title = $_POST['title'];
$description = $_POST['description'];


$filePath = "categories/{$category}/{$title}.txt";
file_put_contents($filePath, $description);


if(false === file_put_contents($filePath, $description)){
    throw new Exception(message:"Error!");
}
chmod($filePath, 0777);

goMain();
?>