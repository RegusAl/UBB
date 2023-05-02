#pragma once

#include "MDO.h"

class IteratorValori {
	friend class MDO;
public:
	//contine o referinta catre containerul pe care il itereaza
	const MDO& dict;

	TCheie cheie;
	int i;
	int index_cheie;

public:

	IteratorValori(const MDO& d, TCheie k);

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TValoare element() const;

};
