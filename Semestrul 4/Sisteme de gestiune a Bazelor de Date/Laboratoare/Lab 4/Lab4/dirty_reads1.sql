BEGIN TRANSACTION 
UPDATE Produse SET Pret = 100 where idProdus=1
WAITFOR DELAY '00:00:05'
ROLLBACK TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) 
VALUES ('DirtyReads rollback', CURRENT_TIMESTAMP, 'rollback')

SELECT * FROM Produse