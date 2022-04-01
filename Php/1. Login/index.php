<?php
    session_start();

    if(!isset($_SESSION['id_user']))
        header('location: login.php');

    include_once('header.php');
    include_once('php/config.php');
    $query = mysqli_query($conn, "SELECT * FROM users WHERE id_user = {$_SESSION['id_user']}");
    $user = mysqli_fetch_assoc($query);
    $query2 = mysqli_query($conn, "SELECT * FROM users LEFT JOIN hobby ON hobby.id_hobby = users.id_hobby_fk WHERE users.id_user = '{$_SESSION['id_user']}'");
    $user_hobby = mysqli_fetch_assoc($query2);

?>
<body>
    <header>
        <div class="user-info">
            <?php echo "{$user['nickname']}" ?>
        </div>

        <div class="logout-btn">
            <a href="php/logout.php?logout_id=<?php $_SESSION['id_user']?>">Logout</a>
        </div>
    </header>

    <div class="user-label">
        <div class="principal-info">
            <img src="https://www.sanitascare.it/wp-content/uploads/2017/04/default-user-image.jpg" alt="user">
    
            <div class="user-data">
                <p>
                    <?php echo $user['surname'] ?>
                </p>
                <p>
                    <?php echo $user['name'] ?>
                </p>
            </div>
        </div>

        <div class="user-principal-info">
            <b>User hobby:</b>
            <?php echo $user_hobby['hobby_name']?>
        </div>
        <div class="user-principal-info">
            <b>User genre:</b>
            <?php echo $user_hobby['genre']?>
        </div>
    </div>
</body>
</html>