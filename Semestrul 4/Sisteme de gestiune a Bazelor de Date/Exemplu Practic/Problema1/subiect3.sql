 CREATE INDEX index_pret_nume ON Briose (pret ASC , nume_briosa ASC)

CREATE INDEX index_nume_cofetarie ON Cofetarii(nume_cofetarie);



select * from Cofetarii

SELECT * FROM Cofetarii WHERE nume_cofetarie = 'Lemnul Verde';

SELECT nume_briosa , pret FROM Briose WHERE pret = 10

