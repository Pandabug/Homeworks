const dati = [
"https://archaeologicalphotorelief.files.wordpress.com/2014/06/roma.jpg",
"http://2.bp.blogspot.com/-G1urw16dkmA/UhE40ZBlzqI/AAAAAAAAA-w/i1V6IIYXBbw/s1600/Sardegna.jpg",
"https://res.cloudinary.com/hzekpb1cg/image/upload/c_fill,h_410,w_800,f_auto/s3/public/prod/s3fs-public/Italy_Napoli.jpg",
"https://www.ouyeah.travel/blog/wp-content/uploads/2019/05/Florencia.jpg",
"https://static.standard.co.uk/s3fs-public/thumbnails/image/2016/07/11/17/an102350797e5k1dr-bolognait.jpg",
"http://www.lovelymolise.com/wp-content/uploads/2019/02/campobasso-panorama-dall-alto.jpg"
];

var cont = -1;
const datiE = dati.length;

forward();

function forward(){
    cont++;
    document.getElementById("immage").src = dati[cont];
    
    numE = cont + 1;
    document.getElementById("numEl").innerHTML = "Immage " + numE + " of " + datiE;

    if (cont == datiE-1) document.getElementById("forward_btn").disabled = true;
    else document.getElementById("backward_btn").disabled = false;
}

function backward(){
    cont--;
    document.getElementById("immage").src = dati[cont];

    numE = cont + 1;
    document.getElementById("numEl").innerHTML = "Immage " + numE + " of " + datiE;

    if (cont == 0) document.getElementById("backward_btn").disabled = true;
    else document.getElementById("forward_btn").disabled = false;
}