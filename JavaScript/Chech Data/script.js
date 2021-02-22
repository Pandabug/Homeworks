function checkData(){
    const surname = document.getElementById("surname").value;
    const name = document.getElementById("name").value;
    const data = document.getElementById("data").value.split("/");
    const cod_fiscale = document.getElementById("cod_fiscale").value;
    const mal = document.getElementById("maschio").checked;
    const fem = document.getElementById("femmina").checked;
    const origin = document.getElementById("provenienza").value;
    
    let gg = parseInt(data[0]);
    let mm = parseInt(data[1]);
    let aa = parseInt(data[2]);

    //cehck surname
    if (surname == "") window.alert("U forgot to input a Surname");
    
    //check name
    if (name == "") window.alert("U forgot to input a Name");
    
    //check kind
    if (mal == false && fem == false) alert("U forgot to input a kind");
    else if (mal == true && fem == true) alert("U can't input 2 kind");

    //check data
    if (data == "") window.alert("U forgot to input a Date");
    else if (gg <= 1 || gg > 32 && mm <= 1 || mm > 13 && aa > 2021)
            window.alert("Date u input is incorrect");

    //check cod-fiscale
    if (cod_fiscale == "") window.alert("U forgot to input a Fiscal-Code");
    
    //check origin
    if (origin == 0) alert("Input a origin");
}