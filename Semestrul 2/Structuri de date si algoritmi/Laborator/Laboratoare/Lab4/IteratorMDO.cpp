#include "IteratorMDO.h"

// Teta(1)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	// Constructor
	prim();
}

// Teta(1)
void IteratorMDO::prim(){
	// Resetam iteratorul
	i = this->dict.prim;
	if(i > -1)
		j = this->dict.elems[i].prim;
}

// Teta(1)
void IteratorMDO::urmator(){
	// trecem la urmatorul element din lista
	if (!this->valid()) // daca dictionarul nu este valid
	{
		throw exception();
//		return;
	}
	j = this->dict.elems[i].urm[j];
	if (j == -1 || j == this->dict.elems[i].primLiber) // daca ajungem la finalul listei
	{
		i = this->dict.urm[i];
		if(i != -1)
			j = this->dict.elems[i].prim;
	}
	
}

// Teta(1)
bool IteratorMDO::valid() const{
	// Verificam daca iteratorul este valid
	if(i == -1 || j == -1)
		return false;
	if(i >= 0 && j >= 0 && dict.cp > i && dict.elems[i].cp > j && i != dict.primLiber && j != dict.elems[i].primLiber)
		return true;
	return false;
}

// Teta(1)
pair <TCheie, TValoare> IteratorMDO::element() const{
	// returnam elementul actual
	if (!this->valid())
		throw exception();
	return this->dict.elems[i].elems[j];
}


