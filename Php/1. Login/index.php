<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $username = $_POST["usernameLabel"];
        $password = $_POST["passwordLabel"];

        echo"<center><h1>Ecco</h1></br />";
        echo"USERNAME: <b>$username</b><br />";
        echo"PASSWORD: <b>$password</b><br />";
        echo"<center>";
    ?>
</body>
</html>