<?php 
    session_start();

    if (isset($_SESSION['id_user']))
        header('location: index.php');

    include_once('header.php'); 
?>

<link rel="stylesheet" href="authentification.css">
<body>
    <form action="php/signup.php" method="POST">
        <h2>Signup</h2>
        <hr />
        
        <?php if (isset($_GET['error'])) { ?>
            <div class="error-msg" role="alert">
                <?=$_GET['error']?>
            </div>
        <?php } ?>

        <label>Name:</label>
        <input type="text" name="name" placeholder="Name" />

        <label>Surname:</label>
        <input type="text" name="surname" placeholder="Surname" />
        
        <label>Nickname:</label>
        <input type="text" name="nickname" placeholder="Nickname" />
        
        <label>Email:</label>
        <input type="text" name="email" placeholder="Email" />
        
        <label>Password:</label>
        <input type="password" name="password" placeholder="Password" />
        

        <label>Over 18?</label>
        <input type="checkbox" name="overmin" />
        
        <div class="general-info">
            <div class="genre">
                <label>Genre:</label>
                <div class="radio-btn">
                    <input type="radio" name="genre" value="male" />
                    <label for="male">Male</label>
                </div>
                <div class="radio-btn">
                    <input type="radio" name="genre" value="female" />
                    <label for="female">Female</label>
                </div>
            </div>

            <div class="hobby-info">
                <label>Hobby</label>
                <select name="hobby">
                    <option value="" disabled selected>Select Hobby</option>
                    <option value="Coding">Coding</option>
                    <option value="Reading">Reading</option>
                    <option value="Dancing">Dancing</option>
                </select>
            </div>
        </div>

        <button type="submit">Signup</button>
        
        <a href="login.php">Alredy have an account?</a>
    </form>
</body>
</html>