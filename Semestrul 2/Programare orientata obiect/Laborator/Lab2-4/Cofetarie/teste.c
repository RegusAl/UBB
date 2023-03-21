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
    destroy(&lista);
    assert(lista.length==0);
}

void test_addCantitate() {
    List lista = createEmpty();
    assert(lista.length == 0);
    add(&lista, creeazaMateriePrima("ex", "producator", 80));
    assert(lista.elements[0].cantitate == 80);
    MateriePrima m = creeazaMateriePrima("ex", "producator", 100);
    addCantitate(&lista, m, 0);
    assert(lista.elements[0].cantitate == 100);
    destroy(&lista);
    assert(lista.length==0);
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

void test_adaugaMateriePrima_stergeMateriePrima() {
    List lista = createEmpty();
    assert(adaugaMateriePrima(&lista, "ex", "prod", 90)==1);
    assert(size(&lista)==1);
    assert(adaugaMateriePrima(&lista, "ex", "prod", -800)==0);
    assert(size(&lista)==1);
    assert(adaugaMateriePrima(&lista, "ex", "prod", 900)==1);
    assert(stergeMateriePrima(&lista, "ex", "prod")==1);
    assert(stergeMateriePrima(&lista, "ex", "producator")==0);
    destroy(&lista);
    assert(lista.length==0);
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
    assert(get(&lista_sortata, 3).cantitate ==200);
    destroy(&lista);
    assert(lista.length==0);
}



