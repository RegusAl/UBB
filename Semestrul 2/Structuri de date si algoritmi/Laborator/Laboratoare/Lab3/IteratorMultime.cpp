#include "IteratorMultime.h"
#include "Multime.h"

IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	curent = m.prim;
}

void IteratorMultime::prim() {
	curent = multime.prim;
}

void IteratorMultime::urmator() {
    if(this->valid())
	    curent = curent->urmator;
    else throw std::exception();
}

TElem IteratorMultime::element() const {
    if(this->valid())
	    return curent->element;
    else
        throw std::exception();
}

bool IteratorMultime::valid() const {
	return curent != nullptr;
}
