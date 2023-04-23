<?php
require __DIR__ . '/vendor/autoload.php';
$guzzleClient = new \GuzzleHttp\Client(array( 'curl' => array( CURLOPT_SSL_VERIFYPEER => false, ), ));

$client = new Google_Client();
$client->setHttpClient($guzzleClient);
$client->setApplicationName('Google sheets in PHP');
$client->setScopes([Google_Service_Sheets::SPREADSHEETS]);
$client->setAccessType('offline');
$client->setAuthConfig(__DIR__ . '/lab4.json');

$service = new Google_Service_Sheets($client);

function redirectToHome():void{
    header(header: 'Location: lab_4_1.php');
exit();
}
if(false === isset($_POST["email"],$_POST["category"],$_POST["title"],$_POST["description"])){
    redirectToHome();
}

$email = $_POST['email'];
$category = $_POST['category'];
$title = $_POST['title'];
$description = $_POST['description'];
echo "\n",$email,"\t",$category,"\t",$title,"\t",$description;

$range_check = 'Лист1!F2';
$spreadsheetId = '1-oyx7IDgphPgc9iYa2_OBULYpIUDvp9eEuZ4ENVwRZw';


$probe = $service -> spreadsheets_values -> get($spreadsheetID, $range_check);
$options = [
    'valueInputOption' => 'RAW'
];
$numRows = 2+$probe[0][0];
$data_check = [
    [
        $probe[0][0]+1
    ]
];
$value_check = new Google_Service_Sheets_ValueRange([
    'values' => $data_check
]);

$service -> spreadsheets_values -> update($spreadsheetID, $range_check, $value_check, $options);
$range = 'Лист1!A'.$numRows.':D'.$numRows;

$data = [
    [
        $category,
        $title,
        $description,
        $email
    ]
];
$values = new Google_Service_Sheets_ValueRange([
    'values' => $data
]);
$service -> spreadsheets_values -> update($spreadsheetID, $range, $values, $options);

redirectToHome();
?>