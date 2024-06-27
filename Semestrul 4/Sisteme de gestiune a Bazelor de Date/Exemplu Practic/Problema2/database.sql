CREATE DATABASE SGBD_Problema2

GO
USE SGBD_Problema2
GO

CREATE TABLE Tari
(
cod_tara INT PRIMARY KEY IDENTITY,
nume_tara VARCHAR(200),
descriere VARCHAR(200)
);
CREATE TABLE Artisti
(
cod_artist INT PRIMARY KEY IDENTITY,
nume_artist VARCHAR(200),
data_nasterii DATE,
website VARCHAR(200),
cod_tara INT FOREIGN KEY REFERENCES Tari(cod_tara)
ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE Melodii 
(
cod_melodie INT PRIMARY KEY IDENTITY,
titlu VARCHAR(200),
an_lansare INT,
durata TIME,
cod_artist INT FOREIGN KEY REFERENCES Artisti(cod_artist)
ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE Clasamente
(
cod_clasament INT PRIMARY KEY IDENTITY,
nume_clasament VARCHAR(200)
);
CREATE TABLE PozitieClasament
(
cod_melodie INT FOREIGN KEY REFERENCES Melodii(cod_melodie)
ON UPDATE CASCADE ON DELETE CASCADE,
cod_clasament INT FOREIGN KEY REFERENCES Clasamente(cod_clasament)
ON UPDATE CASCADE ON DELETE CASCADE,
pozitie_maxima INT,
CONSTRAINT pk_PozitieClasament PRIMARY KEY (cod_melodie,cod_clasament)
);
--Tari
INSERT INTO Tari (nume_tara,descriere) VALUES ('tara1','descriere tara1');
INSERT INTO Tari (nume_tara,descriere) VALUES ('tara2','descriere tara2');
INSERT INTO Tari (nume_tara,descriere) VALUES ('tara3','descriere tara3');
--Artisti
INSERT INTO Artisti (nume_artist,data_nasterii,website,cod_tara) VALUES
('artist1 tara1','1987-02-02','www.artist1.com',1);
INSERT INTO Artisti (nume_artist,data_nasterii,website,cod_tara) VALUES
('artist2 tara2','1997-02-02','www.artist2.com',2);
INSERT INTO Artisti (nume_artist,data_nasterii,website,cod_tara) VALUES
('artist3 tara3','1977-02-02','www.artist3.com',3);
--Melodii artist 1
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie1 artist1',2000,'00:03:40',1);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie2 artist1',2001,'00:04:03',1);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie3 artist1',2002,'00:02:49',1);
--Melodii artist 2
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie1 artist2',2009,'00:03:40',2);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie2 artist2',2010,'00:04:43',2);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie3 artist2',2012,'00:05:49',2);
--Melodii artist 3
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie1 artist3',2007,'00:05:20',3);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie2 artist3',2017,'00:07:48',3);
INSERT INTO Melodii (titlu,an_lansare,durata,cod_artist) VALUES
('melodie3 artist3',2016,'00:02:49',3);
--Clasamente
INSERT INTO Clasamente (nume_clasament) VALUES ('clasament1');
INSERT INTO Clasamente (nume_clasament) VALUES ('clasament2');
INSERT INTO Clasamente (nume_clasament) VALUES ('clasament3');
--PozitieClasament
INSERT INTO PozitieClasament (cod_melodie,cod_clasament,pozitie_maxima) VALUES
(1,1,2);
INSERT INTO PozitieClasament (cod_melodie,cod_clasament,pozitie_maxima) VALUES
(1,2,10);
INSERT INTO PozitieClasament (cod_melodie,cod_clasament,pozitie_maxima) VALUES
(1,3,20);