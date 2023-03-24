#include <string.h>
#include <stdlib.h>

#include "MateriePrima.h"

/*
 * Creeaza o entitate de tipul Materie Prima
 * param nume: numele entitatii (char)
 * param producator: producatorul entitatii (char)
 * param cantitate: cantitatea (int)
 * return: Materie Prima
 */
MateriePrima creeazaMateriePrima(char *nume, char *producator, int cantitate) {
    MateriePrima m;
    int nrC  = (int) strlen(nume)+1;
    m.nume = malloc(nrC * sizeof(char));
    strcpy(m.nume, nume);

    nrC = (int) strlen(producator)+1;
    m.producator = malloc(nrC * sizeof(char));
    strcpy(m.producator, producator);

    m.cantitate = cantitate;
    return m;
}

/*
 * Valideaza o entitate de tipul Materie Prima
 * param: m (struct)
 * return: 1 - daca entitatea este valida
 *         0 - daca entitatea nu este valida
 */
int valideazaMateriePrima(MateriePrima m) {
    if(strlen(m.nume) == 0)
        return 0;
    if(strlen(m.producator) == 0)
        return 0;
    if(m.cantitate < 0)
        return 0;
    return 1;
}

/*
 * Sterge elementele entitatii de tipul Materie Prima
 * param: m (struct)
 */
void destroyMateriePrima(MateriePrima *m) {
//    m -> nume[0] = '\0';
//    m -> producator[0] = '\0';
    free(m->nume);
    free(m->producator);
    m ->cantitate = -1;
    m->nume = NULL;
    m->producator = NULL;

}
