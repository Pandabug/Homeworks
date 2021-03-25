function getSen(){
    var input = document.getElementById('input').value;

    document.getElementById('output1').innerHTML = input;
    document.getElementById('output2').innerHTML = Math.cos((input * Math.PI) / 100);
}