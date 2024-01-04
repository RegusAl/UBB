CREATE OR ALTER PROCEDURE addNota
	@idRestaurant INT,
	@idUtilizator INT,
	@nota INT
	AS
	BEGIN
		IF EXISTS ( SELECT  * FROM Note WHERE @idRestaurant = idRestaurant AND @idUtilizator = idUtilizator)
		 BEGIN
			UPDATE Note
			SET nota = @nota WHERE @idRestaurant = idRestaurant AND @idUtilizator = idUtilizator
		 END
		ELSE
		 BEGIN
			INSERT INTO Note(idRestaurant, idUtilizator, nota) VALUES (@idRestaurant, @idUtilizator, @nota)
		 END
	END
GO

SELECT * FROM Note

exec addNota 1, 2, 3