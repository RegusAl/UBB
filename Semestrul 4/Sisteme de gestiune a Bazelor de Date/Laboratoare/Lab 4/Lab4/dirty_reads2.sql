-- gresit
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
BEGIN TRAN
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after update')
WAITFOR DELAY '00:00:10'
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after Rollback')
COMMIT TRAN

-- corect
SET TRANSACTION ISOLATION LEVEL READ COMMITTED
BEGIN TRAN
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after update')
WAITFOR DELAY '00:00:10'
SELECT * FROM Produse;
INSERT INTO LogTable(actiune, data, mesaj) VALUES('SELECT Produse', CURRENT_TIMESTAMP, 'SELECT ALL from Produse after Rollback')
COMMIT TRAN