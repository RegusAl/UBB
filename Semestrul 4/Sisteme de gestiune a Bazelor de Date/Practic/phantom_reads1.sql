BEGIN TRANSACTION
WAITFOR DELAY '00:00:05'
INSERT INTO Orase(Nume, AnDatare, Tara) VALUES ('Oradea', 1000, 'Romania');
COMMIT TRANSACTION


SELECT * FROM Orase