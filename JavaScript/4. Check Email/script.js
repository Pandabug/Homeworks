function getEmailAdress(){
    var check = false;
    const name = document.getElementById('name').value;
    const surname = document.getElementById('surname').value;
    var email = document.getElementById('email').value;
    
    if (name == "" || surname == "" || email == "")window.alert("Some data are missing");
    else{
        for (var i=0; i<email.length; i++)
            if (email.indexOf("@") != -1 && email.indexOf(".") != -1) check = true;
        if (!check) window.alert("Email adress erred");
        else window.alert("Registrazione completata!")
    }
}