#include "repository.h"

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
 * Distruge o lista
 */
void destroy(List* v) {
    v->length = 0;
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
