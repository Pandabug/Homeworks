<?php
    session_start();

    include_once('config.php');
    
    $email = $_POST['email'];
    $password = $_POST['password'];

    if (!empty($email) && !empty($password)){
        $sql = mysqli_query($conn, "SELECT * FROM users WHERE email = '$email'");

        if (mysqli_num_rows($sql) > 0){
            $row = mysqli_fetch_assoc($sql);
            // $password = md5($password);

            if ($password == $row['password']){
                $_SESSION['id_user'] = $row['id_user'];
                header('location: ../index.php');
                echo "Succesfully login!";
            } else
                header("Location: ../login.php?error=Email or password incorrect!");
        } else 
            header("Location: ../login.php?error=This email not Exist!");
    } else 
        header("Location: ../login.php?error=All inputs are required");
?>