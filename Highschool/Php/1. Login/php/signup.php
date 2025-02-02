<?php
    session_start();

    include_once('config.php');

    $name = $_POST['name'];
    $surname = $_POST['surname'];
    $nickname = $_POST['nickname'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    $overmin = $_POST['overmin'];
    $genre = $_POST['genre'];
    $hobby = $_POST['hobby'];

    if (!empty($name) && !empty($surname) && !empty($email) && !empty($password) && !empty($genre) && $hobby != ''){
        if (filter_var($email, FILTER_VALIDATE_EMAIL)){
            $query_email_controll = mysqli_query($conn, "SELECT * FROM users WHERE email = '$email'");

            if (mysqli_num_rows($query_email_controll) > 0)
                header("Location: ../signup.php?error=Email: '{$email}' alredy exist!");
            else {
                // $password = md5($password);
                $hobby_query = mysqli_query($conn, "SELECT * FROM hobby WHERE hobby_name = '{$hobby}'");
                $hobby_row = mysqli_fetch_assoc($hobby_query);
                $query = mysqli_query($conn, "INSERT INTO users (name, surname, nickname, email, password, overmin, genre, id_hobby_fk) VALUES ('{$name}', '{$surname}', '{$nickname}', '{$email}', '{$password}', '{$overmin}', '{$genre}', '{$hobby_row['id_hobby']}')");

                if ($query){
                    $query2 = mysqli_query($conn, "SELECT * FROM users WHERE email = '$email' AND password = '$password'");

                    if (mysqli_num_rows($query2) > 0){
                        $user = mysqli_fetch_assoc($query2);
                        $_SESSION['id_user'] = $user['id_user'];
                        header('location: ../index.php');
                        echo "Succesfully signup!";
                    } else 
                        header("Location: ../signup.php?error=Email or password incorrect!");
                } else
                    header("Location: ../signup.php?error=Somthing went wrong. Please try again!");
            }
        } else 
            header("Location: ../signup.php?error=$email - invalid email");
    } else 
        header("Location: ../signup.php?error=All inputs required!");
?>