BEGIN TRANSACTION
WAITFOR DELAY '00:00:03';
UPDATE Produse SET Stoc=11 WHERE Nume='exPrd';
INSERT INTO LogTable(actiune, data,mesaj) VALUES('stoc updated', CURRENT_TIMESTAMP, 'Delay for stoc update')
COMMIT TRANSACTION
INSERT INTO LogTable(actiune, data,mesaj) VALUES('stoc updated', CURRENT_TIMESTAMP, 'Update rollback ended')
