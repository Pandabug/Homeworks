function checkData(){
    const surname = document.getElementById("surname").value.toLowerCase();
    const name = document.getElementById("name").value.toLowerCase();
    const date = document.getElementById("date").value;
    const cod_fiscale = document.getElementById("cod_fiscale").value.toLowerCase();
    const mal = document.getElementById("maschio").checked;
    const fem = document.getElementById("femmina").checked;
    const origin = document.getElementById("provenienza").value;
    const currentYear = new Date().getFullYear();
    
    //check surname
    if (surname == "") window.alert("U forgot to input a Surname");
    
    //check name
    if (name == "") window.alert("U forgot to input a Name");
    
    //check kind
    if (mal == false && fem == false) alert("U forgot to input a kind");
    else if (mal == true && fem == true) alert("U can't input 2 kind");

    //check data
    if (date == "") alert("U forgot to input a date");
    else if (
            date.split('/')[0] < 1 || date.split('/')[0] > 31 || 
            date.split('/')[1] < 1 || date.split('/')[1] > 12 || 
            date.split('/')[2] > currentYear
            )
            alert("Incorrect date");
        else{
            //check cod-fiscale
            if (cod_fiscale == "") window.alert("U forgot to input a Fiscal-Code");
            else if (
                    getConsonants(surname).substring(0, 3) != cod_fiscale.substring(0, 3) || 
                    getConsonants(name).substring(0, 3) != cod_fiscale.substring(3, 6) || 
                    date.split('/')[2] != cod_fiscale.substring(6, 10)
                    )
                    window.alert("Ci sono dei errori nel codice fiscale.");
                else window.alert("Inserimento dei dati e andato a buon fine.");
        }

    
    //check origin
    if (origin == 0) alert("Input a origin");
}

function getConsonants(word){
    var letters = '';

    for (var i=0; i<word.length; i++){
        var consonant = word[i];
        if (
            consonant != 'a' && 
            consonant != 'e' && 
            consonant != 'i' && 
            consonant != 'o' && 
            consonant != 'u'
            )
            letters += consonant;
    }
    return letters;
}