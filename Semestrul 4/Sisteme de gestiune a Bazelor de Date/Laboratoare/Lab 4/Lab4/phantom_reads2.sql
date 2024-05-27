BEGIN TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Delay for insert started')
WAITFOR DELAY '00:00:05'
INSERT INTO Produse(Nume, Stoc, Pret) VALUES ('Aaa', 112, 987);
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Inserted')
COMMIT TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Insert rollback ended')


SELECT * FROM Produse