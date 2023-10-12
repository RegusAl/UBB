create database PlacereaCeaiului
go
use PlacereaCeaiului
go

CREATE TABLE Magazine
(Mid INT PRIMARY KEY, Denumire varchar(50), NrMagazine int, NrClienti int)

CREATE TABLE Tipuri
(Tid INT PRIMARY KEY IDENTITY, Tip varchar(50) DEFAULT 'Negru', NrCeaiuri int)

CREATE TABLE Ceaiuri
(Cid INT PRIMARY KEY IDENTITY, Denumire varchar(50), Cantitate INT CHECK (Cantitate=1 OR Cantitate=2), Pret INT, Tid INT FOREIGN KEY REFERENCES Tipuri(Tid))

CREATE TABLE CeaiuriMagazine
(Mid INT FOREIGN KEY REFERENCES Magazine(Mid), Cid INT FOREIGN KEY REFERENCES Ceaiuri(Cid), CONSTRAINT pkCeaiuriMagazine PRIMARY KEY (Cid, Mid))

CREATE TABLE Manageri
(MaId INT FOREIGN KEY REFERENCES Magazine(Mid),
Nume varchar(50) NOT NULL,
Experienta INT,
CONSTRAINT pk_Manageri PRIMARY KEY(MaId))
