const domande = [
    {
        domanda: '10 + 5 =',
        a: '15',
        b: '7',
        c: '3',
        d: '5',
        risposta: 'a' 
    }, 
    {
        domanda: '5 - 2 =',
        a: '0',
        b: '7',
        c: '3',
        d: '2',
        risposta: 'c' 
    }, 
    {
        domanda: '8 * 2 =',
        a: '200',
        b: '16',
        c: '19',
        d: '4',
        risposta: 'b' 
    }, 
    {
        domanda: '18 / 3 =',
        a: '6',
        b: '21',
        c: '48',
        d: '7',
        risposta: 'a' 
    }, 
    {
        domanda: '6 - 2 * (2 + 1) = ',
        a: '12',
        b: '16',
        c: '0',
        d: '1',
        risposta: 'c' 
    }
];
const quiz = document.getElementById("quiz");
const answerEls = document.querySelectorAll(".answer");
const domandaEl = document.getElementById("domanda");
const a_text = document.getElementById("a_text");
const b_text = document.getElementById("b_text");
const c_text = document.getElementById("c_text");
const d_text = document.getElementById("d_text");
const done_b = document.getElementById("done");

let domanda_now = 0;
let score = 0;
let voto;

caricamento_domande();

function caricamento_domande(){
    cancella_scelta();

    const dati_domanda = domande[domanda_now];

    domandaEl.innerText = dati_domanda.domanda;
    a_text.innerText = dati_domanda.a;
    b_text.innerText = dati_domanda.b;
    c_text.innerText = dati_domanda.c;
    d_text.innerText = dati_domanda.d;
}

function scelta(){
    let answer = undefined;

    answerEls.forEach((answerEl) => {
        if (answerEl.checked){
            answer = answerEl.id;
        }
    });
    return answer;
}

function cancella_scelta(){
    answerEls.forEach((answerEl) => {
        answerEl.checked = false;
    });
}

done_b.addEventListener("click", () =>{
    
    const answer = scelta();

    if (answer){
        if (answer === domande[domanda_now].risposta){
            score++;
        }
        domanda_now++;
        if (domanda_now < domande.length){
            caricamento_domande();
        } else{
            switch(score){
                case 1:
                    voto = 'Pessimo';
                break;
                case 2:
                    voto = 'Insufficiente';
                break;
                case 3:
                    voto = 'Sufficiente';
                break;
                case 4:
                    voto = 'Discreto';
                break;
                case 5:
                    voto = 'Ottimo';
                break;
                default:
                    voto = 'Schifo';
            }
            quiz.innerHTML = `<h2>${voto} corrisponde al punteggio: ${score}/${domande.length} .</h2><br><button onclick="location.reload()">Reload</button>`;
        }
    }
});