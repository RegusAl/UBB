USE MagazinSportiv
GO

--- FURNIZORI
INSERT INTO Furnizori(Nume, Locatie) 
VALUES ('Nike', 'North-America'),
	   ('Adidas', 'North-America'),
	   ('Altra', 'North-America'),
       ('Under Armour', 'North-America'),
	   ('Puma', 'North-America'),
	   ('Patagonia', 'South-America'),
	   ('The North Face', 'North-America')

--- CATEGORIE
INSERT INTO Categorie(Nume)
VALUES ('Fitness'),
	   ('Alergare'),
       ('Drumetie'),
       ('Alpinism'),
       ('Schi')

--- PRODUSE
INSERT INTO Produse(Nume, Pret, Stoc, idFurnizor, idCategorie)
VALUES
	   -- Nike (1)
	   ('Pantaloni scurti - Nike', 90, 2, 1, 1),
	   ('Nike Revolution 6', 190, 3, 1, 2),
	   -- Adidas (2)


	   -- Altra (3)
	   ('Altra Provision 5', 500, 4, 3, 2),
	   ('Altra Olympus 6', 700, 9, 3, 2),
	   ('Altra Outroad 2', 750, 3, 3, 2),
	   ('Altra Lone Peak 3.5', 250, 5, 3, 2),
	   ('Altra Youth Lone Peak', 100, 2, 3, 2),
  	   -- Under Armour (4)
	  ('Tricou - Under Armour', 65, 6, 4, 1),
	   

	   -- Puma (5)


	   -- Patagonia (6)
	   ('Vesta', 120, 1, 6, 3),
	   ('Geaca schi', 200, 3, 6, 5),
	   ('Vesta Patagonia Nano Puff', 850, 2, 6, 3),
	   ('Bluza Patagonia Capilene', 270, 4, 6, 3),
	   ('Polar Patagonia R1 Air Fz Hoodie', 750, 2, 6, 3),
	   ('Rucsac Patagonia Descensionist 40l', 1100, 5, 6, 3),
	   -- The North Face (7)
	   ('Caciula The North Face Gateway', 110, 2, 7, 3),
	   ('Jacheta Quest Hooded The North Face', 800, 5, 7, 3),
	   ('Bluze North Face Fine', 220, 6, 7, 3),
	   ('Rucsac The North Face Hot Shot', 550, 9, 7, 3),
	   ('Vesta The North Face Retro', 1400, 1, 7, 3)


--- DEPOZITE
INSERT INTO Depozite(Localitate, Nume)
VALUES ('Cluj-Napoca', 'depozit central'),
	   ('Suceava', 'depozit estic'),
	   ('Bucuresti', 'depozit capitala')

--- PRODUSE-DEPOZITE
INSERT INTO ProduseDepozite(idProdus, idDepozit)
VALUES (1,1), (5, 1), (6, 1), (2, 2), (3, 2), (4,2), (1,3)

--- MANAGERI
INSERT INTO Manageri(idManager, Nume, Experienta)
VALUES (1, 'Mihai Ion', 15),
	   (2, 'Valeriu Vasi', 8),
	   (3, 'Emilian D', 11)

INSERT INTO Departamente(Nume, nrAngajati)
VALUES ('Caserie', 12),
       ('Marketing', 6),
	   ('Logistica', 20),
	   ('Aprovizionare', 40)

INSERT INTO Angajati(Nume, Prenume, Departament, Depozit, Vechime)
VALUES ('Costi', 'Cornea', 1, 1, 3),
	   ('Virgil', 'Cinca', 1, 1, 4),
	   ('Radu', 'Gogean', 1, 1, 5),
	   ('Cristina', 'Donceanu', 2, 1, 7),
	   ('Carmen', 'Tugurlan', 2, 1, 8),
	   ('Rodica', 'Arcos', 3, 1, 4),
	   ('Augustina', 'Tomescu', 3, 1, 6),
	   ('Andrei', 'Toma', 3, 1, 9),
	   ('Emil', 'Vladu', 4, 1, 3),
	   ('Nicolae', 'Mihai', 4, 1, 6),
	   ('Laur', 'Mihnea', 4, 1, 9),

	   ('Costica', 'Pacurar', 1, 2, 3),
	   ('Marc', 'Moisuc', 1, 2, 4),
	   ('Tudor', 'Plesu', 1, 2, 5),
	   ('Horea', 'Neagoe', 2, 2, 7),
	   ('Doru', 'Popa', 2, 2, 8),
	   ('Dorian', 'Popa', 3, 2, 4),
	   ('Dorina', 'Mihaili', 3, 2, 6),
	   ('Ana', 'Pavel', 3, 2, 9),
	   ('Cici', 'Galca', 4, 2, 3),
	   ('Silvia', 'Cojocar', 4, 2, 6),
	   ('Victoria', 'Voicu', 4, 2, 9),

	   ('Viorel', 'Stefan', 1, 3, 3),
	   ('Ionus', 'Theo', 1, 3, 4),
	   ('Nandru', 'Oprea', 1, 3, 5),
	   ('Toma', 'Oprea', 2, 3, 7),
	   ('Bogdan', 'Banciu', 2, 3, 8),
	   ('Mircea', 'Bravo', 3, 3, 4),
	   ('Gabriela', 'Tomescu', 3, 3, 6),
	   ('Gabi', 'Poenaru', 3, 3, 9),
	   ('Eminovici', 'Mihai', 4, 3, 3),
	   ('Marina', 'Cozma', 4, 3, 6),
	   ('Costela', 'Diaconu', 4, 3, 9)

INSERT INTO Clienti(Nume)
VALUES ('Ion Paval'),
       ('Georgiana Mihaiela'),
	   ('Ioana Toma'),
	   ('Alexandru Oprea'),
	   ('George Bartos')

INSERT INTO Comenzi(idClient, idAngajatRaspunzator)
VALUES (1,1), (2, 1), (3, 12), (4, 13), (5, 14)
	   