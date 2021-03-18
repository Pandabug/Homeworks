function findConsonants(){
    const name = document.getElementById("inputName").value;
    const surname = document.getElementById("inputSurname").value;
    const consonantsList = 'bcdfghjklmnpqrstvwxyz';
    var contNameLetters = 0;
    var contSurnameLetters = 0;
    var outName = '';
    var outSurname = '';

    for (var i=0; i<name.length; i++)
        if (consonantsList.indexOf(name[i]) != -1){
            contNameLetters++;
            outName += name[i] + ",";
        }
        document.getElementById("outputNameNumber").innerHTML = "Le lettere consonanti del nome sono: " + contNameLetters;
        document.getElementById("outputNameLetters").innerHTML = outName;

        for (var i=0; i<surname.length; i++)
            if (consonantsList.indexOf(surname[i]) != -1){
                contSurnameLetters++;
                outSurname += surname[i] + ",";
            }
            document.getElementById("outputSurnameNumber").innerHTML = "Le lettere consonanti del cognome sono: " + contSurnameLetters;
            document.getElementById("outputSurnameLetters").innerHTML = outSurname;
}