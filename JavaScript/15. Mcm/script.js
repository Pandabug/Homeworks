function getPrimaryNumber(){
    const numberOfNumbers = prompt("Input number of numbers: "); 
    var number = [];
    
    for (var i=0; i<numberOfNumbers; i++)
        number.push(prompt("Input number: "));

    const mcd = (a, b) => a ? mcd(b % a, a) : b;
    const mcm = (a, b) => a * b / mcd(a, b);

    document.getElementById("myArray").innerHTML = number.reduce(mcm);
}