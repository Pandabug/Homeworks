const MaxSize = 5;

function array(){
    var number;
    var a = [MaxSize];

    // do{
        number = parseInt(prompt("Input number: "));
    // } while (number != 0);

    for (var i=0; i<number; i++)
        a[i] = Math.floor(50 * Math.random()) + 1;
        
    document.getElementById("out").innerHTML = Math.max(...a);
    
    var outNumbers = "";
    print(a, number);
}

function print(a, number){
    document.write("<table border=1><tr>")

    for (var i=0; i<number; i++)
        document.write("<td>" + a[i] + "</td>")

    document.write("</tr></table>")

}