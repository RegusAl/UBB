#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
#include <unordered_map>

using namespace std;

// Teta(1)
lista::lista() {
	this->prim = -1;
	this->primLiber = -1;
	this->cp = 0;
}

// Teta(1)
lista::lista(TCheie c)
{
	this->cheie = c;
	this->prim = -1;
	this->primLiber = 0;
	this->cp = 2;

	this->elems = new TElem[cp];
	urm = new int[cp];
	pre = new int[cp];

	// completam vectorul de pozitii ca fiind liber
	for (int i = 0; i < cp - 1; i++)
	{
		urm[i] = i + 1;
		pre[i] = -1;
	}
	urm[cp - 1] = -1;
	pre[cp - 1] = -1;
}

// Teta(1)
// Marcheaza un nod din lista ca fiind ocupat
// Complexitate: Theta(1)
// Returneaza pozitia nodului ce a fost marcat ca ocupat
int lista::aloca()
{
	int i = primLiber;			 // primul nod liber va fi ocupat
	primLiber = urm[primLiber];  // primulLiber va fi urmatorul nod
	return i;
}

// Teta(1)
// Marcheaza un nod dat ca fiind liber
// Complexitate: Theta(1)
void lista::dealoca(int i)
{
	urm[i] = primLiber;  // actualul primLiber se muta pe poz urmatoare
	pre[primLiber] = i;
	primLiber = i;		 // actualizam primLiber
}

// Creeaza un nou nod in lista cu valoarea elementului dat
// Complexitate: Theta(1)
// returneaza pozitia din vector unde s-a creat nodul
int lista::creeazaNod(TElem el)
{
	if (primLiber == -1)	// daca nu mai avem noduri libere
		redim();			// redimensionam vectorii

	int i = aloca();		// alocam spatiu pentru noul nod
 
	elems[i] = el;		// punem elementul pe pozitia alocata

	if(prim != -1)
		pre[prim] = i;
	urm[i] = prim;
	prim = i;
	pre[i] = -1;

	return i;				// returnam pozitia unde s-a creat nodul
}

// Mareste capacitatea de stocare a vectorilor asociati implementarii colectiei
// Complexitate: Theta(n)
void lista::redim()
{
	int cp_nou = cp * 2;	// dublam capacitatea
	TElem* elem_nou = new TElem[cp_nou];
	int* urm_nou = new int[cp_nou];
	int* pre_nou = new int[cp_nou];

	// copiem toate elementele din vectorii actuali in cei noi
	for (int i = 0; i < cp; ++i)
	{
		elem_nou[i] = elems[i];
		urm_nou[i] = urm[i];
		pre_nou[i] = pre[i];
	}

	// marcam toate pozitiile noi adaugate ca facand 
	// parte din vectorul de pozitii libere fiind consecutive
	for (int i = cp; i < cp_nou - 1; ++i)
	{
		urm_nou[i] = i + 1;
		pre_nou[i] = -1;
	}
	urm_nou[cp_nou - 1] = -1;  // ultima pozitie nu are niciun succesor
	pre_nou[cp_nou - 1] = -1;

	this->primLiber = cp;	   // setam primLiber la primul element nou dupa redim

	//delete[] elems;
	delete[] urm;
	delete[] pre;

	// actualizam proprietatile colectiei
	this->elems = elem_nou;
	this->urm = urm_nou;
	this->cp = cp_nou;
}

// Marcheaza un nod din lista ca fiind ocupat
// Complexitate: Theta(1)
// returneaza pozitia nodului ce a fost marcat ca ocupat
int MDO::aloca()
{
	int i = primLiber;			 // primul nod liber va fi ocupat
	primLiber = urm[primLiber];  // primulLiber va fi urmatorul nod
	return i;
}

// Marcheaza un nod dat ca fiind liber
// Complexitate: Theta(1)
void MDO::dealoca(int i)
{
	urm[i] = primLiber;  // actualul primLiber se muta pe poz urmatoare
	pre[primLiber] = i;
	primLiber = i;		 // actualizam primLiber
}

