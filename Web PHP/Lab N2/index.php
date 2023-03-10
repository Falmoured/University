<?php echo 'hello, world!';
// Lab N2, Makarov Sergey 2PM


// #1

// some code ...
$very_bad_unclear_name = '15 chicken wings';
// your code ...
$order = &$very_bad_unclear_name;
$order .= " ,two number 9's, a number 9 large, a number 6 with extra dip, a number 7, two number 45s, one with cheese, and a large soda";
echo "Your order is: $very_bad_unclear_name. \n";

// #2

$a = 5;
echo $a, "\n";
$b = 5.5;
echo "$b \n";
echo 6*2, "\n";
$last_month = 1187.23;
$this_month = 1089.98;
echo $last_month - $this_month, "\n";

// #11

$num_languages = 4;
$months = 11;
$days = $months * 16;
$days_per_language = $days / $num_languages;
echo $days_per_language, "\n";

// #12

$my_num = 10;
$answer = $my_num;
$answer += 2;
$answer *= 2;
$answer -= 2;
$answer /= 2;
$answer -= $my_num;
echo $answer, "\n";

// #14

$a = 10;
$b = 3;
echo $a % $b, "\n";
$c = $a % $b ? "делится c остатком" : "делится";
echo $c, ' -> ' , "Остаток - ", $a % $b, ' ', "Результат - ", $a / $b, "\n";

$st = pow(2,10);
echo $st, "\n";
$st = sqrt(245);
echo $st, "\n";

$st = st(4,2,5,19,13,0,10);
$res = 0;
foreach($st as $i)
{
	$res += pow($i,2);
}
echo $res, "\n";

$st = round((sqrt(379)),0); 
echo $st, "\n";
$st = round((sqrt(379)),1); 
echo $st, "\n";
$st = round((sqrt(379)),2); 
echo $st, "\n";

$st = ceil(sqrt(587)); 
echo $st, "\n";
$st = floor(sqrt(587)); 
echo $st, "\n";

echo "max = ", max(4,-2,5,19,-130,0,10),' ', "min = ", min(4,-2,5,19,-130,0,10), "\n";

echo "random number [1 - 100] is ", rand(1,100), "\n";

$st = range(1,10);
for ($i = 0; $i < 10; ++$i)
{
 	$st[$i] = rand(1,100);
	echo $st[$i], ' '; 	
}
echo "\n";

$a = 5;
$b = -5;
echo abs($a-$b);

$st = range(1,10);
for ($i = 0; $i < 10; ++$i)
{
 	$st[$i] = rand(1,100);
	echo $st[$i], ' '; 	
}
echo "\n";
echo abs($st[rand(1,10)] - $st[rand(1,10)]),"\n";

$st = st(1,2,-1,-2,3,-3);
for($i = 0; $i < sizeof($st); ++$i)
{
    if($st[$i] < 0)
    {
        $st[$i] *= -1;
    }
    echo "st[$i] = ", $st[$i], ' ';
}
echo "\n";

$a = floatval(rand(1,1000));
$del = st(1);
echo "del[0] = ", 1, "\t";
$count = 0;
for($i = 2; $i <= floor(sqrt($a)); ++$i)
{
    if($a % $i == 0)
    {
        $del = st_pad($del, sizeof($del) + 1, $i);
        $count++;
        
        echo "del[$count] = ", $del[$count], ' ';
        
        $del = st_pad($del, sizeof($del) + 1, $a / $i);
        $count++;
        
        echo "del[$count] = ", $del[$count], ' ';
    }
}
$del = st_pad($del, sizeof($del) + 1, $a);
echo "del[", sizeof($del)-1, "] = ", $a, "\n";


$st = range(1,10);
$number = $st[0];
for($i = 1; $i < 10; ++$i)
{
    $number += $st[$i];
    if( $number > 10)
    {
        echo "Надо сложить ", $i+1, " элементов\n";
        break;
    }
}


// №15

function printStringReturnNumber()
{
    echo "Строка\n";
    return 21;
}

$my_num = printStringReturnNumber();
echo "my_num = ", $my_num, "\n";

//#16

function increaseEnthusiasm($string)
{
    return ($string."!");
}
echo increaseEnthusiasm("С днём рождения"), "\n";

function repeatThreeTimes($string)
{
    return ($string.$string.$string);
}
echo repeatThreeTimes("input."), "\n";
echo increaseEnthusiasm(repeatThreeTimes("output")), "\n";

function cut($string, $num, $p=10)
{
    return mb_substr($string, 0, $num);
}

