#include "MateriePrima.h"

typedef MateriePrima ElemType;
typedef struct {
    ElemType* elements;
    int length;
    int capacitate;
} List;

/*
 * Creeaza o lista goala
 * return: lista
 */
List createEmpty();

/*
 * Distruge o lista
 */
void destroy(List* v);

/*
 * Adauga in lista v elementul el
 * param v: lista
 * param el: elementul ce se introduce in lista
 */
void add(List *v, ElemType el);

/*
 * Inlocuieste in lista 'v', elementul de pe pozitia 'poz' cu 'el'
 * param v: lista
 * param el: elementul ce se introduce in lista
 * param poz (int): pozitia din lista in care se introduce elementul 'el'
 */
void addCantitate(List *v, ElemType el, int poz);

/*
 * Sterge elementul de pe pozitia 'poz' din lista 'v'
 * param v: lista din care se sterge
 * param poz: pozitia elementului ce se sterge (int)
 * return: elementul ce s-a sters
 */
ElemType delete(List *v, int poz);

/*
 * Returneaza elementul de pe pozitia 'poz'
 * param v: lista
 * param poz: pozitia elementului ce se returneaza
 * return: Elementul de pe pozitia 'poz'
 */
ElemType get(List *v, int poz);

/*
 * Returneaza lungimea listei 'v'
 * param v: lista
 * return: lungimea listei 'v'
 */
int size(List *v);

