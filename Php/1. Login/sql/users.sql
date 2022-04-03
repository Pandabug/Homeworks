CREATE DATABASE authentification;
USE authentification;

CREATE TABLE hobby (
    id_hobby INT(3) PRIMARY KEY AUTO_INCREMENT,
    hobby_name VARCHAR(25)
);

CREATE TABLE hobby_posters (
    id_hobby_poster INT(3) PRIMARY KEY AUTO_INCREMENT,
    hobby_poster_name VARCHAR(25),
    hobby_poster_description VARCHAR(100),
    hobby_poster_image VARCHAR(255),
    id_hobby_fk INT(3),
    FOREIGN KEY (id_hobby_fk) REFERENCES hobby(id_hobby)
);

CREATE TABLE users (
    id_user INT(3) PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(25),
    surname VARCHAR(25),
    nickname VARCHAR(25),
    email VARCHAR(25),
    password VARCHAR(15),
    genre VARCHAR(25),
    id_hobby_fk INT(3),
    FOREIGN KEY (id_hobby_fk) REFERENCES hobby(id_hobby)
);

INSERT INTO hobby (hobby_name) VALUES ('Coding'), ('Reading'), ('Danzig');

INSERT INTO hobby_posters (hobby_poster_name, hobby_poster_description, hobby_poster_image, id_hobby_fk) VALUES ("Visual Studio Code", "Visual Studio Code è un editor di codice sorgente sviluppato da Microsoft per Windows, Linux e macOS. Include il supporto per debugging, un controllo per Git integrato, syntax highlighting, IntelliSense, snippet e refactoring del codice.", "https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Visual_Studio_Code_1.35_icon.svg/2048px-Visual_Studio_Code_1.35_icon.svg.png", 1);
INSERT INTO hobby_posters (hobby_poster_name, hobby_poster_description, hobby_poster_image, id_hobby_fk) VALUES ("PyCharm", "PyCharm è un ambiente di sviluppo integrato per il linguaggio di programmazione Python sviluppato da JetBrains.", "https://pbs.twimg.com/profile_images/1206603239791218688/0AwZ0m6W_400x400.jpg", 1);

INSERT INTO hobby_posters (hobby_poster_name, hobby_poster_description, hobby_poster_image, id_hobby_fk) VALUES ("Assassinio sul Nilo", "Mentre è in vacanza sul Nilo, il geniale detective di fama mondiale Hercule Poirot si ritrova a dover indagare sull'omicidio di una giovane ereditiera.", "https://images-na.ssl-images-amazon.com/images/I/71tBYbBACFL.jpg", 2);
