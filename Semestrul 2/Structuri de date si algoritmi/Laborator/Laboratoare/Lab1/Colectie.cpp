#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

/*
 * Best Case = Average Case = Worst Case
 * complexitate timp = O(1)
 */
bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

/*
 * Best Case: perechea se afla la mijloc => O(1) - theta
 * Worst Case: perechea nu exista sau se afla la inceputul/sfarsitul sirului => O(log(n))
 * Average Case: O(log(n)) - theta
 * Complexitate Spatiu: O(1)
 */
int Colectie::cautareBinara(Pereche *pereche, int stanga, int dreapta, TElem element, bool& gasit) const{
    int mijloc = 0;
    while (stanga <= dreapta && !gasit) {
        mijloc = (stanga + dreapta) / 2;
        if (element == pereche[mijloc].valoare) {
            gasit = true;
        }
        else {
            if (rel(element, pereche[mijloc].valoare))
                dreapta = mijloc - 1;
            else
                stanga = mijloc + 1;
        }
    }
    if (rel(element, pereche[mijloc].valoare))
        return mijloc;
    return mijloc + 1;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(n)
 * Complexitate Spatiu: O(n) - deoarece lucram cu vector
 */
void Colectie::redim() {
    Pereche* eNou = new Pereche[2 * cp];
    for(int i = 0; i<n; i++) {
        eNou[i] = e[i];
    }
    cp = 2 * cp;
    delete[] e;
    e = eNou;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate timp: O(1)
 * Complexitate spatiu: O(1)
 */
Colectie::Colectie() {
    this->cp = 1;
    this->e = new Pereche[this->cp];
    this->n = 0;
}

/*
 * Best Case: O(1) - daca elementul exista in mijlocul vectorului
 * Average Case: O(log(n)) - daca exista sau trebuie adaugat intre inceput-mijloc sau intre mijloc-sfarsit
 * Worst Case: O(log(n)) - daca exista sau trebuie adaugat la inceput/sfarsit
 * Complexitate Timp: O(log(n))
 * Complexitate Spatiu: O(1)
 */
void Colectie::adauga(TElem e) {
    if(n==0) {
        Pereche p;
        p.valoare = e;
        p.frecventa = 1;
        this->e[0] = p;
        n++;
        return;
    }
    bool gasit = false;
    int poz = cautareBinara(this->e, 0, n - 1, e, gasit);
    if (gasit)
        this->e[poz].frecventa++;
    else {
        if (n == cp)
            redim();
        for (int i = n; i > poz; i--)
            this->e[i] = this->e[i - 1];
        Pereche p;
        p.valoare = e;
        p.frecventa = 1;
        this->e[poz] = p;
        n++;
    }
}

/*
 * Best Case: O(1) - daca elementul ce trebuie sters se afla la mijloc
 * Average Case: O(log(n)) - daca elementul este intre inceput-mijloc sau mijloc-sfarsit
 * Worst Case: O(log(n)) - daca nu exista sau se afla la inceput/sfarsit
 * Complexitate Timp: O(log(n))
 * Complexitate Spatiu: O(1)
 */
bool Colectie::sterge(TElem e) {
	bool gasit = false;
    int poz = cautareBinara(this->e, 0, n-1, e, gasit);
    if(gasit == false) {
        return false;
    }
    if(this->e[poz].frecventa > 1) {
        this->e[poz].frecventa--;
    } else {
        for(int i = poz; i < n-1; i++) {
            this->e[i] = this->e[i+1];
        }
        n--;
    }
    return true;
}

/*
 * Best Case: O(1) - daca elementul cautat se afla pe prima pozitie
 * Average Case: O(n)
 * Worst Case: O(n) - daca elementul cauta nu exista sau se afla pe ultima pozitie
 * Complexitate Timp: O(n)
 * Complexitate Spatiu: O(1)
 */
bool Colectie::cauta(TElem elem) const {
    for(int i = 0; i<n; i++) {
        if(this->e[i].valoare == elem) {
            return true;
        }
    }
    return false;
}

/*
 * Best Case: perechea se afla la mijloc => O(1) - theta
 * Worst Case: perechea nu exista sau se afla la inceputul/sfarsitul sirului => O(log(n))
 * Average Case: O(log(n)) - theta
 * Complexitate Spatiu: O(1)
 */
int Colectie::nrAparitii(TElem elem) const {
    bool gasit = false;
    int poz = cautareBinara(this->e, 0, n - 1, elem, gasit);
    if (!gasit)
        return 0;
    return this->e[poz].frecventa;
}


/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(n)
 * Complexitate Spatiu: O(1)
 */
int Colectie::dim() const {
	int d = 0;
    for(int i = 0; i<n; i++) {
        d += this->e[i].frecventa;
    }
    return d;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
bool Colectie::vida() const {
	/* de adaugat */
	if(n == 0)
        return true;
    else
        return false;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(n) - unde n = nr - daca numarul de aparitii a elementului n ce trebuie sters > nr
 *                                n = nrAparitii - daca nr > nrAparitii
 * Complexitate Spatiu: O(1) - deoarece folosim variabile simple
 */
int Colectie::eliminaAparitii(int nr, TElem elem) {
    // daca nr este negativ, arunca exceptie
    if(nr < 0) {
        throw std::exception();
    }
    int aparitii_eliminate = 0;
    while(nr && nrAparitii(elem)) {
        sterge(elem);
        nr--;
        aparitii_eliminate++;
    }
    return aparitii_eliminate;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
Colectie::~Colectie() {
    delete[] e;
}