// Creeaza un nou nod in lista cu valoarea elementului dat
// Complexitate: Theta(1) amortizat
//  Pozitia din vector unde s-a creat nodul
int MDO::creeazaNod(TElem el)
{
	if (primLiber == -1)	// daca nu mai avem noduri libere
		redim();			// redimensionam vectorii

	int i = aloca();		// alocam spatiu pentru noul nod


	lista list(el.first);
	elems[i] = list;		// punem elementul pe pozitia alocata
	elems[i].creeazaNod(el);

	return i;				// returnam pozitia unde s-a creat nodul
}

// Mareste capacitatea de stocare a vectorilor asociati implementarii
// Complexitate: Theta(n)
void MDO::redim()
{
	int cp_nou = cp * 2;	// dublam capacitatea
	lista* elem_nou = new lista[cp_nou];
	int* urm_nou = new int[cp_nou];
	int* pre_nou = new int[cp_nou];

	// copiem toate elementele din vectorii actuali in cei noi
	for (int i = 0; i < cp; ++i)
	{
		elem_nou[i] = elems[i];
		urm_nou[i] = urm[i];
		pre_nou[i] = pre[i];
	}

	// marcam toate pozitiile noi adaugate ca facand 
	// parte din vectorul de pozitii libere fiind consecutive
	for (int i = cp; i < cp_nou - 1; ++i)
	{
		urm_nou[i] = i + 1;
		pre_nou[i] = -1;
	}
	urm_nou[cp_nou - 1] = -1;  // ultima pozitie nu are niciun succesor

	this->primLiber = cp;	   // setam primLiber la primul element nou dupa redim

	//delete[] elems;
	//delete[] urm;

	// actualizam proprietatile colectiei
	this->elems = elem_nou;
	this->urm = urm_nou;
	this->cp = cp_nou;
}


// Teta(1)
MDO::MDO(Relatie r) {
	this->len = 0;
	this->rel = r;
	this->prim = -1;
	this->primLiber = 0;
	this->cp = 2;

	this->elems = new lista[cp];
	urm = new int[cp];
	pre = new int[cp];

	// completam vectorul de pozitii ca fiind liber
	for (int i = 0; i < cp - 1; i++)
	{
		urm[i] = i + 1;
		pre[i] = -1;
	}
	urm[cp - 1] = -1;
	pre[cp - 1] = -1;
	prim = -1;
	primLiber = 0;
}

// caz favoranil : Teta(1)
// caz defavorabil : Teta(n)
// caz mediu : Teta(n)
// overall case : O(n)
void MDO::adauga(TCheie c, TValoare v) {

	if (this->prim == -1) // daca dictionarul e vid
	{
		TElem element_auxiliar;
		element_auxiliar.first = c;
		element_auxiliar.second = v;
		int i = this->creeazaNod(element_auxiliar);

		if (prim != -1)
			pre[prim] = i;
		urm[i] = prim;
		prim = i;
		pre[i] = -1;
		this->len = 1;
		return;
	}

	int anterior = -1;
	int current = prim;
	while (current != -1 && rel(this->elems[current].cheie, c))
	{
		if (this->elems[current].cheie == c)
		{
			TElem element_auxiliar;
			element_auxiliar.first = c;
			element_auxiliar.second = v;
			this->elems[current].creeazaNod(element_auxiliar);
			this->len++;
			return;
		}

		anterior = current;
		current = urm[current];
	}

	if (current <= -1)
	{
		TElem element_auxiliar;
		element_auxiliar.first = c;
		element_auxiliar.second = v;
		int i = this->creeazaNod(element_auxiliar);
		this->len++;
		urm[anterior] = i;
		pre[i] = anterior;
		urm[i] = -1;
		return;
	}
	else if (this->elems[current].cheie == c)
	{
		TElem element_auxiliar;
		element_auxiliar.first = c;
		element_auxiliar.second = v;
		this->elems[current].creeazaNod(element_auxiliar);
		this->len++;
		return;
	}
	else if (!rel(this->elems[current].cheie, c))
	{
		TElem element_auxiliar;
		element_auxiliar.first = c;
		element_auxiliar.second = v;
		int i = this->creeazaNod(element_auxiliar);

		if(anterior > -1)
			urm[anterior] = i;
		pre[i] = anterior;
		urm[i] = current;
		pre[current] = i;
		if (anterior == -1)
			this->prim = i;
		this->len++;
		return;
	}
}


