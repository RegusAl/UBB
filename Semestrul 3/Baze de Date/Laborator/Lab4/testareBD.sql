-- populare TABELE

INSERT INTO Tables( Name) VALUES
('Categorie'), ('Produse'), ('ProduseDepozite'); 

SELECT * FROM Tables


-- creare VIEW-uri

CREATE OR ALTER VIEW VCategorie AS
	SELECT c.Nume AS NumeCategorie, p.Nume AS NumeProdus, p.Stoc, p.Pret, f.Nume AS NumeFurnizor
	FROM Produse p 
	JOIN Categorie c ON c.idCategorie = p.idCategorie
	JOIN Furnizori f ON f.idFurnizor = p.idFurnizor
GO

CREATE OR ALTER VIEW VProduse AS
	SELECT Nume, Pret, Stoc 
	FROM Produse
GO

CREATE OR ALTER VIEW VProduseDepozite AS
	SELECT c.Nume AS NumeCategorie, Count(*) AS NumarProduse
	FROM Categorie c
	JOIN Produse p ON p.idCategorie = c.idCategorie
	GROUP BY c.Nume
GO

SELECT * FROM VCategorie

SELECT * FROM VProduse

SELECT * FROM VProduseDepozite


-- inserare in Tabela VIEWS

INSERT INTO Views VALUES ('VCategorie'), ('VProduse'), ('VProduseDepozite');
SELECT * FROM Views

-- inserare in Tabela Tests

INSERT INTO Tests(Name) 
VALUES ('insert_table_10'),
       ('insert_table_100'),
	   ('insert_table_1000'),
	   ('delete_table_10'),
	   ('delete_table_100'),
	   ('delete_table_1000'),
	   ('select_view')
GO

SELECT * FROM Tests

-- inserare in Tabela TestViews

INSERT INTO TestViews(TestID, ViewID) 
VALUES (7, 1), (7, 2), (7, 3)
GO

SELECT * FROM TestViews

-- inserare in tabela TestTables
INSERT INTO TestTables VALUES
(1, 1, 10, 1),
(2, 1, 100, 1),
(3, 1, 1000, 1),
(1, 2, 10, 2),
(2, 2, 100, 2),
(3, 2, 1000, 2),
(1, 3, 10, 3),
(2, 3, 100, 3),
(3, 3, 1000, 3),

(4, 1, 10, 3),
(5, 1, 100, 3),
(6, 1, 1000, 3),
(4, 2, 10, 2),
(5, 2, 100, 2),
(6, 2, 1000, 2),
(4, 3, 10, 1),
(5, 3, 100, 1),
(6, 3, 1000, 1)
GO


-- inserare tabela Categorie
CREATE OR ALTER PROCEDURE InsertCategorie (@rows int)
AS
BEGIN
	DECLARE @id int
	DECLARE @nume VARCHAR(50)
	DECLARE @i int
	DECLARE @lastId int
	SET @nume = 'nume_categorie'
	SET @id = 1000
	SET @i = 1
	
	SET IDENTITY_INSERT Categorie ON;

	WHILE @i <= @rows
	BEGIN
		SET @id = 1000 + @i
		SELECT TOP 1 @lastId =  Categorie.idCategorie FROM dbo.Categorie ORDER BY Categorie.idCategorie DESC
		IF @lastId > 2000
			SET @id = @lastId + 1
		INSERT INTO Categorie(idCategorie, Nume) VALUES (@id, @nume)
		SET @i = @i + 1
	END

	SET IDENTITY_INSERT Categorie OFF;

END
GO

-- stergere din tabela Categorie
CREATE OR ALTER PROCEDURE DeleteCategorie (@rows int)
AS
BEGIN
	DECLARE @id int
	DECLARE @i int
	DECLARE @lastId int
	SET @id = 1000
	SET @i = @rows

	WHILE @i > 0
	BEGIN 
		SET @id = 1000 + @i
		SELECT TOP 1 @lastId = Categorie.idCategorie FROM dbo.Categorie ORDER BY Categorie.idCategorie DESC
		IF @lastId > @id
			SET @id = @lastId
		DELETE FROM Categorie WHERE Categorie.idCategorie = @id
		SET @i = @i - 1
	END
