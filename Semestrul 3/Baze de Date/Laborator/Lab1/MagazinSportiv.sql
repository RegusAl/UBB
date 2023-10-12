-- creare baza de date
CREATE DATABASE MagazinSportiv
go
use MagazinSportiv
go

CREATE TABLE Depozite
(
idDepozit INT PRIMARY KEY IDENTITY,
Localitate VARCHAR(50),
Nume VARCHAR(50)
)

CREATE TABLE Departamente
(
idDepartament INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
nrAngajati INT
)

CREATE TABLE Angajati
(
idAngajat INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
Prenume VARCHAR(50),
Departament INT FOREIGN KEY REFERENCES Departamente(idDepartament),
Depozit INT FOREIGN KEY REFERENCES Depozite(idDepozit),
Vechime INT
)

CREATE TABLE Furnizori
(
idFurnizor INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
Locatie VARCHAR(50)
)

CREATE TABLE Categorie
(
idCategorie INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50)
)

CREATE TABLE Produse
(
idProdus INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
Pret INT,
Stoc INT,
idFurnizor INT FOREIGN KEY REFERENCES Furnizori(idFurnizor),
idCategorie INT FOREIGN KEY REFERENCES Categorie(idCategorie),
)

CREATE TABLE ProduseDepozite
(
idProdus INT FOREIGN KEY REFERENCES Produse(idProdus),
idDepozit INT FOREIGN KEY REFERENCES Depozite(idDepozit),
CONSTRAINT pkProduseDepozite PRIMARY KEY (idProdus, idDepozit)
)

CREATE TABLE Clienti
(
idClient INT PRIMARY KEY IDENTITY,
Nume VARCHAR(50),
)

CREATE TABLE Comenzi
(
idComanda INT PRIMARY KEY IDENTITY,
idClient INT FOREIGN KEY REFERENCES Clienti(idClient),
idAngajatRaspunzator INT FOREIGN KEY REFERENCES Angajati(idAngajat),
)

CREATE TABLE Manageri
(
idManager INT FOREIGN KEY REFERENCES Depozite(idDepozit),
Numa VARCHAR(50) NOT NULL,
Experienta INT,
CONSTRAINT pkManager PRIMARY KEY(idManager)
)

