function getPassword(){
    let password = document.getElementById("password").value;
    const chars = '!?$?%^&*()_-+={[}]:;@#|\\<,>.?/';
    const letters = 'abcdefghijklmnopqrstuwxyz';
    const numbers = '0123456789';
    const upperCases = 'ABCDEFGHILMNOPQRSTUVZ';
    let checkChar = false, checkLetters = false, checkNumbers = false, checkUpperCase = false;
    
    if (password == "")
        alert("Invalid Password");
        else if (password.length < 8)
            alert("Invalid Password");
            else{
                for (var i=0; i<password.length; i++){
                        if (chars.indexOf(password[i]) != -1)
                            checkChar = true;
                        if (letters.indexOf(password[i]) != -1)
                            checkLetters = true;
                        if (numbers.indexOf(password[i]) != -1)
                            checkNumbers = true;
                        if (upperCases.indexOf(password[i]) != -1)
                            checkUpperCase = true;
                }
            }
    if (checkChar && checkLetters && checkNumbers && checkUpperCase)
        alert("U choised a good password");
    else
        alert("Invalid Password");
}