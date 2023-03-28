#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

typedef struct {
	char* cod;
	char* nume;
	float concentratie;
	int stoc;
} Medicament;

/*
* Creare medicament
*
* @param cod: codul med (string)
* @param nume: numele med (string)
* @param concentratie: concentratia melodiei (float)
* @param stoc: cantitate de med in stoc (int)
*
* @return medicamentul creat (Medicament)
*/
Medicament* createMedicament(char* cod, char* nume, float concentratie, int stoc);

/* Copie medicament. */
Medicament* copyMedicament(Medicament* m);

/* Distrugere med. */

void destroyMedicament(Medicament *m);

/*
* Valideaza med
* Un medicament este valid daca codul si numele sunt diferite de ""
* iar 0<=concentratie si 0<=stoc
* @param m: med de validat (Medicament)
*
* @return: 1 daca medicamentul este valid, 0 daca nu
*/

int valideaza(Medicament* m);

void testCreateDestroy();