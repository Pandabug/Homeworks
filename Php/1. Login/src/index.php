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

            for ($i=0; $i<2; $i++)
                if (in_array($username, $storage[$i]) && in_array($password, $storage[$i])){
                    $check = true;
                    break;
                }
                
            if ($check){
                echo "<div class='profile-div'>";
                    echo '<img src=\''.$image.'\'><br /><br />';
                    echo "USERNAME: <b>$username</b><br />";
                    echo "PASSWORD: <b>$password</b><br /><br />";
                    // echo "<b>Input new password:</b>";
                    // echo "<input value='new password' id='new_password' /><br /><br />";
                    echo "<p>Federico Caffe fifth grade student.</p><br />";
                echo"</div>";
            } else {
                echo"<center>";
                    echo"Nope";
                echo"</center>";
            }
        ?>
    </body>
</html>