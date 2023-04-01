<?php
// A

$string = "accbakkbaqqlammmn"; // исходная строка
echo $string; 

echo "\n";

$regexp = '!a[a-z]{2}b!'; // регулярное выражение
$mathces = array();
$count = preg_match_all($regexp,$string,$matches);
var_dump($matches);

//Пункт B

$string1 = "a1b2c3";
$regexp = "![0-9]{1,}!";
function cube($s){
    
    return ($s[0]**3);
}
echo preg_replace_callback($regexp,'cube',$string1);
?>