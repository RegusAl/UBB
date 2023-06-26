#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Multime::Multime() {
	prim = nullptr;
	ultim = nullptr;
	size = 0;
}


bool Multime::adauga(TElem elem) {
	Nod* newNod = new Nod;
	newNod->anterior = newNod->urmator = nullptr;
	newNod->element = elem;

	//daca lista e goala
	if (prim == nullptr)
	{
		prim = ultim = newNod;
		size++;
		return true;
	}

	//daca lista nu e goala
	if (cauta(elem))
		return false;

	//daca lista nu e goala si nici nu se afla deja elementul
	ultim->urmator = newNod;
	newNod->anterior = ultim;
	ultim = newNod;
	size++;
	return true;
}

// AC: O(n)
// BC: Theta(1)
// WC: Theta(n)
bool Multime::sterge(TElem elem) {
	//daca elementul nu exista in lista
	if (!cauta(elem))
		return false;
	//elementul exista
	Nod* p = prim;
	while (p != nullptr)
	{
		if (p->element == elem)
			break;
		p = p->urmator;
	}
	// p - adresa nodului ce trebuie sters

	if (prim == ultim && prim == p)
	{
		delete p;
		prim = ultim = nullptr;
		size--;
		return true;
	}

	if (p == prim)
	{
		prim = prim->urmator;
		prim->anterior = nullptr;
		delete p;
		size--;
		return true;
	}

	if (p == ultim)
	{
		ultim = ultim->anterior;
		ultim->urmator = nullptr;
		delete p;
		size--;
		return true;
	}

	p->anterior->urmator = p->urmator;
	p->urmator->anterior = p->anterior;
	delete p;
	size--;
	return true;
}

// BC: Theta(1)
// WC: Theta(n)
// AC: O(n)
bool Multime::cauta(TElem elem) const {
	if (size == 0)
		return false;

	//daca lista nu e vida
	Nod* p = prim;
	while (p != nullptr)
	{
		if (p->element == elem)
			return true;
		p = p->urmator;
	}
	// daca nu gaseste elementul
	return false;
}


int Multime::dim() const {
	return size;
}

bool Multime::vida() const {
	if (size == 0)
		return true;
	else
		return false;
}


Multime::~Multime() {
	Nod* curent;
	curent = prim;
	while (curent != nullptr)
	{
		Nod* next = curent->urmator;
		delete curent;
		curent = next;
	}
	size = 0;
	prim = ultim = nullptr;
}


IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