END
GO

-- exec InsertCategorie 10
-- exec DeleteCategorie 10

-- SELECT * FROM Categorie


-- inserare in tabela Produse
CREATE OR ALTER PROCEDURE InsertProduse (@rows int)
AS
BEGIN
	DECLARE @id int
	DECLARE @nume VARCHAR(50)
	DECLARE @i int
	DECLARE @lastId int

	DECLARE @fkFurnizor int
	DECLARE @fkCategorie int

	SET @nume = 'nume_produs'
	SET @id = 1000
	SET @i = 1

	SET IDENTITY_INSERT Produse ON;

	WHILE @i <= @rows
	BEGIN
		SET @id = 1000+@i
		SELECT TOP 1 @lastId = Produse.idProdus FROM dbo.Produse ORDER BY Produse.idProdus DESC
		IF @lastId > 1000
			SET @id = @lastId + 1
		SELECT TOP 1 @fkFurnizor = Furnizori.idFurnizor FROM dbo.Furnizori ORDER BY NEWID()
		SELECT TOP 1 @fkCategorie = Categorie.idCategorie FROM dbo.Categorie ORDER BY NEWID()

		INSERT INTO Produse(idProdus, Nume, Pret, Stoc, idFurnizor, idCategorie) VALUES (@id, @nume, 111, 1, @fkFurnizor, @fkCategorie)
		SET @i = @i + 1
	END

	SET IDENTITY_INSERT Produse OFF;

END
GO

-- stergere din tabela Produse
CREATE OR ALTER PROCEDURE DeleteProduse (@rows int)
AS
BEGIN
	DECLARE @id int
	DECLARE @i int
	DECLARE @lastId int

	SET @id = 1000
	SET @i = @rows

	WHILE @i > 0
	BEGIN
		SET @id = 1000 + @i
		SELECT TOP 1 @lastId = Produse.idProdus FROM dbo.Produse ORDER BY Produse.idProdus DESC
		IF @lastId > @id
			SET @id = @lastId
		DELETE FROM Produse WHERE Produse.idProdus = @id 
		SET @i = @i - 1
	END
END
GO
 
-- exec InsertProduse 10
-- exec DeleteProduse 10

-- SELECT * FROM Produse


-- inserare in tabela ProduseDepozite
CREATE OR ALTER PROCEDURE InsertProduseDepozite (@rows int)
AS
BEGIN
	DECLARE @i int
	SET @i = @rows


	exec insertProduse @rows
	
	DECLARE @idP int, @nume varchar(50)
	DECLARE cursorProduse CURSOR SCROLL FOR
	SELECT idProdus, Nume FROM Produse;
	OPEN cursorProduse;
	FETCH LAST FROM cursorProduse INTO @idP, @nume;

	WHILE @i > 0 AND @@FETCH_STATUS = 0
	BEGIN
		INSERT INTO ProduseDepozite(idProdus, idDepozit) VALUES (@idP, 1)
		FETCH PRIOR FROM cursorProduse INTO @idP, @nume
		SET @i = @i - 1
	END

	CLOSE cursorProduse
	DEALLOCATE cursorProduse

END
GO

-- stergere din tabel ProduseDepozite
CREATE OR ALTER PROCEDURE DeleteProduseDepozite (@rows int)
AS
BEGIN
	DECLARE @idP int
	DECLARE @idD int
	DECLARE @i int

	SET @i = @rows
	SET @idD = 1

	WHILE @i > 0
	BEGIN
		SELECT TOP 1 @idP = Produse.idProdus FROM dbo.Produse ORDER BY Produse.idProdus DESC
		IF @idP > 1000
		BEGIN
			DELETE FROM ProduseDepozite WHERE ProduseDepozite.idDepozit = @idD AND ProduseDepozite.idProdus = @idP
			exec DeleteProduse 1
		END
		SET @i = @i - 1
	END
