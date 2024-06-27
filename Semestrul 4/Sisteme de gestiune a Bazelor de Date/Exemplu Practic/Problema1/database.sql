GO
CREATE DATABASE SGBD_Problema1;
GO

CREATE TABLE Cofetarii
(
cod_cofetarie INT PRIMARY KEY IDENTITY,
nume_cofetarie VARCHAR(200),
adresa VARCHAR(200),
website VARCHAR(200)
);
CREATE TABLE Briose
(
cod_briosa INT PRIMARY KEY IDENTITY,
nume_briosa VARCHAR(200),
descriere VARCHAR(1000),
pret REAL,
cod_cofetarie INT FOREIGN KEY REFERENCES Cofetarii(cod_cofetarie)
ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE Tari
(
cod_tara INT PRIMARY KEY IDENTITY,
nume_tara VARCHAR(200)
);
CREATE TABLE Clienti
(
cod_client INT PRIMARY KEY IDENTITY,
nume VARCHAR(200),
email VARCHAR(200),
data_nasterii DATE,
cod_tara INT FOREIGN KEY REFERENCES Tari(cod_tara) 
ON UPDATE CASCADE ON DELETE CASCADE
);
CREATE TABLE Note
(
cod_briosa INT FOREIGN KEY REFERENCES Briose(cod_briosa)
ON UPDATE CASCADE ON DELETE CASCADE,
cod_client INT FOREIGN KEY REFERENCES Clienti(cod_client)
ON UPDATE CASCADE ON DELETE CASCADE,
nota INT,
CONSTRAINT pk_Note PRIMARY KEY (cod_briosa, cod_client)
);
--Cofetarii
INSERT INTO Cofetarii(nume_cofetarie,adresa,website) VALUES
('Lemnul Verde','adresa Lemnul Verde','www.lemnulverde.ro');
INSERT INTO Cofetarii(nume_cofetarie,adresa,website) VALUES
('Carpati','adresa Carpati','www.carpati.ro');
INSERT INTO Cofetarii(nume_cofetarie,adresa,website) VALUES
('La Casa','adresa La Casa','www.lacasa.ro');
--Briose Lemnul Verde
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa1 Lemnul Verde','descriere briosa1',5,1);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa2 Lemnul Verde','descriere briosa2',9,1);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa3 Lemnul Verde','descriere briosa3',7,1);
--Briose Carpati
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa1 Carpati','descriere briosa1',4,2);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa2 Carpati','descriere briosa2',8,2);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa3 Carpati','descriere briosa3',10,2);
--Briose La Casa
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa1 La Casa','descriere briosa1',6,3);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa2 La Casa','descriere briosa2',3,3);
INSERT INTO Briose(nume_briosa,descriere,pret,cod_cofetarie) VALUES
('briosa3 La Casa','descriere briosa3',7,3);
--Tari
INSERT INTO Tari (nume_tara) VALUES ('Romania');
INSERT INTO Tari (nume_tara) VALUES ('Ungaria');
INSERT INTO Tari (nume_tara) VALUES ('Spania');
--Clienti 
INSERT INTO Clienti (nume,email,data_nasterii,cod_tara) VALUES
('client1','client1@gmail.com','1991-02-12',1);
INSERT INTO Clienti (nume,email,data_nasterii,cod_tara) VALUES
('client2','client2@gmail.com','1972-12-02',2);
INSERT INTO Clienti (nume,email,data_nasterii,cod_tara) VALUES
('client3','client3@gmail.com','1982-10-10',3);
--Note
INSERT INTO Note (cod_briosa,cod_client,nota) VALUES (1,1,10);
INSERT INTO Note (cod_briosa,cod_client,nota) VALUES (1,2,7);
INSERT INTO Note (cod_briosa,cod_client,nota) VALUES (1,3,8);