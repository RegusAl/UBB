#include "repository.h"

/*
 * Adauga Materia Prima la lista 'v'
 * param v: lista
 * param nume: numele Materiei Prime
 * param producator: producatorul Materiei Prime
 * param cantitate: cantitatea de Materie Prima
 * return: 1 - daca s-a efectuat adaugarea
 *         0 - daca datele au fost invalide
 */
int adaugaMateriePrima(List *v, char *nume, char *producator, int cantitate);

/*
 * Sterge materia prima in functie de nume si producator
 * param v: lista
 * param nume: Numele Materiei Prime ce se sterge
 * param producator: Producatorul Materiei Prime ce se sterge
 * return: 1 - daca s-a sters din stoc
 *         0 - daca nu s-a sters nimic din stoc
 */
int stergeMateriePrima(List *v, char *nume, char *producator);

/*
 * Modifica Materia Prima in finctie de nume si producator
 * param v: lista
 * param nume: Numele Materiei Prime ce se modifica
 * param producator: Producatorul Materiei Prime ce se modifica
 * param nume_nou: Numele Materiei Prime noi
 * param producator_nou: Producatorul Materiei Prime noi
 * param cantitate: Cantitatea Materiei Prime noi
 * return: 1 - daca s-a modificat
 *         0 - daca nu s-a modificat
 */
int modificaMateriePrima(List *v, char *nume, char *producator, char *nume_nou, char *producator_nou, int cantitate);

/*
 * Filtreaza Materia Prima cu prima litera din nume egala cu 'l' si cu cantitatea mai mica decat 'cantitate_max'
 * param v: lista
 * param l: litera dupa care se cauta Materia Prima
 * param cantitate_max: cantitatea maxima a Materiei Prime
 * return: lista filtrata
 */
List filtruMateriePrima(List *v, char l, int cantitate_max);

typedef int(*FunctieComparare)(MateriePrima* m1, MateriePrima* m2);

//int comparareNume(MateriePrima* m1, MateriePrima* m2);
//
//int comparareCantitate(MateriePrima* m1, MateriePrima* m2);

//void sort(List*v, FunctieComparare cmpN, FunctieComparare cmpC);

/*
 * Sorteaza Materia Prima in functie de nume si de cantitate
 * param v: lista
 * return: lista sortata
 */
List sortMateriaPrima(List *v);