#include <stdio.h>
#include <string.h>

// domain
typedef struct {
    char nume[30];
    char producator[30];
    int cantitate;
} MateriePrima;

/*
 * Creeaza o entitate de tipul Materie Prima
 * param nume: numele entitatii (char)
 * param producator: producatorul entitatii (char)
 * param cantitate: cantitatea (int)
 * return: Materie Prima
 */
MateriePrima creeazaMateriePrima(char *nume, char *producator, int cantitate) {
    MateriePrima m;
    strcpy(m.nume, nume);
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
    m -> nume[0] = '\0';
    m -> producator[0] = '\0';
    m ->cantitate = -1;
}

// list
typedef MateriePrima ElemType;
typedef struct {
    ElemType elements[100];
    int length;
} List;

/*
 * Creeaza o lista goala
 * return: lista
 */
List createEmpty() {
    List v;
    v.length = 0;
    return v;
}

/*
 * Adauga in lista v elementul el
 * param v: lista
 * param el: elementul ce se introduce in lista
 */
void add(List *v, ElemType el) {
    v->elements[v->length] = el;
    v->length++;
}

/*
 * Inlocuieste in lista 'v', elementul de pe pozitia 'poz' cu 'el'
 * param v: lista
 * param el: elementul ce se introduce in lista
 * param poz (int): pozitia din lista in care se introduce elementul 'el'
 */
void addCantitate(List *v, ElemType el, int poz) {
    v->elements[poz] = el;
}

/*
 * Sterge elementul de pe pozitia 'poz' din lista 'v'
 * param v: lista din care se sterge
 * param poz: pozitia elementului ce se sterge (int)
 * return: elementul ce s-a sters
 */
ElemType delete(List *v, int poz) {
    ElemType el = v->elements[poz];
    for(int i = poz; i<v->length-1; i++) {
        v->elements[i] = v->elements[i+1];
    }
    v->length--;
    return el;
}

/*
 * Returneaza elementul de pe pozitia 'poz'
 * param v: lista
 * param poz: pozitia elementului ce se returneaza
 * return: Elementul de pe pozitia 'poz'
 */
ElemType get(List *v, int poz) {
    return v->elements[poz];
}

/*
 * Returneaza lungimea listei 'v'
 * param v: lista
 * return: lungimea listei 'v'
 */
int size(List *v) {
    return v->length;
}

// service

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

// ui

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
    run();
    return 0;
}