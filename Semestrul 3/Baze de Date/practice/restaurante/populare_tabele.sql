USE restaurante GO

INSERT INTO Tipuri(nume, descriere) 
VALUES ('fast food', 'mancare pregatita rapid'),
       ('gourmand', 'delicatese'),
	   ('romanesc', 'specific romanesc')

INSERT INTO Orase(nume)
VALUES ('Suceava'),
       ('Petrosani'),
	   ('Cluj-Napoca')

INSERT INTO Restaurante(nume, adresa, telefon, idTip, idOras)
VALUES ('Mc Donald', 'str. Antonio Betoniu', 0799898765, 1, 1),
       ('Mozart', 'str. Ureche', 098765433, 2, 1),
	   ('La Bunica', 'str. Centrala', 112, 3, 1),
	   ('La Bunicu', 'str. Veche', 911, 3, 3)

INSERT INTO Utilizatori(nume, email) 
VALUES ('Alex', 'alex@gmail.com'),
       ('Ana', 'ana@gmail.com'),
	   ('Maria', 'maria1234@gmail.com'),
	   ('George', 'georgel@gmail.com'),
	   ('qwerty', 'qwerty@gmail.com'),
	   ('lololo', 'lololo@gmail.com'),
	   ('theGamer', 'thegamer@gmail.com')

INSERT INTO Note(idUtilizator, idRestaurant, nota)
VALUES (1, 1, 9),
       (1, 2, 7),
	   (1, 3, 10),
	   (2, 1, 7),
	   (2, 3, 9),
	   (3, 3, 10),
	   (3, 4, 5),
	   (4, 1, 4),
	   (4, 2, 9)

SELECT * FROM Tipuri
SELECT * FROM Restaurante
SELECT * FROM Orase
SELECT * FROM Utilizatori
SELECT * FROM Note