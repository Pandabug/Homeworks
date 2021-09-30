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
        $storage = array(
            array(
                'ivan', 
                '123456'
            ),
            array(
                'admin', 
                'admin'
            ),
        );

        $username = $_POST["usernameLabel"];
        $password = $_POST["passwordLabel"];
        $image = '../assets/avatar.svg';
        $check = false;
        $text = 'Federico Caffe fifth grade student.';

        if (isset($_POST['reg_user'])){
            // if ($username != '' && $password != '')
            //     $storage = array_merge($storage, array($username, $password));
            
            print_r($storage);
            // var_dump($storage);
        }

        if (isset($_POST['login'])){
            for ($i=0; $i<count($storage); $i++)
                if (in_array($username, $storage[$i]) && in_array($password, $storage[$i])){
                    $check = true;
                    break;
                }
                
            if ($check){
                echo "<div class='profile-div'>";
                    echo '<img src=\''.$image.'\'><br /><br />';
                    echo "<div class='profile-info-div'>";
                        echo "USERNAME: <b>$username</b><br />";
                        echo "PASSWORD: <b>$password</b><br /><br />";
                        echo "<p>   $text</p><br />";
                        echo"</div>";
                        // echo "<b>Input new password:</b>";
                        // echo "<input value='new password' id='new_password' /><br /><br />";
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