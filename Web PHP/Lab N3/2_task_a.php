<form action="" method="GET">

<label for = "textarea">Write your text</label>
    <textarea rows = "2" name = "textarea"></textarea>
    <input type = "submit" value = "Calculate">
</form>

<?php
// A
if (!empty($_GET['textarea'])) {
    $text = $_GET['textarea'];
    echo "Word count: ", str_word_count($text, $format = 0), "<br>";
    echo "Symbol count: ", strlen($text);
}
?>