USE MagazinSportiv
GO
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

-- VERIFICARI

-- verificare Tabela Clienti
CREATE OR ALTER PROCEDURE verificareClienti
	@flag BIT OUTPUT,
	@mesaj VARCHAR(50) OUTPUT,
	@nume VARCHAR,
	@rows INT
	AS
	BEGIN
		DECLARE @suma INT;
		SET @flag = 0;
		SET @mesaj = '';
		SET @suma = 0;
		if dbo.validareRows(@rows) = 0
			SET @mesaj = @mesaj + ' | nr randuri invalide |';
		if dbo.validareString(@nume) = 0
			SET @mesaj = @mesaj + ' | nume invalid |';
		SET @suma = @suma + dbo.validareRows(@rows) + dbo.validareString(@nume);
	IF @suma = 2
		SET @flag = 1;
END
GO

-- verificare Tabela Depozite
CREATE OR ALTER PROCEDURE verificareDepozite
	@flag BIT OUTPUT,
	@mesaj VARCHAR(50) OUTPUT,
	@nume VARCHAR(50),
	@localitate VARCHAR(50),
	@rows INT
	AS
	BEGIN
		DECLARE @suma INT;
		SET @flag = 0;
		SET @mesaj = '';
		SET @suma = 0;
		IF dbo.validareString(@nume) = 0
			SET @mesaj = @mesaj + ' | nume invalid | ';
		IF dbo.validareString(@localitate) = 0
			SET @mesaj = @mesaj + ' | localitate invalida | ';
		SET @suma = @suma + dbo.validareString(@nume) + dbo.validareString(@localitate);
	IF @suma = 2
		SET @flag = 1
END
GO


-- verificare Tabela Produse
CREATE OR ALTER PROCEDURE verificareProdus
	@flag BIT OUTPUT,
	@mesaj VARCHAR(50) OUTPUT,
	@nume VARCHAR(50),
	@pret INT,
	@stoc INT,
	@idF INT,
	@idC INT,
	@rows INT
AS
BEGIN
	DECLARE @suma INT;
	SET @flag = 0;
	SET @mesaj = '';
	SET @suma = 0;
	IF dbo.validareString(@nume) = 0
		SET @mesaj = @mesaj + ' | nume invalid | ';
	IF dbo.validareRows(@rows) = 0
		SET @mesaj = @mesaj + ' | nr de randuri invalide | ';
	IF dbo.validareIdFurnizor (@idF) = 0
		SET @mesaj = @mesaj + ' | id furnizori invalid | ';
	IF dbo.validareIdCategorie (@idC) = 0
		SET @mesaj = @mesaj + ' | id categorie invalid | ';
	SET @suma = @suma + dbo.validareString(@nume) + dbo.validareRows(@rows) + dbo.validareIdFurnizor(@idF) + dbo.validareIdCategorie(@idC);
	IF @suma = 4
		SET @flag = 1;
END
GO

CREATE OR ALTER PROCEDURE verificarePD 
	@flag BIT OUTPUT,
	@mesaj VARCHAR(50) OUTPUT,
	@idP INT,
	@idD INT
AS
BEGIN
	DECLARE @suma INT;
	SET @flag = 0;
	SET @mesaj = '';
	SET @suma = 0;
	IF dbo.validareIdProdus (@idP) = 0
		SET @mesaj = @mesaj + ' | id produs invalid | ';
	IF dbo.validareIdDepozit (@idD) = 0
		SET @mesaj = @mesaj + ' | id depozit invalid | ';
	SET @suma = @suma + dbo.validareIdProdus (@idP) + dbo.validareIdDepozit (@idD);
	IF @suma = 2
		SET @flag = 1;
END
GO


--- Operatii CRUD

-- Tabela Clienti
CREATE OR ALTER PROCEDURE CRUD_Clienti
	@nume VARCHAR(50),
	@rows INT
	AS
	BEGIN
		SET NOCOUNT ON;

		DECLARE @idClient INT;
		DECLARE @mesaj VARCHAR(50);
		DECLARE @i INT;
		DECLARE @flag BIT;
		
		SET @i = 1;
		
		SELECT TOP 1 @idClient = idClient FROM Clienti ORDER BY idClient DESC;

		exec verificareClienti @flag OUTPUT, @mesaj OUTPUT, @nume, @rows;

		IF @flag = 0
			print 'Eroare: ' + @mesaj;
		ELSE
		BEGIN
			SET IDENTITY_INSERT Clienti ON;

			-- INSERT
			WHILE @i <= @rows
			BEGIN
				SET @idClient = @idClient + 1;
				INSERT INTO Clienti(idClient, Nume) VALUES (@idClient, @nume);
				SET @i = @i + 1;
				print 'Clientul ' + @nume + ' a fost adaugat cu succes!';
			END
			SET IDENTITY_INSERT Clienti OFF;

			-- SELECT
			SELECT * FROM Clienti;

			-- UPDATE
			UPDATE Clienti SET Nume='toDelete' WHERE idClient > 5;

			-- DELETE
			DELETE Clienti WHERE Nume='toDelete';

			print 'S-au efectuat operatiile CRUD pe tabela CLienti';
		END
	END
