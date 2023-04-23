!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Доска объявлений</title>
</head>
<body>
    <form action="lab_4_2.php" method="POST">
        <label for="email">Email</label>
            <input type="email" name="email"><br>
        <label for="category">Категории</label>
        <select name="category" required>
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
                $range = 'E2:E4';

                $spreadsheetId = '1-oyx7IDgphPgc9iYa2_OBULYpIUDvp9eEuZ4ENVwRZw';
                $categories = $service -> spreadsheets_values -> get($spreadsheetID, $range);

                foreach ($categories as $category) {
                     if ($category != "." && $category != "..") {
                           echo "<option value=\"$category[0]\">$category[0]</option>";
                         }
                     }
                ?>
        </select><br>
        <label for="title">Заголовок объявления</label>
            <input type="text" name="title" required><br>
        <label for="description">Текст объявления</label>
            <textarea name="description" id="" cols="30" rows="5" required></textarea><br>
        <input type="submit" value="Сохранить">
</form>
    <table> 
        <thead>
           <th>Категория</th> 
           <th>Заголовок</th> 
           <th>Описание</th> 
        </thead>
        <?php
         $rangeGet = 'A2:D10';
         $results = $service -> spreadsheets_values -> get($spreadsheetID, $rangeGet);
         foreach ($results as $result) {
             if(!empty($result))
             {
                 echo "<tr><td>$result[0]</td><td>$result[1]</td><td>$result[2]</td><td>$result[3]</td></tr>";
             }
             else
             {
                 break;
             }
         }
        ?>
    </table>
</body>
</html>