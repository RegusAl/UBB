USE MagazinSportiv
GO

GO
CREATE OR ALTER FUNCTION validareProdus
(@numeProudus VARCHAR(50), 
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