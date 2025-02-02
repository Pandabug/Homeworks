function train(){
    const name = document.getElementById("name").value;
    const surname = document.getElementById("surname").value;
    const date1 = document.getElementById("date1").value;
    const date2 = document.getElementById("date2").value;
    const station1 = document.getElementById("station1").value;
    const station2 = document.getElementById("station2").value;

    if (name == "")
        alert('Ti sei scordato di inserire il nome');
    
    if (surname == "")
        alert('Ti sei scordato di inserire il cognome');
    
    if (date1 == "")
        alert('Ti sei scordato di inserire il data di partenza');
    if (date2 == "")
        alert('Ti sei scordato di inserire il data di arrivo');
    if (date1 >= date2)
        alert('Data inserita non e corretta');
    
    if (station1 == 0)
        alert('Ti sei scordato di inserire il stazione di partenza');
    if (station2 == 0)
        alert('Ti sei scordato di inserire il stazione di arrivo');
    if (station1 == station2)
    alert("Errore nell'inserimento delle stazioni");
}