CREATE DATABASE restaurante
GO 
USE restaurante
GO

CREATE TABLE Tipuri(
	idTip INT PRIMARY KEY IDENTITY,
	nume VARCHAR(50),
	descriere VARCHAR(50)
)

CREATE TABLE Orase(
	idOras INT PRIMARY KEY IDENTITY,
	nume VARCHAR(50)
)

CREATE TABLE Restaurante(
	idRestaurant INT PRIMARY KEY IDENTITY,
	nume VARCHAR(50),
	adresa VARCHAR(50),
	telefon BIGINT,
	idOras INT FOREIGN KEY REFERENCES Orase(idOras),
	idTip INT FOREIGN KEY REFERENCES Tipuri(idTip)
)

CREATE TABLE Utilizatori(
	idUtilizator INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20),
	email VARCHAR(20),
	parola BIGINT,
)

CREATE TABLE Note(
	idUtilizator INT FOREIGN KEY REFERENCES Utilizatori(idUtilizator),
    idRestaurant INT FOREIGN KEY REFERENCES Restaurante(idRestaurant),
	nota INT,
	CONSTRAINT pk_Nota PRIMARY KEY (idRestaurant, idUtilizator) 
)

-- DROP TABLE Note, Utilizatori, Restaurante, Orase, Tipuri


