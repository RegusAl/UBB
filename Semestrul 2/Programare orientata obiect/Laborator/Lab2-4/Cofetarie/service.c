#include "service.h"

#include <string.h>

/*
 * Adauga Materia Prima la lista 'v'
 * param v: lista
 * param nume: numele Materiei Prime
 * param producator: producatorul Materiei Prime
 * param cantitate: cantitatea de Materie Prima
 * return: 1 - daca s-a efectuat adaugarea
 *         0 - daca datele au fost invalide
 */
int adaugaMateriePrima(List *v, char *nume, char *producator, int cantitate) {
    MateriePrima m = creeazaMateriePrima(nume, producator, cantitate);
    if(valideazaMateriePrima(m)==0)
        return 0;
    int ok = 0;
    // se modifica cantitatea daca se da o materie prima cu acelasi nume si producator ce este in stoc.
    for(int i = 0; i< size(v); i++) {
        if(strcmp(get(v, i).nume, m.nume)==0 && strcmp(get(v, i).producator, m.producator)==0) {
            addCantitate(v, m, i);
            ok = 1;
        }
    }
    if(ok == 0)
        add(v, m);
    return 1;
}

/*
 * Sterge materia prima in functie de nume si producator
 * param v: lista
 * param nume: Numele Materiei Prime ce se sterge
 * param producator: Producatorul Materiei Prime ce se sterge
 * return: 1 - daca s-a sters din stoc
 *         0 - daca nu s-a sters nimic din stoc
 */
int stergeMateriePrima(List *v, char *nume, char *producator) {
    int poz;
    for(int i = 0; i< size(v); i++) {
        if(strcmp(get(v, i).nume, nume)==0 && strcmp(get(v, i).producator, producator)==0) {
            poz = i;
            MateriePrima m = delete(v, poz);
            destroyMateriePrima(&m);
            return 1;
        }
    }
    return 0;
}

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
int modificaMateriePrima(List *v, char *nume, char *producator, char *nume_nou, char *producator_nou, int cantitate) {
    int sters = stergeMateriePrima(v, nume, producator);
    if(sters==0) {
        return 0;
    } else {
        int adauga = adaugaMateriePrima(v, nume_nou, producator_nou, cantitate);
        if(adauga==0)
            return 0;
    }
    return 1;
}

/*
 * Filtreaza Materia Prima cu prima litera din nume egala cu 'l' si cu cantitatea mai mica decat 'cantitate_max'
 * param v: lista
 * param l: litera dupa care se cauta Materia Prima
 * param cantitate_max: cantitatea maxima a Materiei Prime
 * return: lista filtrata
 */
List filtruMateriePrima(List *v, char l, int cantitate_max) {
    List listaFiltrata = createEmpty();
    for(int i = 0; i< size(v); i++) {
        MateriePrima m = get(v, i);
        if(m.nume[0] == l && m.cantitate < cantitate_max) {
            add(&listaFiltrata, creeazaMateriePrima(m.nume, m.producator, m.cantitate));
        }
    }
    return listaFiltrata;
}

/*
 * Sorteaza Materia Prima in functie de nume si de cantitate
 * param v: lista
 * return: lista sortata
 */
List sortMateriaPrima(List *v) {
    List listaSortata = *v;
    MateriePrima temp;
    for(int i = 0; i < size(&listaSortata)-1; i++) {
        for(int j = i+1; j < size(&listaSortata); j++) {
            if(strcmp(get(&listaSortata, i).nume, get(&listaSortata, j).nume)>0) {
                if(get(&listaSortata, i).cantitate > get(&listaSortata, j).cantitate) {
                    temp = listaSortata.elements[i];
                    listaSortata.elements[i] = listaSortata.elements[j];
                    listaSortata.elements[j] = temp;
                }
            }
        }
    }
    return listaSortata;
}
