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
    destroyMateriePrima(&m);
}

void test_destroyMateriePrima() {
    MateriePrima m = creeazaMateriePrima("ciocolata", "milka", 90);
    destroyMateriePrima(&m);
    assert(m.nume == NULL);
    assert(m.producator == NULL);
    assert(m.cantitate == -1);
}

void test_valideazaMateriePrima() {
    MateriePrima ex1 = creeazaMateriePrima("ciocolata", "milka", 90);
    assert(valideazaMateriePrima(ex1) == 1);
    destroyMateriePrima(&ex1);
    MateriePrima ex2 = creeazaMateriePrima("", "milka", 90);
    assert(valideazaMateriePrima(ex2) == 0);
    destroyMateriePrima(&ex2);
    MateriePrima ex3 = creeazaMateriePrima("cioco", "", 90);
    assert(valideazaMateriePrima(ex3) == 0);
    destroyMateriePrima(&ex3);
    MateriePrima ex4 = creeazaMateriePrima("ciocolata", "milka", -100);
    assert(valideazaMateriePrima(ex4) == 0);
    destroyMateriePrima(&ex4);
}

// teste REPOSITORY
void test_createEmpty() {
    List v = createEmpty();
    assert(v.length == 0);
    destroy(&v);
}

void test_add() {
    List lista = createEmpty();
    MateriePrima m = creeazaMateriePrima("ex1", "prod", 78);
    assert(lista.length == 0);
    add(&lista, m);
    assert(lista.length == 1);
    destroy(&lista);
    assert(lista.length==0);
}

void test_addCantitate() {
    List lista = createEmpty();
    assert(lista.length == 0);
    MateriePrima m = creeazaMateriePrima("ex", "producator", 80);
    add(&lista, m);
    destroyMateriePrima(&m);
    assert(lista.elements[0].cantitate == 80);
    MateriePrima n = creeazaMateriePrima("ex", "producator", 100);
    addCantitate(&lista, n, 0);
    destroyMateriePrima(&m);
    assert(lista.elements[0].cantitate == 100);
    destroy(&lista);
    assert(lista.length==0);
}

void test_delete() {
    List lista = createEmpty();
    assert(lista.length == 0);
    MateriePrima m = creeazaMateriePrima("unu", "prod", 90);
    add(&lista, m);
    destroyMateriePrima(&m);
    MateriePrima n = creeazaMateriePrima("doi", "prod", 1234);
    destroyMateriePrima(&m);
    add(&lista, n);
    assert(lista.length == 2);
    delete(&lista, 0);
    assert(lista.length == 1);
    assert(strcmp(lista.elements[0].nume, "doi")==0);
    assert(strcmp(lista.elements[0].producator, "prod")==0);
    assert(lista.elements[0].cantitate==1234);
    destroy(&lista);
    assert(lista.length==0);
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
    destroy(&lista);
}

void test_size() {
    List lista = createEmpty();
    assert(size(&lista) == 0);
    add(&lista, creeazaMateriePrima("unu", "prod", 90));
    add(&lista, creeazaMateriePrima("doi", "prod", 1234));
    assert(size(&lista) == 2);
    destroy(&lista);
    assert(lista.length==0);
}

void test_adaugaMateriePrima() {
    List lista = createEmpty();
    MateriePrima m = creeazaMateriePrima("ex", "prod", 90);
    assert(adaugaMateriePrima(&lista, m.nume, m.producator, m.cantitate)==1);
    destroyMateriePrima(&m);
    assert(size(&lista)==1);
    MateriePrima n = creeazaMateriePrima("ex", "prod", -800);
    assert(adaugaMateriePrima(&lista, n.nume, n.producator, n.cantitate)==0);
    destroyMateriePrima(&n);
    assert(adaugaMateriePrima(&lista, "ex", "prod", 123)==1);
    assert(size(&lista)==1);
    destroy(&lista);
    assert(lista.length==0);
}

void test_stergeMateriePrima() {
    List lista = createEmpty();
    MateriePrima m = creeazaMateriePrima("ex", "prod", 90);
    stergeMateriePrima(&lista, m.nume, m.producator);
    destroyMateriePrima(&m);
    assert(size(&lista)==0);
    destroy(&lista);
}

void test_modificaMateriePrima() {
    List lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ex", "prod", 90)==1);
    assert(size(&lista)==1);
    assert(modificaMateriePrima(&lista, "ex", "prod", "exemplu", "producator", 999)==1);
    assert(lista.elements[0].cantitate==999);
    assert(modificaMateriePrima(&lista, "ex", "prod", "", "producator", 999)==0);
    assert(modificaMateriePrima(&lista, "123", "prod", "ex", "producator", 999)==0);
    assert(lista.length==1);
    destroy(&lista);
    assert(lista.length==0);
}

void test_filtruMateriePrima() {
    List lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ex1", "prod1", 1));
    assert(adaugaMateriePrima(&lista, "ex2", "prod2", 500));
    assert(adaugaMateriePrima(&lista, "dada", "prod3", 300));
    List lista_filtrata = filtruMateriePrima(&lista, 'e', 300);
    assert(size(&lista_filtrata)==1);
    destroy(&lista);
    assert(lista.length==0);
    destroy(&lista_filtrata);
}

void test_sortMateriePrima() {
    List  lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ciocolata", "milka", 345));
    assert(adaugaMateriePrima(&lista, "corn", "7days", 200));
    assert(adaugaMateriePrima(&lista, "covrig", "gigi", 456));
    assert(adaugaMateriePrima(&lista, "cupcakes", "bakery", 34));
    assert(adaugaMateriePrima(&lista, "aaa", "nuj", 900));
    assert(adaugaMateriePrima(&lista, "corn", "la casa", 100));
    List lista_sortata = sortMateriaPrima(&lista);
    assert(size(&lista_sortata)==6);
    assert(strcmp(get(&lista_sortata, 0).nume, "aaa")==0);
    assert(strcmp(get(&lista_sortata, 1).nume, "ciocolata")==0);
    assert(strcmp(get(&lista_sortata, 2).nume, "corn")==0);
    assert(get(&lista_sortata, 3).cantitate==200);
    destroy(&lista);
    assert(lista.length==0);
}



