<?php 
    session_start();
    
    if(isset($_SESSION['id_user']))
        header('location: index.php');
        
    include_once('header.php');
?>
<link rel="stylesheet" href="authentification.css">
<body>
    <form action="php/login.php" method="POST">
        <h2>Login</h2>
        <hr />

        <?php if (isset($_GET['error'])) { ?>
            <div class="error-msg" role="alert">
                <?=$_GET['error']?>
            </div>
        <?php } ?>

        <label>Email</label>
        <input type="text" name="email" placeholder="Email" />
        
        <label>Password</label>
        <input type="password" name="password" placeholder="Password" />

        <button type="submit">Login</button>

        <a href="signup.php">Don't have an account?</a>
    </form>
</body>
</html>