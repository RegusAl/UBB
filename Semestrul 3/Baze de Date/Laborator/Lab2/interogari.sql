USE MagazinSportiv


-- 1) Produsele impreuna cu furnizorii ce fac parte din categoria 'Alergare'
SELECT p.Nume, p.Pret, p.Stoc, f.Nume AS Furnizor, f.Locatie
FROM Furnizori f INNER JOIN Produse p ON f.idFurnizor = p.idFurnizor
WHERE p.idCategorie IN (SELECT c.idCategorie FROM Categorie c WHERE c.Nume = 'Alergare')


-- 2) Furnizorii si numarul produselor de alergare 
SELECT f.Nume, f.Locatie, COUNT(*) AS Numar_Produse_Alergare
FROM Furnizori f INNER JOIN Produse p ON f.idFurnizor = p.idFurnizor
WHERE p.idCategorie IN (SELECT c.idCategorie FROM Categorie c WHERE c.Nume = 'Alergare')
GROUP BY f.Nume, f.Locatie


-- 3) Departamentele de angajati cu mai mult de 5 persoane
SELECT d.Nume, Count(*) AS Numar_Angajati
FROM Departamente d
INNER JOIN Angajati a
ON d.idDepartament = a.Departament
GROUP BY d.Nume HAVING COUNT(*)>5

-- 4) Depozitele ce au mai mult de 5 angajati cu vechime >= de 5 ani
SELECT d.Nume, d.Localitate, COUNT(*) AS Nr_Angajati
FROM Angajati a
INNER JOIN Departamente dep
ON a.Departament = dep.idDepartament
INNER JOIN Depozite d
ON a.Depozit = d.idDepozit
WHERE a.Vechime >= 5
GROUP BY d.Nume, d.Localitate HAVING COUNT(*) > 5 


-- 5) Managerii ce au mai mult de 2 produse in depozit
SELECT m.Nume, d.Nume as Nume_Depozit, COUNT(*) AS Nr_produse
FROM Manageri m
INNER JOIN Depozite d
ON m.idManager = d.idDepozit
INNER JOIN ProduseDepozite pd
ON d.idDepozit = pd.idDepozit
INNER JOIN Produse p
ON pd.idProdus = p.idProdus
GROUP BY m.Nume, d.Nume HAVING COUNT(*) > 2

-- 6) Depozitele cu produse de alergat de peste 500 de lei
SELECT DISTINCT d.Nume, d.Localitate
FROM Depozite d
INNER JOIN ProduseDepozite pd
ON d.idDepozit = pd.idDepozit
INNER JOIN Produse p
ON pd.idProdus = p.idProdus
WHERE p.Pret >= 500

-- 7) Departamentele si numarul de angajati din Depozitul 'Cluj-Napoca'
SELECT d.Nume, COUNT(a.Nume) as Nr_Angajati 
FROM Departamente d
RIGHT OUTER JOIN Angajati a
ON d.idDepartament = a.Departament
RIGHT OUTER JOIN Depozite dep
ON a.Depozit = dep.idDepozit
WHERE dep.Localitate = 'Cluj-Napoca'
GROUP BY d.Nume

-- 8) Departamentul ce preia comenzile clientilor din Suceava
SELECT DISTINCT dep.Nume
FROM Departamente dep
RIGHT OUTER JOIN Angajati a
ON dep.idDepartament = a.Departament
RIGHT OUTER JOIN Comenzi c
ON a.idAngajat = c.idAngajatRaspunzator
RIGHT OUTER JOIN Depozite d
ON a.Depozit = d.idDepozit
WHERE d.Localitate = 'Suceava'

-- 9) Clientii ce au comanda pregatita de angajati cu vechime de peste 3 ani
SELECT c.Nume
FROM Clienti c
RIGHT OUTER JOIN Comenzi com
ON c.idClient = com.idClient
INNER JOIN Angajati a
ON com.idAngajatRaspunzator = a.idAngajat
WHERE a.Vechime > 3

-- 10) Toate departamentele din fiecare depozit
SELECT DISTINCT dep.Nume AS Nume_Depozit, dep.Localitate, d.Nume AS Nume_Departament
FROM Departamente d
RIGHT OUTER JOIN Angajati a
ON d.idDepartament = a.Departament
RIGHT OUTER JOIN Depozite dep
ON a.Depozit = dep.idDepozit