var arrayPrimaryNumbers = [];

function getPrimaryNumber(){
    var number, cont = 0;
    
    number = parseInt(prompt("Input number: "));

    for (var i=2; i<number; i++)
        if ((number % i) == 0){
            cont++;
            break;
        }

    if (cont > 0) alert("Il numero inserito non e un numero primo.");
    else{ 
        alert("In numbero inserito e un numero primo.");
        arrayPrimaryNumbers += number + ", ";
    }

    document.getElementById("myArray").innerHTML = arrayPrimaryNumbers;
}