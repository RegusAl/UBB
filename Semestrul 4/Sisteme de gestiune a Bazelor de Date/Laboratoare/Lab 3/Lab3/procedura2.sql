USE MagazinSportiv
GO

CREATE TABLE Logare
(
	id  INT PRIMARY KEY IDENTITY(1,1),
	tip_actiune VARCHAR(50),
	tabel_operatie VARCHAR(50),
	data_executiei DATETIME
)


GO
CREATE OR ALTER FUNCTION validareProdus
(@numeProdus VARCHAR(50), 
 @pretProdus FLOAT,
 @stocProdus INT)
RETURNS VARCHAR(100)
AS
BEGIN

	DECLARE @mesajEroare VARCHAR(100)
	SET @mesajEroare = ''

	IF(@pretProdus < 0)
	SET @mesajEroare += 'Pretul produsului este incorect! '

	IF(@stocProdus < 0)
	SET @mesajEroare += 'Stocul produsului este incorect! '

	RETURN @mesajEroare

END


GO
CREATE OR ALTER PROCEDURE AddProduseDepozitCorecte @numeProdus varchar(50), @pretProdus float, @stocProdus int, @numeDepozit varchar(50), @localitateDepozit varchar(50)
AS
BEGIN
	
	DECLARE @insertProdus INT = 0

	BEGIN TRAN
	BEGIN TRY

		DECLARE @mesajEroareProdus VARCHAR(100) = dbo.validareProdus(@numeProdus, @pretProdus, @stocProdus);
		IF (@mesajEroareProdus <> '')
		BEGIN
			RAISERROR(@mesajEroareProdus, 14, 1)
		END

		DECLARE @idProdus INT

		INSERT INTO Produse(Nume, Pret, Stoc)
		VALUES (@numeProdus, @pretProdus, @stocProdus)
		SET @idProdus = SCOPE_IDENTITY()

		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Insert', 'Produse', CURRENT_TIMESTAMP)
		
		
		COMMIT TRAN
		SELECT 'Transaction commited (Produse)'

		SET @insertProdus = @idProdus

	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		SELECT 'Transaction rollbacked (Produse)'
		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Rollback', 'Produse', CURRENT_TIMESTAMP)
	END CATCH


	DECLARE @insertDepozit INT = 0

	BEGIN TRAN
	BEGIN TRY

		DECLARE @idDepozit INT

		INSERT INTO Depozite(Nume, Localitate)
		VALUES (@numeDepozit, @localitateDepozit)
		SET @idDepozit = SCOPE_IDENTITY()

		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Insert', 'Depozit', CURRENT_TIMESTAMP)
		
		COMMIT TRAN
		SELECT 'Transaction commited (Depozit)'

		SET @insertDepozit = @idDepozit

	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		SELECT 'Transaction rollbacked (Depozit)'
		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Rollback', 'Depozit', CURRENT_TIMESTAMP)
	END CATCH


	BEGIN TRAN
	BEGIN TRY

		IF (@insertProdus = 0 OR @insertDepozit = 0)
		BEGIN
			RAISERROR('eroare', 14, 1)
		END

		INSERT INTO ProduseDepozite(idProdus, idDepozit)
		VALUES (@idProdus, @idDepozit)

		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Insert', 'ProduseDepozite', CURRENT_TIMESTAMP)

		COMMIT TRAN
		SELECT 'Transaction commited (ProduseDepozite)'

	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		SELECT 'Transaction rollbacked (ProduseDepozite)'
		INSERT INTO Logare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Rollback', 'ProduseDepozite', CURRENT_TIMESTAMP)
	END CATCH

END

SELECT * FROM Produse
SELECT * FROM Depozite
SELECT * FROM ProduseDepozite

SELECT * FROM Logare

EXEC AddProduseDepozitCorecte 'proc2_produs', 45, 45, 'depo', 'Jucu'

EXEC AddProduseDepozitCorecte 'produs_gresit', -56, 5, 'depo_bun', 'Ploiesti'