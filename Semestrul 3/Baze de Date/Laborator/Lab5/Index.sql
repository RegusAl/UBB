-- view Produse
CREATE OR ALTER VIEW ViewProduse
AS
	SELECT Nume, Stoc, Pret FROM Produse;
GO

IF EXISTS (SELECT NAME FROM sys.indexes WHERE NAME='N_idx_Produse_Nume_Stoc_PretN')
	DROP INDEX N_idx_Produse_Nume_Stoc_PretN ON Produse;
GO

CREATE NONCLUSTERED INDEX N_idx_Produse_Nume_Stoc_PretN ON Produse(Nume, Stoc, Pret);


SELECT * FROM ViewProduse ORDER BY Pret


-- view Clienti
CREATE OR ALTER VIEW ViewDepozite
AS
	SELECT Nume, Localitate FROM Depozite;
GO

IF EXISTS (SELECT NAME FROM sys.indexes WHERE NAME='N_idx_Depozite_Nume_LocalitateN')
	DROP INDEX N_idx_Depozite_Nume_LocalitateN ON Depozite;
GO

CREATE NONCLUSTERED INDEX N_idx_Depozite_Nume_LocalitateN ON Depozite(Nume, Localitate);

SELECT * FROM ViewDepozite ORDER BY Localitate