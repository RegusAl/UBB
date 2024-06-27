 CREATE INDEX index_nume_an ON Tablouri (AnPictura ASC , Denumire ASC)
 
 CREATE INDEX index_nume_oras ON Orase (Nume DESC)

 

 SELECT * FROM Orase ORDER BY  Nume

 SELECT * FROM Tablouri 

 SELECT * FROM Tablouri WHERE AnPictura > 1900

  SELECT * FROM Tablouri WHERE AnPictura = 1999

  SELECT * FROM Tablouri ORDER BY Denumire

  SELECT * FROM Tablouri ORDER BY AnPictura