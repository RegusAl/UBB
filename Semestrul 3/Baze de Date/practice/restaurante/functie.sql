CREATE OR ALTER FUNCTION afisareUtilizator(@email VARCHAR(50))
	RETURNS TABLE AS 
		RETURN SELECT 
			U.nume,
			N.nota,
			R.nume AS 'Nume Restaurant',
			O.nume AS 'Oras',
			T.nume AS 'Tip Restaurant',
			@email AS 'email'
		FROM
			Utilizatori U
		JOIN Note N ON U.idUtilizator = N.idUtilizator
		JOIN Restaurante R ON N.idRestaurant = R.idRestaurant
		JOIN Orase O ON R.idOras = O.idOras
		JOIN Tipuri T ON R.idTip = T.idTip
		WHERE U.email = @email;

SELECT * FROM afisareUtilizator('alex@gmail.com')
SELECT * FROM afisareUtilizator('ana@gmail.com')
SELECT * FROM afisareUtilizator('maria1234@gmail.com')