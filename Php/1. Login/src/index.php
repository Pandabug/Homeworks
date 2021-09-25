<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="php_style.css">
</head>
<body>
    <a href="../index.html" class='back-btn'>Back</a>
    
    <?php 
        $user = 'ivan';
        $password = '123456';

        $username = $_POST["usernameLabel"];
        $password = $_POST["passwordLabel"];
        $image = '../assets/avatar.svg';

        if ($username == $user && $password == $password){
            echo "<div class='profile-div'>";
                echo '<img src=\''.$image.'\'><br /><br />';
                echo "USERNAME: <b>$username</b><br />";
                echo "PASSWORD: <b>$password</b><br /><br />";
                echo "<p>Federico Caffe fifth grade student.</p><br />";
            echo"</div>";
        }
        else {
            echo"<center>";
            echo"Nope";
            echo"</center>";
        }
    ?>
</body>
</html>