END
GO


-- inserarile
CREATE OR ALTER PROCEDURE insert_table_10 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec InsertProduse 10
	IF @Tabela='Categorie'
	exec InsertCategorie 10
	IF @Tabela='ProduseDepozite'
	exec InsertProduseDepozite 10
	else PRINT 'Nume invalid'
END
GO

CREATE OR ALTER PROCEDURE insert_table_100 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec InsertProduse 100
	IF @Tabela='Categorie'
	exec InsertCategorie 100
	IF @Tabela='ProduseDepozite'
	exec InsertProduseDepozite 100
	else PRINT 'Nume invalid'
END
GO

CREATE OR ALTER PROCEDURE insert_table_1000 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec InsertProduse 1000
	IF @Tabela='Categorie'
	exec InsertCategorie 1000
	IF @Tabela='ProduseDepozite'
	exec InsertProduseDepozite 1000
	else PRINT 'Nume invalid'
END
GO

-- stergeri
CREATE OR ALTER PROCEDURE delete_table_10 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec DeleteProduse 10
	IF @Tabela='Categorie'
	exec DeleteCategorie 10
	IF @Tabela='ProduseDepozite'
	exec DeleteProduseDepozite 10
	else PRINT 'Nume invalid'
END
GO

CREATE OR ALTER PROCEDURE delete_table_100 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec DeleteProduse 100
	IF @Tabela='Categorie'
	exec DeleteCategorie 100
	IF @Tabela='ProduseDepozite'
	exec DeleteProduseDepozite 100
	else PRINT 'Nume invalid'
END
GO

CREATE OR ALTER PROCEDURE delete_table_1000 (@Tabela VARCHAR(20))
AS
BEGIN
	IF @Tabela='Produse'
	exec DeleteProduse 1000
	IF @Tabela='Categorie'
	exec DeleteCategorie 1000
	IF @Tabela='ProduseDepozite'
	exec DeleteProduseDepozite 1000
	else PRINT 'Nume invalid'
END
GO

-- view
CREATE OR ALTER PROCEDURE Evaluare (@View VARCHAR(20))
AS
BEGIN
	IF @View='VCategorie'
	select * from View1
	IF @View='VProduse'
	select * from View2
	IF @View='VProduseDepozite'
	select * from View3
	else PRINT 'Nume invalid'
END
GO

-- main
CREATE OR ALTER PROCEDURE main (@Tabela VARCHAR(20), @rows int)
AS
BEGIN
	DECLARE @t1 datetime, @t2 datetime, @t3 datetime
	DECLARE @desc VARCHAR(2000)

	DECLARE @testInserare VARCHAR(20)
	DECLARE @testSterge VARCHAR(20)
	DECLARE @nrRows int
	DECLARE @idTest int

	DECLARE @id_table int
	SELECT @id_table = Tables.TableID FROM Tables WHERE Tables.Name = @Tabela

	DECLARE @id_view int
	SELECT @id_view = Views.ViewID FROM Views WHERE Views.Name = 'V'+@Tabela

	SET @testInserare = 'insert_table_' + CONVERT(VARCHAR(10),@rows)
	SET @testSterge = 'delete_table_' + CONVERT(VARCHAR(10),@rows)

		SET @t1 = GETDATE()
		exec @testInserare @Tabela
		exec @testSterge @Tabela
		SET @t2 = GETDATE()
		exec Evaluare @Tabela
		SET @t3 = GETDATE()
		SET @desc = @testInserare+' - '+@testSterge+' - '+@Tabela
		INSERT INTO TestRuns VALUES (@desc, @t1, @t2)
		SELECT TOP 1 @idTest=T.TestRunID FROM dbo.TestRuns T ORDER BY T.TestRunID DESC
		INSERT INTO TestRunTables VALUES (@idTest,@id_table,@t1,@t2)
		INSERT INTO TestRunViews VALUES (@idTest,@id_view,@t2,@t3)

