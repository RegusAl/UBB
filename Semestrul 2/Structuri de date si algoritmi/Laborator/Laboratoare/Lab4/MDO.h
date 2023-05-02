#pragma once

#include <vector>
#include <stdlib.h>

typedef int TCheie;
typedef int TValoare;

#include <utility>
typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;
class IteratorValori;
class MDO;

class lista {
public:
	int cp;				// capacitate memorare vectori
	int* urm;			// lista cu pozitiile elementelor urmatoare
	int* pre;
	int prim;			// primul element din colectie
	int primLiber;		// pozitia primului element liber
	TElem* elems;
	TCheie cheie;

	lista();
	lista(TCheie c);
	int aloca();
	void dealoca(int i);
	int creeazaNod(TElem el);
	void redim();
};

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
	friend class IteratorValori;
 private:
public:
		Relatie rel;
		int cp;				// capacitate memorare vectori
		int* urm;			// lista cu pozitiile elementelor urmatoare
		int* pre;
	    int prim;			// primul element din colectie
		int primLiber;		// pozitia primului element liber
		int len;			// numarul elementelor 
		lista* elems;

		int aloca();
		void dealoca(int i);
		int creeazaNod(TElem el);
		void redim();
    public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();
};