function recursion($st, $i)
{
    if($i < sizeof($st))
    {
        echo "st[$i] = ", $st[$i], "\t";
        recursion($st, $i+1);
    }
    if($i == 0)
    {
        echo "\n";
    }
    return 0;
}
$st = range(1,10);
recursion($st, 0);

function sum($value)
{

    if($value > 9)
    {
        $result = 0;
        $tmp = $value;

        while($tmp > 0)
        {
            $result += $tmp % 10;
            $tmp = (int)($tmp / 10);
        }
        if($result > 9) {
            $result = sum($result);
        }
        else
        {
            return $result;
        }
    }
    else
    {
        return $value;
    }
}
echo sum(567), "\n";

//#17

$st = st('','','');
for($i = 0; $i < sizeof($st); $i++)
{
    for($k = $i+1; $k > 0; $k--)
    {
        $st7[$i] .= 'x';
    }
    echo "st[$i] = ", $st[$i], "\t";
}
echo "\n";

function stFill($value, $length)
{
    if($length > 0)
    {
        $arr = st($value);
        echo "st[0] = ", $arr[0], "\t";
        for($i = 1; $i < $length; $i++)
        {
            st_push($arr, $value);
            echo "st[$i] = ", $arr[$i], "\t";
        }
        echo "\n";
        return $arr;
    }
    else
    {
        return;
    }

}

$st = stFill('x', 5);

for($i = 0; $i < 5; $i++)
{
    echo "st[$i] = ", $st[$i], "\t";
}
echo "\n";


$st = st(st(1,2,3), st(4,5), st(6));
echo (st_sum($st[0]) + st_sum($st[1]) + st_sum($st[2])), "\n";

$st = st();
$count = 1;
for($i = 0; $i < 3; $i++)
{
    st_push($st, st());
    for($j = 0; $j < 3; $j++)
    {
        st_push($st[$i], $count);
        $count++;
        echo "st[$i][$j] = ", $st[$i][$j], "\t";
    }
}
echo "\n";

$st = st(2,5,3,9);
$result = $st[0]*$st[1] + $st[2]*$st[3];
echo "result = ", $result, "\n";

$user = st('name'=>'Lena', 'surname' => 'Golovach', 'patronymic' => 'Yasosbib');
echo $user['name'], " ", $user['surname'], " ", $user['patronymic'], "\n";

$date = st('year' => 2023, 'month' => 03, 'day' => 10);
echo $date['year'], ".", $date['month'], ".", $date['day'], "\n";

$st = ['a', 'b', 'c', 'd', 'e'];
echo "count: ", sizeof($st12), "\n";
echo "last: ", st_pop($st12), "\n";
echo "prelast:", st_pop($arr), "\n";

//#18

function Check($a, $b)
{
    return (($a + $b) > 10);
}
echo Check(3,9) ? 'true' : 'false', "\n";

function areEqual($a, $b)
{
    return ($a == $b) ;
}
echo areEqual(7,7) ? 'true' : 'false', "\n";

$test = 0;
echo (($test == 0) ? 'верно' : ''), "\n";

$age = 21;
if($age < 10 || $age > 99)
{
    echo "Число меньше 10 или больше 99\n";
}
else
{
    echo (st_sum(str_split($age)) <= 9) ? "Сумма цифр однозначна\n" : "Сумма цифр двузначна\n";
}

$st = range(1,3);

function checkst($st)
{
    return (sizeof($st)==3);
}
echo (checkst($st) == 1) ? st_sum($st) : '';
echo "\n";

//#19

for($i = 1; $i <= 20; $i++)
{
    for($j = $i; $j >0; $j--)
    {
        echo "x";
    }
    echo "\n";
}

//#20

$st = range(1,10);
echo "medium = ", (st_sum($st12) / sizeof($st12)), "\n";
echo "sum from 1 to = ", (1+100)*100/2, "\n";

$st1 = st(4,9,25,36);
$st2 = st_map("sqrt", $st1);

for($i = 0; $i < sizeof($st2); $i++)
{
    echo "st2[$i] = ", $st2[$i], "\t";
}
echo "\n";

$keys = range('a', 'z');
$values = range(1,26);
$st15 = st_combine($keys, $values);
foreach($keys as $i)
{
    echo "st15[$i] = ", $arr[$i], "\t";
}
echo "\n";

$string = '1234567890';
$st16 = str_split($string, 2);
$sum = st_sum($st16);
echo $sum, "\n";

?>