-- DO

-- DROP PROCEDURE do_proc_1
CREATE PROCEDURE do_proc_1 AS
ALTER TABLE Furnizori
ALTER COLUMN Nume VARCHAR(100)
PRINT 'S-a modificat coloana [Nume] din tabelul [Furnizori]'
GO

-- DROP PROCEDURE do_proc_2
CREATE PROCEDURE do_proc_2 AS
ALTER TABLE Produse
ADD CONSTRAINT stoc_min1 DEFAULT 1 FOR Stoc
PRINT 'S-a adaugat constrangere pentru coloana [Stoc] din tabelul [Produse]'
GO

-- DROP PROCEDURE do_proc_3
CREATE PROCEDURE do_proc_3 AS
CREATE TABLE ComenziFinalizate(
Cid int NOT NULL PRIMARY KEY,
Finalizat int NOT NULL
)
PRINT 'S-a creat un nou tabel [ComenziFinalizate]'
GO

-- DROP PROCEDURE do_proc_4
CREATE PROCEDURE do_proc_4 AS
ALTER TABLE ComenziFinalizate
ADD Data_comanda date
PRINT 'S-a adaugat un camp nou in tabela [ComenziFinalizate]'
GO

-- DROP PROCEDURE do_proc_5
CREATE PROCEDURE do_proc_5 AS
ALTER TABLE ComenziFinalizate
ADD CONSTRAINT CFid FOREIGN KEY(Cid) REFERENCES Comenzi(idComanda)
PRINT 'S-a adaugat cheie straina'
GO

-- UNDO

-- DROP PROCEDURE undo_proc_1
CREATE PROCEDURE undo_proc_1 AS
ALTER TABLE Furnizori
ALTER COLUMN Nume VARCHAR(50)
PRINT 'S-a remodificat coloana [Nume] din tabelul [Furnizori]'
GO

-- DROP PROCEDURE undo_proc_2
CREATE PROCEDURE undo_proc_2 AS
ALTER TABLE Produse
DROP CONSTRAINT stoc_min1
PRINT 'S-a eliminat constrangerea pentru coloana [Stoc] din tabelul [Produse]'
GO

-- DROP PROCEDURE undo_proc_3
CREATE PROCEDURE undo_proc_3 AS
DROP TABLE ComenziFinalizate
PRINT 'S-a sters tabelul [ComenziFinalizate]'
GO

-- DROP PROCEDURE undo_proc_4
CREATE PROCEDURE undo_proc_4 AS
ALTER TABLE ComenziFinalizate
DROP COLUMN Data_comanda
PRINT 'S-a eliminat coloana [Data_comanda]  din [ComenziFinalizate]'
GO

-- DROP PROCEDURE undo_proc_5
CREATE PROCEDURE undo_proc_5 AS
ALTER TABLE ComenziFinalizate
DROP CONSTRAINT CFid
PRINT 'S-a eliminat cheia straina'
GO

DROP TABLE IF EXISTS VersiuneDB
CREATE TABLE VersiuneDB (
	versionNo int
);

INSERT INTO VersiuneDB VALUES(0)


SELECT * FROM VersiuneDB

GO
CREATE OR ALTER PROCEDURE main @versiune INT
AS
BEGIN
		
		IF @versiune < 0 OR @versiune > 5
		BEGIN
			PRINT 'Versiunea este invalida!'
			RETURN
		END

		DECLARE @versiune_curenta AS INT
		SET @versiune_curenta = (SELECT versionNo FROM VersiuneDB)

		IF @versiune = @versiune_curenta
		BEGIN
			PRINT 'Versiunea actuala este deja cea curenta!'
			RETURN
		END

		DECLARE @proc VARCHAR(20)
		DECLARE @proc_undo VARCHAR(20)

		DECLARE @ok AS INT
		SET @ok = 0

		DELETE FROM VersiuneDB
		INSERT INTO VersiuneDB(versionNo) VALUES (@versiune)

		WHILE(@versiune_curenta < @versiune)
			BEGIN
				SET @ok = @ok + 1
				SET @versiune_curenta = @versiune_curenta + 1
				SET @proc = 'do_proc_' + CAST(@versiune_curenta AS VARCHAR(10))
				PRINT 'Se executa ' + @proc
				EXEC @proc
			END

		IF(@ok > 0)
		BEGIN
			RETURN
		END

		WHILE(@versiune_curenta > @versiune)
			BEGIN
				SET @proc_undo = 'undo_proc_' + CAST(@versiune_curenta AS VARCHAR(10))
				PRINT 'Se executa ' + @proc_undo
				EXEC @proc_undo
				SET @versiune_curenta = @versiune_curenta - 1
			END

END
GO


--exec do_proc_1     
--exec undo_proc_1   

--exec do_proc_2
--exec undo_proc_2

--exec do_proc_3
--exec undo_proc_3

--exec do_proc_4
--exec undo_proc_4

--exec do_proc_5
--exec undo_proc_5

exec main 0
exec main 1
exec main 2
exec main 3
exec main 4
exec main 5
