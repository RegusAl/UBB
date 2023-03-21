#include <iostream>
#include "IteratorColectie.h"
#include "Colectie.h"

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
    pozitie = 0;
    frecventa = 1;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
TElem IteratorColectie::element() const{
	/* de adaugat */
	if(this->valid())
        return col.e[pozitie].valoare;
    throw std::exception();
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
bool IteratorColectie::valid() const {
	/* de adaugat */
	return pozitie < col.n;
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
void IteratorColectie::urmator() {
	/* de adaugat */
    if(this->valid()) {
        if(frecventa < col.e[pozitie].frecventa)
            frecventa++;
        else {
            pozitie++;
            frecventa = 1;
        }
    } else {
        throw std::exception();
    }
}

/*
 * Best Case = Average Case = Worst Case
 * Complexitate Timp: O(1)
 * Complexitate Spatiu: O(1)
 */
void IteratorColectie::prim() {
	/* de adaugat */
    pozitie = 0;
    frecventa = 1;
}
