#include "teste.h"

#include "service.h"

#include <assert.h>
#include <string.h>

// teste DOMAIN
void test_creeazaMateriePrima() {
    MateriePrima m = creeazaMateriePrima("ciocolata", "milka", 90);
    assert(strcmp(m.nume, "ciocolata")==0);
    assert(strcmp(m.producator, "milka")==0);
    assert(m.cantitate==90);
}

void test_destroyMateriePrima() {
    MateriePrima m = creeazaMateriePrima("ciocolata", "milka", 90);
    destroyMateriePrima(&m);
    assert(strlen(m.nume)==0);
    assert(strlen(m.producator)==0);
    assert(m.cantitate == -1);
}

void test_valideazaMateriePrima() {
    MateriePrima ex1 = creeazaMateriePrima("ciocolata", "milka", 90);
    assert(valideazaMateriePrima(ex1) == 1);
    MateriePrima ex2 = creeazaMateriePrima("", "milka", 90);
    assert(valideazaMateriePrima(ex2) == 0);
    MateriePrima ex3 = creeazaMateriePrima("cioco", "", 90);
    assert(valideazaMateriePrima(ex3) == 0);
    MateriePrima ex4 = creeazaMateriePrima("ciocolata", "milka", -100);
    assert(valideazaMateriePrima(ex4) == 0);
}

// teste REPOSITORY
void test_createEmpty() {
    List v = createEmpty();
    assert(v.length == 0);
}

void test_add() {
    List lista = createEmpty();
    MateriePrima m = creeazaMateriePrima("ex1", "prod", 78);
    assert(lista.length == 0);
    add(&lista, m);
    assert(lista.length == 1);
}

void test_addCantitate() {
    List lista = createEmpty();
    assert(lista.length == 0);
    add(&lista, creeazaMateriePrima("ex", "producator", 80));
    assert(lista.elements[0].cantitate == 80);
    MateriePrima m = creeazaMateriePrima("ex", "producator", 100);
    addCantitate(&lista, m, 0);
    assert(lista.elements[0].cantitate == 100);
}

void test_delete() {
    List lista = createEmpty();
    assert(lista.length == 0);
    add(&lista, creeazaMateriePrima("unu", "prod", 90));
    add(&lista, creeazaMateriePrima("doi", "prod", 1234));
    assert(lista.length == 2);
    delete(&lista, 0);
    assert(lista.length == 1);
    assert(strcmp(lista.elements[0].nume, "doi")==0);
    assert(strcmp(lista.elements[0].producator, "prod")==0);
    assert(lista.elements[0].cantitate==1234);
}

void test_get() {
    List lista = createEmpty();
    assert(lista.length == 0);
    add(&lista, creeazaMateriePrima("unu", "prod", 90));
    add(&lista, creeazaMateriePrima("doi", "prod", 1234));
    assert(lista.length == 2);
    assert(strcmp(get(&lista, 0).nume, "unu")==0);
    assert(strcmp(get(&lista, 0).producator, "prod")==0);
    assert(get(&lista, 0).cantitate==90);
}

void test_size() {
    List lista = createEmpty();
    assert(size(&lista) == 0);
    add(&lista, creeazaMateriePrima("unu", "prod", 90));
    add(&lista, creeazaMateriePrima("doi", "prod", 1234));
    assert(size(&lista) == 2);
}

void test_adaugaMateriePrima_stergeMateriePrima() {
    List lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ex", "prod", 90)==1);
    assert(size(&lista)==1);
    assert(adaugaMateriePrima(&lista, "ex", "prod", -800)==0);
    assert(size(&lista)==1);
    assert(stergeMateriePrima(&lista, "ex", "prod")==1);
    assert(stergeMateriePrima(&lista, "ex", "producator")==0);
}

void test_modificaMateriePrima() {
    List lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ex", "prod", 90)==1);
    assert(size(&lista)==1);
    assert(modificaMateriePrima(&lista, "ex", "prod", "exemplu", "producator", 999)==1);
    assert(lista.elements[0].cantitate==999);
    assert(modificaMateriePrima(&lista, "nuj", "prod", "exemplu", "producator", 999)==0);
    assert(lista.length==1);
}


