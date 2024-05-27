-- gresit
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRAN;
UPDATE Produse SET Stoc=5555 WHERE idProdus=1;
WAITFOR DELAY '00:00:05';
UPDATE Depozite SET Nume='lolo' WHERE  Localitate='Jucu';
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES('Deadlock', CURRENT_TIMESTAMP, 'Second transaction - succeeded')

-- corect
SET DEADLOCK_PRIORITY HIGH;
BEGIN TRANSACTION;
UPDATE Produse SET Stoc=5555 WHERE idProdus=1;
WAITFOR DELAY '00:00:05';
UPDATE Depozite SET Nume='lolo' WHERE  Localitate='Jucu';
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES('Deadlock', CURRENT_TIMESTAMP, 'Second transaction - succeeded')


GO
CREATE OR ALTER PROCEDURE run_thread1
AS
    BEGIN
        BEGIN TRANSACTION
        UPDATE Produse SET Pret=2000 WHERE Nume='Vesta';
        WAITFOR DELAY '00:00:10'
        UPDATE Depozite SET nume = nume + ' THR1' WHERE Localitate='Jucu';
        COMMIT TRANSACTION
    END

GO
CREATE OR ALTER PROCEDURE run_thread2
AS
    BEGIN
		SET DEADLOCK_PRIORITY HIGH
		-- SET DEADLOCK_PRIORITY LOW
        BEGIN TRANSACTION
        UPDATE Produse SET Pret=5555 WHERE Nume='Vesta';
        WAITFOR DELAY '00:00:10'
        UPDATE Depozite SET nume = nume + ' THR2' WHERE Localitate='Jucu';
        COMMIT TRANSACTION
    END