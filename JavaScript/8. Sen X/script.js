function getSen() {
    let input = document.getElementById('input').value;
  
    let x = (input * Math.PI) / 180;
  
    document.getElementById('output1').innerHTML = Math.sin(x);
    document.getElementById('output2').innerHTML = input;
    document.getElementById('output3').innerHTML = Math.sin(x) / x;
  }