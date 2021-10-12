<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Profile</title>
    <link rel="stylesheet" href="php_style.css">
</head>
<body>
    <a href="../index.html" class='back-btn'>Back</a>
    
    <?php
        $username = $_POST["usernameLabel"];
        $password = $_POST["passwordLabel"];
        $image = '../assets/avatar.svg';
        $check = false;
        $text = 'Federico Caffe fifth grade student.';

        if (isset($_POST['reg_user'])){
            if ($username != '' && $password != ''){
                $data = $username.' '.$password."\n";
                
                if (is_writable('users.txt')){
                    $myFile = fopen('users.txt', 'a+') or die("Unable to open file!");

                    if (!$myFile){
                        echo '<h1>File not found</h1>';
                    } else {
                        fwrite($myFile, $data);
                        echo '<h3>User was correctly created</h3>';
                    }
                }
            }
        }

        if (isset($_POST['login'])){
            $myFile = file_get_contents('users.txt');
            $rows = explode("\n", $myFile);

            foreach ($rows as $row) {
                $user = explode(" ", $row);
                if ($user[0] == $username && $user[1] == $password){
                    $check = true;
                    break;
                }
            }

            if ($check){
                echo "<div class='profile-div'>";
                    echo "<img src='$image'><br /><br />";
                    echo "<div class='profile-info-div'>";
                        echo "USERNAME: <b>$username</b><br />";
                        echo "PASSWORD: <b>$password</b><br /><br />";
                        echo "<p>   $text</p><br />";
                    echo"</div>";
                echo"</div>";
            } else {
                echo"<center style='color: white;'>";
                    echo"<h1>Le credenziali da te inserite non sono corrette.</h1>";
                    echo"<h4>Si prega di tornare alla pagina principale.</h4>";
                echo"</center>";
            }
        }
    ?>
</body>
</html>