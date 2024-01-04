CREATE DATABASE trenuri
GO
USE trenuri
GO

-- creare tabele

-- DROP TABLE Tip
CREATE TABLE Tip(
	idTip INT PRIMARY KEY IDENTITY,
	descriere VARCHAR(20)
);

-- DROP TABLE Statie
CREATE TABLE Statie(
	idStatie INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20)
)

-- DROP TABLE Trenuri
CREATE TABLE Trenuri(
	idTren INT PRIMARY KEY IDENTITY,
	nume VARCHAR(20),
	idTip INT FOREIGN KEY REFERENCES Tip(idTip)  
)

CREATE TABLE Rute(
	idRute INT PRIMARY KEY IDENTITY,
	idTren INT FOREIGN KEY REFERENCES Trenuri(idTren),
	nume VARCHAR(20)
)

CREATE TABLE StatiiRute(
	idRute INT FOREIGN KEY REFERENCES Rute(idRute),
	idStatie INT FOREIGN KEY REFERENCES Statie(idStatie),
	oraPlecare time,
	oraSosire time,
	constraint pk_SR PRIMARY KEY  (idRute, idStatie)
)

-- populare tabele

insert into Tip(descriere) values
('IC'),
('IR'),
('R'),
('IRN')

insert into Trenuri(idTip,nume) values
(1,'Tren1'),
(1,'Tren2'),
(2,'Tren3'),
(2,'Tren4'),
(3,'Tren5'),
(3,'Tren6'),
(4,'Tren7'),
(4,'Tren8')

insert into Statie(nume) values
('Bucuresti'),
('Brasov'),
('Cluj-Napoca'),
('Ploiesti'),
('Constanta'),
('Timisoara'),
('Oradea')

insert into Rute(idTren,nume) values
(1,'Bucuresti-Cluj'),
(2,'Oradea-Cluj'),
(3,'Bucuresti-Constanta'),
(4,'Timisoara-Bucuresti'),
(1,'Timisoara-Constanta'),
(3,'Bucuresti-Brasov')

insert into StatiiRute(idRute,idStatie,oraPlecare,oraSosire) values
(1,1,'5:40','5:50'),
(1,3,'6:20','6:25'),
(1,2,'8:10','8:35'),
(4,1,'5:00','5:10'),
(4,2,'6:00','6:10'),
(4,3,'7:00','7:10'),
(4,4,'8:00','8:10'),
(4,5,'9:10','9:15'),
(4,6,'10:00','10:10'),
(4,7,'11:00','11:10')
go

-- procedura

CREATE PROCEDURE addRuta
	@idRuta INT,
	@idStatie INT,
	@oraPlecare TIME,
	@oraSosire TIME
	as
	begin
		IF exists (SELECT * FROM StatiiRute WHERE @idRuta = idRute AND @idStatie = idStatie)
		BEGIN
			UPDATE StatiiRute
			SET oraPlecare = @oraPlecare, oraSosire = @oraSosire
			WHERE idRute = @idRuta AND idStatie = @idStatie
		END
		ELSE
		BEGIN
			INSERT INTO StatiiRute(idRute, idStatie, oraPlecare, oraSosire) VALUES (@idRuta, @idStatie, @oraPlecare, @oraSosire)
		END
	END
GO

	SELECT * FROM StatiiRute

	exec addRuta 1, 1, '4:00', '4:05';
	exec addRuta 3, 1, '6:00', '9:01';

	-- view
	CREATE OR ALTER VIEW RuteCuToateStatiile
	AS
		SELECT r.nume AS 'Nume Ruta' FROM Rute r JOIN  StatiiRute sr on r.idRute = sr.idRute
		GROUP BY r.nume HAVING COUNT(sr.idRute) = (select count(*) from Statie)
	GO


	SELECT * FROM RuteCuToateStatiile