CREATE DATABASE SGBD_Problema3

GO 
USE SGBD_Problema3
GO

create table TipuriInghetate(
Tid int primary key identity,
Tip varchar(50),
Descriere varchar(50),
NrSortimente int)

create table Inghetate(
Iid int primary key identity,
Denumire varchar(50),
Pret int,
Gramaj int,
Tid int foreign key references TipuriInghetate(Tid))

create table InghetatePreferate(
IPid int primary key identity,
Denumire varchar(50),
Categorie varchar(50),
NrStele int)

create table Copii(
Cid int primary key identity,
Nume varchar(50),
Prenume varchar(50),
Gen varchar(20),
Varsta int,
IPid int foreign key references InghetatePreferate(IPid))

create table Serviri(
Iid int foreign key references Inghetate(Iid),
Cid int foreign key references Copii(Cid),
DataServire date,
Cantitate int,
constraint pk_Serviri primary key(Iid, Cid))

-- 1-n: InghetatePreferate-Copii

select * from TipuriInghetate
select * from Inghetate
select * from InghetatePreferate
select * from Copii
select * from Serviri

insert into TipuriInghetate values('La cutie', 'in cutie de plastic la diverse gramaje', 20),
('La cornet', 'glazurate si neglazurate', 30)

insert into Inghetate values('Panda', 4, 150, 2),('Scufita Rosie', 6, 100, 2)

insert into InghetatePreferate values('Alpin', 'vafa napolitana', 10), 
('Tort de ciocolata', 'ciocolate asortate cu vanilie', 6 )

insert into Copii values('Lupea', 'Maria', 'F', 6, 1), 
('Cristea', 'Dan', 'M', 8, 2)

insert into Serviri values(1, 1, '07/05/2022', 1),
(1, 2, '11/05/2023', 2)