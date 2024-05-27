USE MagazinSportiv

ALTER TABLE LogTable

CREATE Table LogTable(
	ID INT PRIMARY KEY IDENTITY(1,1),
	actiune VARCHAR(50),
	data DATETIME,
	mesaj VARCHAR(50)
)


SELECT * FROM Produse


-- Dirty Reads

BEGIN TRANSACTION 
UPDATE Produse SET Pret = 100 where idProdus=1
WAITFOR DELAY '00:00:05'
ROLLBACK TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) 
VALUES ('DirtyReads rollback', CURRENT_TIMESTAMP, 'rollback')

SELECT * FROM Produse

SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
BEGIN TRAN
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after update')
WAITFOR DELAY '00:00:10'
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after Rollback')
COMMIT TRAN


SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRAN
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after update')
WAITFOR DELAY '00:00:10'
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after Rollback')
COMMIT TRAN

SELECT * FROM LogTable

-- Non-Repeatable Reads

SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRANSACTION
SELECT * FROM Produse;
WAITFOR DELAY '00:00:06'
SELECT * FROM Produse;
COMMIT TRANSACTION

BEGIN TRANSACTION
WAITFOR DELAY '00:00:03';
UPDATE Produse SET Stoc=999 WHERE Nume='exPrd';
INSERT INTO LogTable(actiune, data,mesaj) VALUES('stoc updated', CURRENT_TIMESTAMP, 'Delay for stoc update')
COMMIT TRANSACTION
INSERT INTO LogTable(actiune, data,mesaj) VALUES('stoc updated', CURRENT_TIMESTAMP, 'Update rollback ended')



-- Phantom Reads

-- gresit
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ
BEGIN TRANSACTION;
SELECT * FROM Produse WHERE idProdus BETWEEN 1 AND 100;
WAITFOR DELAY '00:00:07';
SELECT * FROM Produse WHERE idProdus BETWEEN 1 AND 100;
COMMIT TRAN;


SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
BEGIN TRANSACTION
SELECT * FROM Produse WHERE idProdus BETWEEN 1 AND 100;
WAITFOR DELAY '00:00:07'
SELECT * FROM Produse WHERE idProdus BETWEEN 1 AND 100;
COMMIT TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) VALUES('Phantom reads', CURRENT_TIMESTAMP, 'PR succeded')


BEGIN TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Delay for insert started')
WAITFOR DELAY '00:00:05'
INSERT INTO Produse(Nume, Stoc, Pret) VALUES ('Aaa', 112, 987);
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Inserted')
COMMIT TRANSACTION
INSERT INTO LogTable(actiune, data, mesaj) VALUES('PR Insert', CURRENT_TIMESTAMP, 'Insert rollback ended')



-- DeadLock

-- 1 --
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRAN;
UPDATE Depozite SET Nume='TEst' WHERE  Localitate='Jucu';
WAITFOR DELAY '00:00:05';
UPDATE Produse SET Stoc=2222 WHERE idProdus=1;
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES ('Deadlock', CURRENT_TIMESTAMP, 'First transaction - victim')


SELECT * FROM Depozite

-- 2-WRONG --
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRAN;
UPDATE Produse SET Stoc=2222 WHERE idProdus=1;
WAITFOR DELAY '00:00:05';
UPDATE Depozite SET Nume='TEst' WHERE  Localitate='Jucu';
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES('Deadlock', CURRENT_TIMESTAMP, 'Second transaction - succeeded')


-- 2-SOLUTION -- prin SET DEADLOCK_PRIORITY HIGH, tranzactia va avea prioritate mai mare la deadlock si nu va fi aleasa ca si victima, pe cand cea de-a doua tranzactie va esua.
SET DEADLOCK_PRIORITY HIGH;
BEGIN TRANSACTION;
UPDATE Produse SET Stoc=2222 WHERE idProdus=1;
WAITFOR DELAY '00:00:05';
UPDATE Depozite SET Nume='TEst' WHERE  Localitate='Jucu';
COMMIT TRAN;
INSERT INTO LogTable(actiune,data,mesaj) VALUES('Deadlock', CURRENT_TIMESTAMP, 'Second transaction - succeeded')

SELECT * FROM Produse
SELECT * FROM Depozite

-- threads

GO
CREATE OR ALTER PROCEDURE run_thread1
AS
    BEGIN
        BEGIN TRANSACTION
        UPDATE Produse SET Pret=2222 WHERE Nume='Vesta';
        WAITFOR DELAY '00:00:10'
        UPDATE Depozite SET nume = nume + ' THR1' WHERE Localitate='Jucu';
        COMMIT TRANSACTION
    END

GO
CREATE OR ALTER PROCEDURE run_thread2
AS
    BEGIN
		SET DEADLOCK_PRIORITY HIGH
		--SET DEADLOCK_PRIORITY LOW
        BEGIN TRANSACTION
        UPDATE Produse SET Pret=7777 WHERE Nume='Vesta';
        WAITFOR DELAY '00:00:10'
        UPDATE Depozite SET nume = nume + ' THR2' WHERE Localitate='Jucu';
        COMMIT TRANSACTION
    END


UPDATE Depozite SET nume = 'lol' WHERE Localitate='Jucu';
UPDATE Produse SET Pret=1 WHERE Nume='Vesta';


	SELECT * FROM Produse
	SELECT * FROM Depozite