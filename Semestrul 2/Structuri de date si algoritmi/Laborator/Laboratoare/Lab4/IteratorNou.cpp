#include "IteratorNou.h"

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
IteratorValori::IteratorValori(const MDO& d, TCheie k) : dict(d) {
	this->cheie = k;
	index_cheie = -1;
	i = -1;

	// cautam indexul cheii date
	int current = d.prim;
	while (current > -1 && d.rel(d.elems[current].cheie, k))
	{
		if (k == d.elems[current].cheie)
		{
			index_cheie = current;
			break;
		}
		current = d.urm[current];
	}

	prim();
}

// Teta(1)
// daca nu exita cheia data vrem sa apara o exceptie.
void IteratorValori::prim() {
	if (index_cheie <= -1)
	{
		throw exception();
	}

	i = dict.elems[index_cheie].prim;
}

// Teta(1)
bool IteratorValori::valid() const {
	if (i > -1 && index_cheie > -1)
		return true;
	return false;
}

// Teta(1)
void IteratorValori::urmator() {
	if (!valid())
	{
		throw exception();
		return;
	}

	// trecem la urmatorul element din lista mica
	i = dict.elems[index_cheie].urm[i];
}

// Teta(1)
TValoare IteratorValori::element() const {
	if (!valid())
	{
		throw exception();
		return -1;
	}

	// returnam valoarea
	return dict.elems[index_cheie].elems[i].second;
}
