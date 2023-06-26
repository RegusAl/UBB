#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include <exception>

using namespace std;

//functia de dispersie
// Theta(1)
int MDO::dispersie(TCheie c) const {
    c = abs(c);
    return c % m;
}

// O(m) - m  = numarul de locatii din tabela de dispersie
MDO::MDO(Relatie r) {
    relatie = r;
    m = 300;
    n = 0;
    for (int i = 0; i < m; i++) {
        e[i].first = INIT;
        e[i].second = INIT;
        urm[i] = INIT;
    }
    primLiber = 0;
}

// actualizare primLiber
void MDO::actualizarePrimLiber() {
    primLiber++;
    while (primLiber < m && e[primLiber].first != INIT)
        primLiber++;
}

// AC: O(n)
// WC: Theta(n)
// BC: Theta(1) - daca multidictionarul este gol
void MDO::adauga(TCheie c, TValoare v) {
    int i = dispersie(c), j;
    if (e[i].first == INIT) {
        e[i].first = c;
        e[i].second = v;
        if (i == primLiber) {
            actualizarePrimLiber();
        }
        n++;
    } else {
        while (i != INIT) {
            if ((Relatie) (e[i].first) && dispersie(e[i].first) == i) {
                int aux1 = c;
                int aux2 = v;
                c = e[i].first;
                v = e[i].second;
                e[i].first = aux1;
                e[i].second = aux2;
            }
            j = i;
            i = urm[i];
        }
        e[primLiber].first = c;
        e[primLiber].second = v;
        urm[j] = primLiber;
        actualizarePrimLiber();
        n++;
    }
}

// WC: Theta(m + n)
// BC: Theta(1) - daca nu exista perechea (c, v)
// AC: O(m) - m = dimensiunea tabelei de dispersie
bool MDO::sterge(TCheie c, TValoare v) {
    TElem elem(c, v);
    int i = dispersie(c), j = INIT, k = 0, p, pp;
    bool gata;

    while (k < m && j == INIT) {
        if (urm[k] == i) j = k;
        else k++;
    }

    while (i != INIT && e[i] != elem) {
        j = i;
        i = urm[i];
    }
    if (i == INIT) //daca cheia cu val asociata nu exista
    {
        return false;
    } else {
        gata = false;
        do {

            p = urm[i];
            pp = i;
            while (p != INIT && dispersie(e[p].first) != i) {
                pp = p;
                p = urm[p];
            }
            if (p == INIT) gata = true;
            else {
                e[i] = e[p];
                j = pp;
                i = p;
            }

        } while (!gata);
        if (j != INIT)
            urm[j] = urm[i];
        e[i].first = INIT;
        urm[i] = INIT;
        if (primLiber > i)
            primLiber = i;
        n--;
        return true;
    }
}


// WC: Theta(n) - se parcurge doar TD
// BC: Theta(1) - se gaseste la locatie si e unica
// AC: O(n)
vector<TValoare> MDO::cauta(TCheie c) const {
    int poz = (c);

    vector<TValoare> v;
    while (poz != -1 && e[poz].first != c) {

        poz = urm[poz];
    }

    //daca poz=-1 => cheia nu a fost gasita
    while (poz != -1 && e[poz].first == c) {
        v.push_back(e[poz].second);
        poz = urm[poz];
    }
    return v;
}

int MDO::dim() const {
    return n;
}

bool MDO::vid() const {
    return n == 0;
}

IteratorMDO MDO::iterator() const {
    return IteratorMDO(*this);
}

MDO::~MDO() {
}

// Theta(n) - n dimensiunea
int MDO::adaugaInexistente(MDO &mdo) {
    int nrPerechiAdaugate = 0;
    for (int i = 1; i <= mdo.dim(); i++) {
        if (this->cauta(e[i].first) != mdo.cauta(mdo.e[i].first) ||
            (this->cauta(e[i].first) != mdo.cauta(mdo.e[i].first) &&
             this->cauta(e[i].second) != mdo.cauta(mdo.e[i].second))) {
            adauga(mdo.e[i].first, mdo.e[i].second);
//            cout << mdo.e[i].second << endl;
            nrPerechiAdaugate++;
        }
    }
    return nrPerechiAdaugate;
}

