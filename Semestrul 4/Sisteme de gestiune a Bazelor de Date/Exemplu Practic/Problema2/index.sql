CREATE INDEX index_melodii ON Melodii(an_lansare DESC)

CREATE INDEX index_melodii_desc ON Melodii(an_lansare DESC)

SELECT * FROM Melodii

SELECT * FROM Melodii WHERE an_lansare > 2000