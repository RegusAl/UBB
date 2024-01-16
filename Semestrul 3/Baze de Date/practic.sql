CREATE DATABASE practic

USE practic
GO

CREATE TABLE PietePeste(
	idPiata INT PRIMARY KEY IDENTITY,
	denumire varchar(50),
	cartier varchar(50),
	localitate varchar(50)
)

CREATE TABLE Standuri(
	idStand INT PRIMARY KEY IDENTITY,
	descriere varchar(50),
	nr_produse INT,
	ora_deschidere TIME,
	ora_inchidere TIME,
	idPiata INT FOREIGN KEY REFERENCES PietePeste(idPiata)
)

CREATE TABLE Client(
	idClient INT PRIMARY KEY IDENTITY,
	nume varchar(50),
	prenume varchar(50),
	gen varchar(50),
	varsta INT,
	idPiata INT FOREIGN KEY REFERENCES PietePeste(idPiata)
)

CREATE TABLE Peste(
	idPeste INT PRIMARY KEY IDENTITY,
	denumire varchar(50),
	pret INT,
	cantitate INT
)

CREATE TABLE Vanzari(
	idPiata INT FOREIGN KEY REFERENCES PietePeste(idPiata),
	idPeste INT FOREIGN KEY REFERENCES Peste(idPeste),
	suma_totala INT,
	clienti INT,
	PRIMARY KEY (idPiata, idPeste)
)

DROP TABLE Vanzari, Peste

-- inserari
INSERT INTO PietePeste(denumire, cartier, localitate) VALUES
	('pastravarie Cluj', 'Sopor', 'Cluj-napoca'),
	('la Balta', 'Zorilor', 'Cluj-Napoca')

INSERT INTO Peste(denumire, pret, cantitate) VALUES
	('pastrav', 50, 4),
	('somon', 190, 2),
	('somn', 44, 6)

INSERT INTO Vanzari(idPiata, idPeste, suma_totala, clienti) VALUES
	(1, 1, 200, 5),
	(1, 2, 500, 20)

INSERT INTO Client(nume, prenume, gen, varsta, idPiata) VALUES
	('Alex', 'Bob', 'M', 80, 1),
	('Mihaela', 'Radu', 'F', 40, 1),
	('Ana', 'Maria', 'F', 45, 2)

INSERT INTO Standuri(descriere, nr_produse, ora_deschidere, ora_inchidere, idPiata) VALUES
	('rapitori', 34, '10:00', '11:00', 1)

SELECT * FROM Client
SELECT * FROM Standuri
SELECT * FROM PietePeste
SELECT * FROM Peste
SELECT * FROM Vanzari

CREATE OR ALTER PROCEDURE adaugaPestePiata
	@idPiata INT,
	@idPeste INT,
	@suma INT,
	@numar_clienti INT
AS
BEGIN
	IF EXISTS (SELECT * FROM Vanzari WHERE idPiata = @idPiata AND idPeste = @idPeste)
	BEGIN
		UPDATE Vanzari
		SET suma_totala = @suma, clienti = @numar_clienti
		WHERE @idPiata = idPiata AND @idPeste = idPeste
		print 'S-a actualizat'
	END
	ELSE
	BEGIN
		INSERT INTO Vanzari(idPiata, idPeste, suma_totala, clienti) VALUES
					(@idPiata, @idPeste, @suma, @numar_clienti)
		print 'S-a adaugat'
	END
END

EXEC adaugaPestePiata 1, 1, 567, 12
EXEC adaugaPestePiata 2, 1, 678, 2

CREATE OR ALTER VIEW afisareClienti
AS
	SELECT C.nume FROM Client C
	INNER JOIN PietePeste PP ON C.idPiata = PP.idPiata
	INNER JOIN Vanzari V ON PP.idPiata = V.idPiata
	GROUP BY C.nume,PP.idPiata
	HAVING COUNT(*) = (SELECT COUNT(*) FROM Peste)
GO

SELECT * FROM afisareClienti