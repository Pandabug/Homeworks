const questions = [
    {
        question: '15 + 15 =',
        a: '31',
        b: '30',
        c: '29',
        answer: 'b'
    },
];
const quiz = document.getElementById('quiz');
const answerEl = document.querySelectorAll('.answer');
const questionEl = document.getElementById('question');
const a_text = document.getElementById('a_text');
const b_text = document.getElementById('b_text');
const c_text = document.getElementById('c_text');
const done_btn = document.getElementById('done');

chargeQuestion();

function chargeQuestion(){
    const question_data = questions[0];

    questionEl.innerText = question_data.question;
    a_text.innerText = question_data.a;
    b_text.innerText = question_data.b;
    c_text.innerText = question_data.c;
}

done_btn.addEventListener("click", () =>{
    let answer = undefined;

    answerEl.forEach((answerEl) =>{
        if(answerEl.checked){
            answer = answerEl.id;
        }
    });

    if(answer){
        if (answer == questions[0].answer)
            quiz.innerHTML = `<h2>Your answer is TRUE</h2><button onclick="location.reload()">Reload</button>`;
        else 
            quiz.innerHTML = `<h2>Your answer is FALSE, The correct one was ${questions[0].answer[0]}</h2><button onclick="location.reload()">Reload</button>`
    }
});

function calcKm(){
    const speed = document.getElementById('speed').value;
    const time = document.getElementById('time').value;

    space.innerHTML = `${speed * time} km.<button onclick="location.reload()">Reload</button>`;
}