SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRAN;
UPDATE Depozite SET Nume='TEst' WHERE  Localitate='Jucu';
WAITFOR DELAY '00:00:05';
UPDATE Produse SET Stoc=2222 WHERE idProdus=1;
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES ('Deadlock', CURRENT_TIMESTAMP, 'First transaction - victim')

SELECT * FROM Produse
SELECT * FROM Depozite