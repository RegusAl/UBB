USE MagazinSportiv
GO


-- validare numar randuri
CREATE OR ALTER FUNCTION dbo.validareRows (@rows INT) RETURNS BIT
AS
BEGIN
	DECLARE @flag BIT;
	SET @flag = 0;
	IF @rows >= 0
		SET @flag = 1;
	RETURN @flag;
END
GO

-- validare string
CREATE OR ALTER FUNCTION dbo.validareString (@string VARCHAR(50)) RETURNS BIT
AS 
BEGIN
	DECLARE @flag BIT;
	SET @flag = 0;
	IF @string NOT LIKE '%[0-9]%' AND LEN(@string) >= 1
		SET @flag = 1;
	RETURN @flag;
END
GO

CREATE OR ALTER FUNCTION dbo.validareIdFurnizor (@idF INT) RETURNS BIT
AS
BEGIN
	DECLARE @start INT;
	DECLARE @end INT;
	DECLARE @flag BIT;
	SET @flag=0;

	SELECT TOP 1 @start = idFurnizor FROM Furnizori ORDER BY idFurnizor ASC;
	SELECT TOP 1 @end = idFurnizor FROM Furnizori ORDER BY idFurnizor DESC;
	if @idF between @start and @end 
		set @flag=1;
	return @flag;
END
GO

CREATE OR ALTER FUNCTION dbo.validareIdCategorie (@idC INT) RETURNS BIT
AS
BEGIN
	DECLARE @start INT;
	DECLARE @end INT;
	DECLARE @flag BIT;
	SET @flag=0;

	SELECT TOP 1 @start = idCategorie FROM Categorie ORDER BY idCategorie ASC;
	SELECT TOP 1 @end = idCategorie FROM Categorie ORDER BY idCategorie DESC;
	if @idC between @start and @end 
		set @flag=1;
	return @flag;
END
GO

CREATE OR ALTER FUNCTION dbo.validareIdProdus (@idP INT) RETURNS BIT
AS
BEGIN
	DECLARE @start INT;
	DECLARE @end INT;
	DECLARE @flag BIT;
	SET @flag=0;

	SELECT TOP 1 @start = idProdus FROM Produse ORDER BY idProdus ASC;
	SELECT TOP 1 @end = idProdus FROM Produse ORDER BY idProdus DESC;
	if @idP between @start and @end 
		set @flag=1;
	return @flag;
END
GO

CREATE OR ALTER FUNCTION dbo.validareIdDepozit (@idD INT) RETURNS BIT
AS
BEGIN
	DECLARE @start INT;
	DECLARE @end INT;
	DECLARE @flag BIT;
	SET @flag=0;

	SELECT TOP 1 @start = idDepozit FROM Depozite ORDER BY idDepozit ASC;
	SELECT TOP 1 @end = idDepozit FROM Depozite ORDER BY idDepozit DESC;
	if @idD between @start and @end 
		set @flag=1;
	return @flag;
END
GO