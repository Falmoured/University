<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>BOARD ANNOUNCEMENT</title>
</head>
<body>

    <form action="3-2.php" method="POST">
        <label for="email">Email</label>
            <input type="email" name="email"><br>
			
        <label for="category">Category</label>
        <select name="category" required>
		
                <?php
                $categories = scandir("categories");
                foreach ($categories as $category) {
                    if ($category != "." && $category != "..") {
                    echo "<option value=\"$category\">$category</option>";
                    }
                }
                ?>
				
        </select><br>
        <label for="title">HEADLINE</label>
            <input type="text" name="title" required><br>
			
        <label for="description">TEXT</label>
            <textarea name="description" id="" cols="30" rows="5" required></textarea><br>
        <input type="submit" value="Сохранить">
</form>

    <table> 
        <thead>
           <th>CATEGORY</th> 
           <th>HEADLINE</th> 
           <th>DISCRIPTION</th> 
        </thead>
        <?php
        $categories = scandir("categories");
        foreach ($categories as $category) {
            if ($category != "." && $category != "..") {
                $announcements = scandir("categories/$category");
                foreach ($announcements as $announcement) {
                    if ($announcement != "." && $announcement != "..") {
                        $title = pathinfo($announcement, PATHINFO_FILENAME);                                      
                        $description = file_get_contents("categories/$category/$announcement");
                        echo "<tr><td>$category</td><td>$title</td><td>$description</td></tr>";
                    }
                }
            }
        }
        ?>
    </table>
</body>
</html>