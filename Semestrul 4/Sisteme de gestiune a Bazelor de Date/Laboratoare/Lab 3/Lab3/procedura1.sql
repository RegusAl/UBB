USE MagazinSportiv
GO

-- DROP TABLE TabelaLogare

-- tabela de logare
CREATE TABLE TabelaLogare
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
CREATE OR ALTER FUNCTION validareDepozit
(@numeDepozit VARCHAR(50), 
 @localitateDepozit VARCHAR(50)
)
RETURNS VARCHAR(100)
AS
BEGIN

	DECLARE @mesajEroare VARCHAR(100)
	SET @mesajEroare = ''

	IF(@numeDepozit = '')
	SET @mesajEroare += 'Numele depozitului este incorect! '

	IF(@localitateDepozit = '')
	SET @mesajEroare += 'Localitatea depozitului este incorect! '

	RETURN @mesajEroare

END


-- procedura1
GO
CREATE OR ALTER PROCEDURE AddProduseDepozit @numeProdus varchar(50), @pretProdus float, @stocProdus int, @numeDepozit varchar(50), @localitateDepozit varchar(50)
AS
BEGIN
	
	BEGIN TRAN
		
		BEGIN TRY

			-- validari
			DECLARE @mesajEroare VARCHAR(100) = '';

			DECLARE @mesajEroareProdus VARCHAR(100) = dbo.validareProdus(@numeProdus, @pretProdus, @stocProdus)
			IF (@mesajEroareProdus <> '')
				SET @mesajEroare += @mesajEroareProdus + ' ';

			DECLARE @mesajEroareDepozit VARCHAR(100) = dbo.validareDepozit(@numeDepozit, @localitateDepozit);
			IF (@mesajEroareDepozit <> '')
				SET @mesajEroare += @mesajEroareDepozit;

			--print @mesajEroare
			--print @mesajEroareProdus

			IF (@mesajEroare <> '')
			BEGIN
				print @mesajEroare;
				INSERT INTO TabelaLogare(tip_actiune, tabel_operatie, data_executiei)
				VALUES ('Eroare', 'Produse', CURRENT_TIMESTAMP)
				RAISERROR (@mesajEroare, 14, 1);
			END

			DECLARE @idProdus INT
			DECLARE @idDepozit INT

			print 'inserare Produse'
			-- inserare in tabela Produse
			INSERT INTO Produse(Nume, Pret, Stoc) 
			VALUES (@numeProdus, @pretProdus, @stocProdus)
			SET @idProdus = SCOPE_IDENTITY()
	
			-- inserare in Logare
			INSERT INTO TabelaLogare(tip_actiune, tabel_operatie, data_executiei)
			VALUES ('Insert', 'Produse', CURRENT_TIMESTAMP)

			print 'inserare Depozite'
			-- inserare in tabela Depozite
			INSERT INTO Depozite(Nume, Localitate) 
			VALUES (@numeDepozit, @localitateDepozit)
			SET @idDepozit = SCOPE_IDENTITY()
	
			-- inserare in Logare
			INSERT INTO TabelaLogare(tip_actiune, tabel_operatie, data_executiei)
			VALUES ('Insert', 'Depozite', CURRENT_TIMESTAMP)

			print 'inserare ProduseDepozite'
			-- inserare in tabela de legatura ProduseDepozite
			INSERT INTO ProduseDepozite(idProdus, idDepozit) 
			VALUES (@idProdus, @idDepozit)

			-- inserare in Logare
			INSERT INTO TabelaLogare(tip_actiune, tabel_operatie, data_executiei)
			VALUES ('Insert', 'ProduseDepozite', CURRENT_TIMESTAMP)

			COMMIT TRAN
			SELECT 'Transaction commited'

		END TRY

	BEGIN CATCH
		ROLLBACK TRAN
		SELECT 'Transaction rollbacked'
		INSERT INTO TabelaLogare(tip_actiune, tabel_operatie, data_executiei)
		VALUES ('Rollback', 'All', CURRENT_TIMESTAMP)
	END CATCH

END

SELECT * FROM Produse
SELECT * FROM Depozite
SELECT * FROM ProduseDepozite

SELECT * FROM TabelaLogare

EXEC AddProduseDepozit 'test2', 90, 12, 'test_depozit2', 'Bucuresti'

EXEC AddProduseDepozit 'test_fail', -9, 50, 'test_proc_depozit', 'Cluj'
EXEC AddProduseDepozit 'test_fail', 12, -9, 'test_proc_depozit', 'Cluj'
EXEC AddProduseDepozit 'test_fail3', -12, -9, 'test_proc_depozit', 'Cluj'
EXEC AddProduseDepozit 'test_fail', 9, 50, 'test_proc_depozit', ''
EXEC AddProduseDepozit 'test_fail', 9, 50, '', 'ffff'

