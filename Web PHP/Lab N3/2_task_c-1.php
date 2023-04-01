<?php
// C (ввод)
session_start();
if (!empty($_GET)) {
    $_SESSION['array'] = $_GET;
}
?>

<form action="" method="GET">
    <label for = "name">Your name</label>
        <input name="name" required><br>
		
    <label for = "surname">Your surname</label>
	    <input name="surname" required><br>
		
    <label for = "age">Your Age</label>
        <input name="age" required><br>
		
    <label for = "city">Your Email</label>
        <input name="email" required><br>
		
    <label for = "phone">Your Addreas</label>
        <input name="addreas" required><br>
	<input type="submit"><br>
</form>