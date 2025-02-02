function checkData(){
    const surname = document.getElementById("surname").value;
    const name = document.getElementById("name").value;
    const date1 = document.getElementById("date1").value;
    const date2 = document.getElementById("date2").value;

    if (surname == "")
        alert("Input surname");
        
    if (name == "")
        alert("Input name");

    if (date1 == "" || date2 == "")
        alert("Input data");
    else{
        checkDate(date1);
        checkDate(date2);
        
        if (date1 > date2)
            alert("Incorrect date");
    }
}

function checkDate(date){
    const currentYear = new Date().getFullYear();
    
    if (
        date.split('/')[0] < 1 || date.split('/')[0] > 31 || 
        date.split('/')[1] < 1 || date.split('/')[1] > 12 || 
        date.split('/')[2] > currentYear
        )
    alert("Incorrect date");
}