/*
	if @Tabela='Categorie'
	BEGIN
		SET @t1 = GETDATE()
		exec @testInserare Categorie
		exec @testSterge Categorie
		SET @t2 = GETDATE()
		exec Evaluare View1
		SET @t3 = GETDATE()
		SET @desc = N'Testul s-a facut '+@testInserare+', '+@testSterge+', '+@Tabela
		INSERT INTO TestRuns VALUES (@desc, @t1, @t2)
		SELECT TOP 1 @idTest=T.TestRunID FROM dbo.TestRuns T ORDER BY T.TestRunID DESC
		INSERT INTO TestRunTables VALUES (@idTest,1,@t1,@t2)
		INSERT INTO TestRunViews VALUES (@idTest,1,@t2,@t3)
	END

	if @Tabela='ProduseDepozite'
	BEGIN
		SET @t1 = GETDATE()
		exec @testInserare ProduseDepozite
		exec @testSterge ProduseDepozite
		SET @t2 = GETDATE()
		exec Evaluare View2
		SET @t3 = GETDATE()
		SET @desc = N'Testul s-a facut '+@testInserare+', '+@testSterge+', '+@Tabela
		INSERT INTO TestRuns VALUES (@desc, @t1, @t2)
		SELECT TOP 1 @idTest=T.TestRunID FROM dbo.TestRuns T ORDER BY T.TestRunID DESC
		INSERT INTO TestRunTables VALUES (@idTest,1,@t1,@t2)
		INSERT INTO TestRunViews VALUES (@idTest,1,@t2,@t3)
	END

	if @Tabela='Produse'
	BEGIN
		SET @t1 = GETDATE()
		exec @testInserare Produse
		exec @testSterge Produse
		SET @t2 = GETDATE()
		exec Evaluare View3
		SET @t3 = GETDATE()
		SET @desc = N'Testul s-a facut '+@testInserare+', '+@testSterge+', '+@Tabela
		INSERT INTO TestRuns VALUES (@desc, @t1, @t2)
		SELECT TOP 1 @idTest=T.TestRunID FROM dbo.TestRuns T ORDER BY T.TestRunID DESC
		INSERT INTO TestRunTables VALUES (@idTest,1,@t1,@t2)
		INSERT INTO TestRunViews VALUES (@idTest,1,@t2,@t3)
	END
	ELSE PRINT 'INVALID'
	*/

END

exec main @Tabela = Categorie, @rows = 10
exec main @Tabela = Produse, @rows = 10
exec main @Tabela = ProduseDepozite, @rows = 10

exec main @Tabela = Categorie, @rows = 100
exec main @Tabela = Produse, @rows = 100
exec main @Tabela = ProduseDepozite, @rows = 100

exec main @Tabela = Categorie, @rows = 1000
exec main @Tabela = Produse, @rows = 1000
exec main @Tabela = ProduseDepozite, @rows = 1000


select * from TestRuns
select * from TestRunTables
select * from TestRunViews


SELECT * FROM Categorie
SELECT * FROM Produse
SELECT * FROM ProduseDepozite


exec InsertProduse 10
exec DeleteProduse 10
SELECT * FROM Produse


exec InsertCategorie 10
exec DeleteCategorie 10
SELECT * FROM Categorie


exec InsertProduseDepozite 10
exec DeleteProduseDepozite 10
SELECT * FROM ProduseDepozite



DROP TABLE TestRunViews
DROP TABLE TestRunTables
DROP TABLE TestRuns 
DROP TABLE TestTables
DROP TABLE TestViews
DROP TABLE Tests
DROP TABLE Tables
DROP TABLE Views