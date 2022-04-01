CREATE DATABASE authentification;
USE authentification;

CREATE TABLE hobby (
    id_hobby INT(3) PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(25)
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

INSERT INTO hobby (name) VALUES ('Coding'), ('Reading'), ('Danzig');