<?php
    session_start();

    if(!isset($_SESSION['id_user']))
        header('location: login.php');

    include_once('header.php');
    include_once('php/config.php');
    $query2 = mysqli_query($conn, "SELECT * FROM users LEFT JOIN hobby ON hobby.id_hobby = users.id_hobby_fk WHERE users.id_user = '{$_SESSION['id_user']}'");
    $user_hobby = mysqli_fetch_assoc($query2);

?>
<body>
    <header>
        <div class="user-info">
            <?php echo "{$user_hobby['nickname']}" ?>
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
                    Cognome: <?php echo $user_hobby['surname'] ?>
                </p>
                <p>
                    Nome: <?php echo $user_hobby['name'] ?>
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

    <div class="posters">
        <?php
            $hobby_posters = mysqli_query($conn, "SELECT * FROM hobby_posters WHERE id_hobby_fk = '{$user_hobby['id_hobby']}'");
            while ($row = mysqli_fetch_assoc($hobby_posters)){
                echo "<div class='hobby_posters'>
                        {$row['hobby_poster_name']}
                        <img src='{$row['hobby_poster_image']}' alt='poster' />
                        {$row['hobby_poster_description']}
                    </div>";
            }
        ?>
    </div>

    <div class="all-users">
        <h2>All users list:</h2>
        <?php 
            $user_query = mysqli_query($conn, "SELECT * FROM users");

            if (mysqli_num_rows($user_query) > 0)
                while ($row = mysqli_fetch_assoc($user_query))
                    echo "<p>{$row['nickname']}</p>"; 
        ?>
    </div>
</body>
</html>