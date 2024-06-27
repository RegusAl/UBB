CREATE DATABASE Practic

GO
USE Practic
GO

create table Muzee(
Mid int primary key identity,
Denumire varchar(50),
TipMuzeu varchar(50),
AnDeschidere int,
NrExponate int)

create table Pictori(
Pid int primary key identity,
Nume varchar(50),
Prenume varchar(50),
Gen varchar(50),
Perioada varchar(50),
AnNastere int)

create table Tablouri(
Tid int primary key identity,
Denumire varchar(50),
AnPictura int,
Dimensiune varchar(30),
Pid int foreign key references Pictori(Pid),
Mid int foreign key references Muzee(Mid))

create table Orase(
Oid int primary key identity,
Nume varchar(50),
AnDatare int,
Tara varchar(50))

create table Locatii(
Pid int foreign key references Pictori(Pid),
Oid int foreign key references Orase(Oid),
AnLocatieInceput int,
NrAni int,
constraint pk_Locatii primary key(Pid, Oid))

-- 1-n: Pictori-Tablouri

select * from Muzee
select * from Pictori
select * from Tablouri
select * from Orase
select * from Locatii

insert into Muzee values('Van Gog', 'muzeu cu picturi', 1958, 250),
('Bruckental', 'muzeu cu picturi si sculpturi', 1990, 127)

insert into Pictori values('Almasan', 'Alin', 'masculin', 'Renascentista', 1930),
('Florian', 'Popa', 'masculin', 'Gothic', 1845)

insert into Tablouri values('Fresca de vara', 1946, '40*60', 1, 1), 
('Abstract de seara', 1867, '30*20', 2, 1)

insert into Orase values('Paris', 1359, 'Franta'), ('Sibiu', 1792, 'Romania')

insert into Locatii values(1, 1, 1930, 5), (1, 2, 1935, 3)