
function primeNumber(){
    var number = document.getElementById("number").value;
    var arrayPrimeNumbers = "";
    var i = 0;

    do {
    let check = true;
        number++;

        for (var j=2; j<number; j++) {
            if ((number % j) == 0){
                check = false;
                break;
            }
        }

        if(check == true){
            arrayPrimeNumbers += number + ", ";
            i++;
        }
    } while (i < 10);
    document.getElementById("out").innerHTML = arrayPrimeNumbers;
}