GO

-- Tabela Produse
CREATE OR ALTER PROCEDURE CRUD_Produse
	@nume VARCHAR(50),
	@pret INT,
	@stoc INT,
	@idF INT,
	@idC INT,
	@rows INT
AS
BEGIN
	SET NOCOUNT ON;

	DECLARE @flag BIT;
	DECLARE @mesaj VARCHAR(30);
	DECLARE @i INT;
	DECLARE @idProdus INT;

	SET @i = 1;
	SELECT TOP 1 @idProdus = idProdus FROM Produse ORDER BY idProdus DESC;

	EXEC verificareProdus @flag OUTPUT, @mesaj OUTPUT, @nume, @pret, @stoc, @idF, @idC, @rows;

	IF @flag = 0
		PRINT 'Eroare: ' + @mesaj;
	ELSE
		BEGIN
			
			SET IDENTITY_INSERT Produse ON;

			-- INSERT
			WHILE @i <= @rows
			BEGIN
				SET @idProdus = @idProdus + 1;
				INSERT INTO Produse(idProdus, Nume, Pret, Stoc, idFurnizor, idCategorie) VALUES (@idProdus, @nume, @pret, @stoc, @idF, @idC);
				SET @i = @i + 1;
			END

			SET IDENTITY_INSERT Produse OFF;


			-- SELECT
			SELECT * FROM Produse;

			-- UPDATE
			UPDATE Produse SET Nume = 'toDelete' WHERE idProdus > 100;

			-- DELETE
			DELETE Produse WHERE Nume = 'toDelete';	
		END
END
GO

-- Tabela Depozite
CREATE OR ALTER PROCEDURE CRUD_Depozite
	@localitate VARCHAR(50),
	@nume VARCHAR(50),
	@rows INT
AS
BEGIN
	SET NOCOUNT ON;

	DECLARE @i INT;
	DECLARE @idDepozit INT;
	DECLARE @flag BIT;
	DECLARE @mesaj VARCHAR(50);

	SELECT TOP 1 @idDepozit = idDepozit FROM Depozite ORDER BY idDepozit DESC;
	SET @i = 1;

	EXEC verificareDepozite @flag OUTPUT, @mesaj OUTPUT, @localitate, @nume, @rows;

	IF @flag = 0
		print 'Eroare: ' + @mesaj;
	ELSE
		BEGIN
			
			SET IDENTITY_INSERT Depozite ON;

			-- INSERT
			WHILE @i <= @rows
			BEGIN
				SET @idDepozit = @idDepozit + 1;
				INSERT INTO Depozite(idDepozit, Localitate, Nume) VALUES (@idDepozit, @localitate, @nume);
				SET @i = @i + 1;
			END

			SET IDENTITY_INSERT Depozite OFF;

			-- SELECT
			SELECT * FROM Depozite;

			-- UPDATE
			UPDATE Depozite set Nume = 'toDelete' WHERE Localitate = 'Buzau';

			-- Delete
			DELETE Depozite WHERE Nume = 'toDelete';

		END
	END
GO

-- Tabela ProduseDepozite
CREATE OR ALTER PROCEDURE CRUD_PD
	@idP INT,
	@idD INT
AS
BEGIN
	SET NOCOUNT ON;

	DECLARE @flag BIT;
	DECLARE @mesaj VARCHAR(50);

	EXEC verificarePD @flag OUTPUT, @mesaj OUTPUT, @idP, @idD;

	IF @flag = 0
		PRINT 'Eroare: ' + @mesaj;
	ELSE
		BEGIN

			-- INSERT
			INSERT INTO ProduseDepozite(idProdus, idDepozit) VALUES (@idP, @idD);

			-- SELECT
			SELECT * FROM ProduseDepozite;

			-- DELETE
			DELETE ProduseDepozite WHERE @idP = idProdus AND @idD = idDepozit;
		END
END
GO


CREATE OR ALTER PROCEDURE CRUD_MAIN
AS
BEGIN
	exec CRUD_Clienti 'Mihai', 1;
	exec CRUD_Produse 'minge', 99, 2, 1, 2, 1;
	exec CRUD_Depozite 'Buzau', 'qwerty', 1;
	exec CRUD_PD 25, 2
END
GO

exec CRUD_MAIN

SELECT * FROM Clienti
SELECT * FROM Produse
SELECT * FROM Depozite
SELECT * FROM ProduseDepozite
