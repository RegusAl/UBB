#pragma once;
#include "IteratorColectie.h"

typedef int TElem;

struct Pereche {
    TElem valoare;
    int frecventa;
};

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:

    int cp; // capacitatea
    int n;  // numarul de elemente
    Pereche* e;
    int cautareBinara(Pereche* pereche, int stanga, int dreapta, TElem element, bool& gasit) const;
    void redim();

public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;

		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

        // elimină nr apariții ale elementului elem. În cazul în care elementul apare mai puțin de nr ori, toate aparițiile sale vor fi eliminate.
        // returnează numărul de apariții eliminate ale elementului.
        // aruncă excepție în cazul în care este nr este negativ.
        int eliminaAparitii(int nr, TElem elem);

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();
};

