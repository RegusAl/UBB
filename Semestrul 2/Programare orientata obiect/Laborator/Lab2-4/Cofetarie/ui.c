#include <stdio.h>
#include <string.h>

#include "service.h"
#include "teste.h"

void testAll() {
    // test domain
    test_creeazaMateriePrima();
    test_destroyMateriePrima();
    test_valideazaMateriePrima();
    // test repository
    test_createEmpty();
    test_add();
    test_addCantitate();
    test_delete();
    test_get();
    test_size();
    // test service
    test_adaugaMateriePrima_stergeMateriePrima();
    test_modificaMateriePrima();
}

// Functia ui de adaugare
void uiAdd(List *v) {
    char nume[30], producator[30];
    int cantitate;
    printf("Nume: ");
    scanf("%s", nume);
    printf("Producator: ");
    scanf("%s", producator);
    printf("Cantitate: ");
    scanf("%d", &cantitate);
    int succes = adaugaMateriePrima(v, nume, producator, cantitate);
    if(succes)
        printf("Materie Prima adaugata cu succes!\n");
    else
        printf("Materia Prima nu este valida!\n");
}

// Functia ui de modificare
void uiModify(List *v) {
    char nume[30], nume_nou[30], producator[30], producator_nou[30];
    int cantitate;
    printf("De modificat\n");
    printf("Nume: ");
    scanf("%s", nume);
    printf("Producator: ");
    scanf("%s", producator);
    printf("Nume nou: ");
    scanf("%s", nume_nou);
    printf("Producator nou: ");
    scanf("%s", producator_nou);
    printf("Cantitate: ");
    scanf("%d", &cantitate);
    int succes = modificaMateriePrima(v, nume, producator, nume_nou, producator_nou, cantitate);
    if(succes)
        printf("Modificarea s-a efectuat cu succes!\n");
    else
        printf("Modificarea nu s-a efectuat! Date invalide!\n");
}

// Functia ui de stergere
void uiDelete(List *v) {
    char nume[30], producator[30];
    printf("Numele Materiei Prime de sters: ");
    scanf("%s", nume);
    printf("Numele producatorului de sters: ");
    scanf("%s", producator);
    int succes = stergeMateriePrima(v, nume, producator);
    if(succes)
        printf("Materie Prima stearsa cu succes!\n");
    else
        printf("Nu exista Materie Prima de acest fel!\n");
}

// Functia ui de afisare a stocului
void uiStoc(List *v) {
    if(v->length == 0)
        printf("Nu este nimic in stoc!\n");
    else {
        printf("Stoc: \n");
        for(int i = 0; i<size(v); i++) {
            MateriePrima m = get(v, i);
            printf("Nume: %s | Producator: %s | Cantitate: %d\n", m.nume, m.producator, m.cantitate);
        }
    }
}

// Functia ui de filtrare
void uiFiltru(List *v) {
    char l;
    int cantitate_max;
    printf("Prima litera: ");
    scanf(" %c", &l);
    printf("Cantitatea maxima: ");
    scanf("%d", &cantitate_max);
    List listaFiltrata = filtruMateriePrima(v, l, cantitate_max);
    uiStoc(&listaFiltrata);
}

// Functia ui de sortare
void uiSort(List *v) {
    List listaSortata = sortMateriaPrima(v);
    uiStoc(&listaSortata);
}

// meniu
void uiMenu() {
    printf("\t\t--MENIU--\n");
    printf("1. Adaugare Materie Prima (daca exista deja in stoc se actualizeaza cantitatea\n");
    printf("2. Modificare Materie Prima\n");
    printf("3. Stergere Materie Prima\n");
    printf("4. Afisare Stoc\n");
    printf("5. Afisare materii prime ale carui nume incepe cu o litera data de utilizator si au cantitatea mai mica decat cea data de utilizator\n");
    printf("6. Afisare stoc sortat dupa nume si cantitate\n");
    printf("0. Iesire din program.\n");
    printf("--\t--\t--\n");
}

// Functia run
void run() {
    List listaMateriePrima = createEmpty();
    int ok = 1, option;
    while(ok) {
        uiMenu();
        printf("Optiune: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("1\n");
                uiAdd(&listaMateriePrima);
                break;
            case 2:
                printf("2\n");
                uiModify(&listaMateriePrima);
                break;
            case 3:
                printf("3\n");
                uiDelete(&listaMateriePrima);
                break;
            case 4:
                printf("4\n");
                uiStoc(&listaMateriePrima);
                break;
            case 5:
                printf("5\n");
                uiFiltru(&listaMateriePrima);
                break;
            case 6:
                printf("6\n");
                uiSort(&listaMateriePrima);
                break;
            case 0:
                printf("Iesire din program.\n");
                ok = 0;
                break;
            default:
                printf("Optiunea nu este valida!\n");
                break;
        }
    }
}

int main() {
    testAll();
    run();
    return 0;
}