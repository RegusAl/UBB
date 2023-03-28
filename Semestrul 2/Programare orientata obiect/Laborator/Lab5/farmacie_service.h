#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include "MyList.h"

typedef struct {
	MyList* allMedicament;
	MyList* undoList;
}Farmacie;

/*
* Creaza o entitate de tip Farmacie care contine o
* lista de medicamente si una pentru undo
*/
Farmacie createFarmacie();

/*
* Elibereaza memoria alocata pentru o Farmacie
*/
void destroyFarmacie(Farmacie* farmacie);

/*
* Adauga un med
*
* @param farmacie: Farmacie in care se adauga (Farmacie*)
* @param cod: codul med care se adauga (char*)
* @param nume: numele med care se adauga (char*)
* @param concentratie: concentratia med care se adauga (float)
* @param stoc: stocul med care se adauga (int)
*
* @return: 1 daca med a fost adaugat cu succes, 0 altfel (int)
* post: med cu datele date este adaugat in lista (daca este valid)
*/

int addMedicament(Farmacie* farmacie, char* cod, char* nume, float concentratie, int stoc);

/*
* Gaseste un med cu cod dat
*
* @param farmacie: Farmacie in care se cauta (Farmacie* )
* @param cod: codul med care se cauta (char*)
*
* @return: pozitia din lista a med cautat, -1 daca
			med nu exista in lista (int)
*/

int findMedicament(Farmacie* farmacie, char* cod);

/*
* Sterge un med
*
* @param farmacie: Farmacie din care se sterge (Farmacie* )
* @param cod: codul med care se sterge (char*)
* @param nume: numele med care se sterge (char*)
*
* @return: 1 daca med a fost sters cu succes, 0 altfel (int)
* post:med cu codul cod si numele nume este sters din lista daca exista
*/

int deleteMedicament(Farmacie* farmacie, char* cod);

/*
* Modifica un med
*
* @param farmacie: Farmacie in care se modifica (Farmacie* )
* @param cod: codul med care se modifica (char*)
* @param nume: numele med cu care se modifica (char*)
* @param concentratie: concentratia med cu care se modifica (float)
* @param stoc: stocul med care se modifica (int)
* @return: 1 daca med a fost modificat cu succes, 0 altfel (int)
* post:med cu codul cod are un nume si o concentratie noua (daca un astfel
*		de med exista)
*/

int modifyMedicament(Farmacie* farmacie, char* cod, char* nume, float concentratie, int stoc);

/*
* Filtreaza lista de medicamente dupa o litera data.
*
* @param farmacie: Farmacie cu toate medicamentele
* @param typeSubstring: litera dupa care se filtreaza (char*)

*
* @return: lista cu medicamentele a caror nume incepe cu litera aleasa (MyList*)
*		   daca typeSubstring="" se returneaza o copie a listei originale
*/

MyList* getAllMedicamentChar(Farmacie* farmacie, char* typeSubstring);

/*
* Filtreaza lista de medicamente dupa un nr dat.
*
* @param farmacie: Farmacie cu toate medicamentele
* @param n: numarul dupa care se filtreaza (int*)

*
* @return: lista cu medicamentele a caror cantitate in stoc este mai mica decat numarul introdus (MyList*)
*		   daca n<=0 se returneaza o copie a listei originale
*/

MyList* getAllMedicamentNr(Farmacie* farmacie, int n);

/*
* Filtreaza lista de medicamente dupa stocurile date.
*
* @param farmacie: Farmacie cu toate medicamentele
* @param stocMin: stocul minim dupa care se filtreaza (int*)
* @param stocMax: stocul maxim dupa care se filtreaza (int*)

*
* @return: lista cu medicamentele a caror sotc este >= decat stocul minim si <= decat stocul maxim. (MyList*)
*/

MyList* getAllMedicamentStoc(Farmacie* farmacie, int stocMin, int stocMax);


//int cmpStoc(Medicament* m1, Medicament* m2);

//int cmpStocD(Medicament* m1, Medicament* m2);

//int cmpNume(Medicament* m1, Medicament* m2);

//int cmpNumeD(Medicament* m1, Medicament* m2);

/*
* Returneaza o lista sortata de medicamente
* Criteriu de sortare: stoc (crescator)
*
* @param farmacie: Farmacie cu medicamentele care se sorteaza (Farmacie*)
*
* @return: o lista sortata de medicamente  (MyList*)
*/

MyList* sortStoc(Farmacie* farmacie);

/*
* Returneaza o lista sortata de medicamente
* Criteriu de sortare: nume (crescator)
*
* @param farmacie: Farmacie cu medicamentele care se sorteaza (Farmacie*)
*
* @return: o lista sortata de medicamente  (MyList*)
*/


MyList* sortNume(Farmacie* farmacie);

/*
* Returneaza o lista sortata de medicamente
* Criteriu de sortare: stoc (descrescator)
*
* @param farmacie: Farmacie cu medicamentele care se sorteaza (Farmacie*)
*
* @return: o lista sortata de medicamente  (MyList*)
*/

MyList* sortStocD(Farmacie* farmacie);

/*
* Returneaza o lista sortata de medicamente
* Criteriu de sortare: nume (descrescator)
*
* @param farmacie: Farmacie cu medicamentele care se sorteaza (Farmacie*)
*
* @return: o lista sortata de medicamente  (MyList*)
*/

MyList* sortNumeD(Farmacie* farmacie);

/*
* Reface ultima operatie
*
* @return: 1 daca undo-ul a fost realizat, 0 altfel (int)
* post: lista de medicamente este cea aferenta efectuarii ultimei operatii care a modificat-o
*/

int undo(Farmacie* farmacie);

void testAddMedicament();
void testFindMedicament();
void testModify();
void testDelete();
void testGetAllChar();
void testGetAllNr();
void testGetAllStocuri();
void testSortStoc();
void testSortStocD();
void testSortNume();
void testSortNumeD();
void testUndo();