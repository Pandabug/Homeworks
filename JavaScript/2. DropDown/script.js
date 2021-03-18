/*
Roma - https://it.wikipedia.org/wiki/Roma
Venezia - https://it.wikipedia.org/wiki/Venezia
Sardegna - https://it.wikipedia.org/wiki/Sardegna
Sicilia - https://it.wikipedia.org/wiki/Sicilia
Firenze - https://it.wikipedia.org/wiki/Firenze
Napoli - https://it.wikipedia.org/wiki/Napoli
*/

const descrizione = [
    "",
    "Fondata secondo la tradizione il 21 aprile del 753 a.C. (sebbene scavi recenti nel Lapis niger farebbero risalire la fondazione a 2 secoli prima), nel corso dei suoi tre millenni di storia è stata la prima metropoli dell'umanità, cuore pulsante di una delle più importanti civiltà antiche, che influenzò la società, la cultura, la lingua, la letteratura, l'arte, l'architettura, l'urbanistica, l'ingegneria civile, la filosofia, la religione, il diritto e i costumi dei secoli successivi. Luogo di origine della lingua latina, fu capitale dell'Impero romano che estendeva il suo dominio su tutto il bacino del Mediterraneo e gran parte dell'Europa, dello Stato Pontificio, sottoposto al potere temporale dei papi e del Regno d'Italia (dal 1871 al 1946). Per antonomasia, è definita l'Urbe, Caput Mundi e Città eterna. ", 
    "La città è stata per 1100 anni la capitale della Serenissima Repubblica di Venezia ed è conosciuta a questo riguardo come la Serenissima, la Dominante e la Regina dell'Adriatico: per le peculiarità urbanistiche e per il suo patrimonio artistico, è universalmente considerata una tra le più belle città del mondo, dichiarata, assieme alla sua laguna, patrimonio dell'umanità dall'UNESCO, che ha contribuito a farne la seconda città italiana dopo Roma con il più alto flusso turistico.",
    "Il suo territorio coincide con l'arcipelago sardo, costituito quasi interamente dall'isola di Sardegna, situata nel Mediterraneo occidentale, e da un considerevole numero di piccole isole e arcipelaghi circostanti. La sua posizione strategica e la sua ricchezza di minerali hanno favorito nell'antichità il suo popolamento e lo svilupparsi di traffici commerciali e scambi culturali tra i suoi abitanti e i popoli rivieraschi.",
    "Il territorio della regione è costituito quasi interamente dall'isola omonima, la più grande isola dell'Italia e del Mediterraneo, nonché la 45ª isola più estesa nel mondo, bagnata a nord dal Mar Tirreno, a ovest dal Canale di Sicilia, a sud-ovest dal Mar di Sicilia, a sud-est dal canale di Malta, a est dal Mar Ionio e a nord-est dallo stretto di Messina che la separa dalla Calabria, con la parte rimanente che è costituita dagli arcipelaghi delle Eolie, delle Egadi e delle Pelagie e dalle isole di Ustica e Pantelleria. È la regione più estesa d'Italia, la quarta per popolazione (dopo Lombardia, Lazio e Campania), e il suo territorio è ripartito in 390 comuni a loro volta costituiti in tre città metropolitane (Palermo, Catania e Messina) e sei liberi Consorzi comunali.",
    "Nel Medioevo è stata un importante centro artistico, culturale, commerciale, politico, economico e finanziario; nell'età moderna ha ricoperto il ruolo di capitale del Granducato di Toscana dal 1569 al 1859 che, con il governo delle famiglie dei Medici e dei Lorena, divenne uno degli stati più ricchi e moderni. Le varie vicissitudini politiche, la potenza finanziaria e mercantile e le influenze in ogni campo della cultura hanno fatto della città un crocevia fondamentale della storia italiana ed europea. Nel 1865 Firenze fu proclamata capitale del Regno d'Italia (seconda, dopo Torino), mantenendo questo status fino al 1871, anno che segna la fine del Risorgimento. ",
    "Fondata dai cumani nell'VIII secolo a.C., fu tra le città più importanti della Magna Grecia[5] e giocò un notevole ruolo commerciale, culturale e religioso nei confronti delle popolazioni italiche circostanti[6]. Dopo il crollo dell'Impero romano, nell'VIII secolo la città formò un ducato autonomo indipendente dall'Impero bizantino; in seguito, dal XIII secolo e per più di cinquecento anni, fu capitale del Regno di Napoli; con la Restaurazione divenne capitale del Regno delle Due Sicilie sotto i Borbone fino all'Unità d'Italia.",
]

caricamentoImmagine();

var cont = 0;

function caricamentoImmagine(){
    switch (output = document.getElementById("scelta").value){
        case "0":
            cont++;
            if (cont > 0){
                alert("Error");
            }
            immage = undefined;
        break;
        case "1":
            immage = "https://archaeologicalphotorelief.files.wordpress.com/2014/06/roma.jpg";
        break;
        case "2":
            immage = "https://www.wallpapers13.com/wp-content/uploads/2016/01/Venice_italy_venezia-2560x1600.jpg";
        break;
        case "3":
            immage = "http://2.bp.blogspot.com/-G1urw16dkmA/UhE40ZBlzqI/AAAAAAAAA-w/i1V6IIYXBbw/s1600/Sardegna.jpg";
        break;
        case "4":
            immage = "https://cdn.hipwallpaper.com/i/82/53/8Prmeb.jpg";
        break;
        case "5":
            immage = "https://www.fashionactivation.com/wp-content/uploads/2017/09/piazzale-michelangelo-firenze.jpg";
        break;
        case "6":
            immage = "http://wp1.blog.com.gr/mariadrakou28/wp-content/uploads/sites/1521/2016/10/napoli.06.jpg";
        break;
    }
    document.getElementById("immagine").src = immage;
    document.getElementById("descrizione").innerText = descrizione[output];
}