// caz favoranil : Teta(1)
// caz defavorabil : Teta(n)
// caz mediu : Teta(n)
// overall case : O(n)
vector<TValoare> MDO::cauta(TCheie c) const {
	//cauta o cheie si returneaza vectorul de valori asociate

	vector<TValoare> v;

	int current = prim;
	while (current != -1 && rel(this->elems[current].cheie, c))
	{
		if (this->elems[current].cheie == c)
		{
			// adaugam toate valorile
			int first_elem = this->elems[current].prim;
			while (first_elem != -1)
			{
				v.push_back(this->elems[current].elems[first_elem].second);
				first_elem = this->elems[current].urm[first_elem];
			}
			return v;
		}
		current = urm[current];
	}

	return v;
}

// caz favoranil : Teta(1)
// caz defavorabil : Teta(n)
// caz mediu : Teta(n)
// overall case : O(n)
bool MDO::sterge(TCheie c, TValoare v) {

	// cautam dupa cheie apoi dupa valoare

	if(prim == -1) // daca e gol
		return false;

	int current = prim;

	if (c == elems[current].cheie)
	{
		int first_elem = this->elems[current].prim;
		while (first_elem != -1)
		{
			if (this->elems[current].elems[first_elem].second == v)
			{
				if (this->elems[current].pre[first_elem] > -1)
					this->elems[current].urm[this->elems[current].pre[first_elem]] = this->elems[current].urm[first_elem];

				if (this->elems[current].urm[first_elem] > -1)
					this->elems[current].pre[this->elems[current].urm[first_elem]] = this->elems[current].pre[first_elem];
				
				if (this->elems[current].prim == first_elem)
					this->elems[current].prim = this->elems[current].urm[first_elem];

				this->elems[current].dealoca(first_elem);

				if (this->elems[current].prim == -1)
				{
					if (this->pre[current] > -1)
						this->urm[this->pre[current]] = this->urm[current];
					if (this->urm[current] > -1)
						this->pre[this->urm[current]] = this->pre[current];

					this->prim = this->urm[current];
					this->dealoca(current);
				}
				this->len--;
				return true;
			}
			first_elem = this->elems[current].urm[first_elem];
		}
		return false;
	}

	current = urm[current];
	while (current != -1 && rel(this->elems[current].cheie, c))
	{
		if (this->elems[current].cheie == c)
		{
			int first_elem = this->elems[current].prim;
			while (first_elem != -1)
			{
				if (this->elems[current].elems[first_elem].second == v)
				{
					if (this->elems[current].pre[first_elem] > -1)
						this->elems[current].urm[this->elems[current].pre[first_elem]] = this->elems[current].urm[first_elem];
					
					if (this->elems[current].urm[first_elem] > -1)
						this->elems[current].pre[this->elems[current].urm[first_elem]] = this->elems[current].pre[first_elem];
					
					if (this->elems[current].prim == first_elem)
						this->elems[current].prim = this->elems[current].urm[first_elem];

					this->elems[current].dealoca(first_elem);
					if (this->elems[current].prim == -1)
					{
						if (this->pre[current] > -1)
							this->urm[this->pre[current]] = this->urm[current];
						if (this->urm[current] > -1)
							this->pre[this->urm[current]] = this->pre[current];

						this->dealoca(current);
					}
					this->len--;
					return true;
				}
				first_elem = this->elems[current].urm[first_elem];
			}
			return false;
		}
		current = urm[current];
	}

	return false; // daca nu gasim cheia
}

// Teta(1)
int MDO::dim() const {
	// returnam dimensiunea
	return this->len;
}

// Teta(1)
bool MDO::vid() const {
	// returnam true daca dictionarul este vid
	return this->len == 0; // sau prim == -1
}

// Teta(1)
IteratorMDO MDO::iterator() const {
	// se returneaza iterator pe dictionar
	return IteratorMDO(*this);
}


// Teta(1)
MDO::~MDO() {
	//delete[] urm;
	//delete[] pre;
}

