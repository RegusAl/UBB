#include "OfertaRepo.h"

#include <iostream>
#include <sstream>
#include <exception>

using std::ostream;
using std::stringstream;
using std::cout;
using std::string;
using std::exception;

bool OfertaRepo::exist(const Oferta &o) const {
    try {
        cauta(o.getDenumire(), o.getDestinatie());
        return true;
    }
    catch (OfertaRepoException&) {
        return false;
    }
}

void OfertaRepo::adauga(const Oferta &o) {
    if(exist(o)) {
        throw OfertaRepoException("Exista deja o oferta de acest fel!\n");
    }
    all.push_back(o);
}

void OfertaRepo::stergere(Oferta &o) {
    int i = 0;
    while (i < this->all.size()) {
        if (all.at(i).getDenumire() == o.getDenumire() && all.at(i).getDestinatie() == o.getDestinatie()) {
            this->all.erase(this->all.begin() + i);
            break;
        }
        i++;
    }
}

const Oferta& OfertaRepo::cauta(const string& denumire, const string& destinatie) const {
    for(const auto& o : all) {
        if(o.getDenumire() == denumire && o.getDestinatie() == destinatie) {
            return o;
        }
    }
    throw OfertaRepoException("Nu exista oferta aceasta!");
}

ostream& operator<<(ostream& out, const OfertaRepoException& ex) {
    out<<ex.msj;
    return out;
}

//Oferta* OfertaRepo::begin() {
//    return all.begin().base();
//}
//
//Oferta* OfertaRepo::end() {
//    return all.end().base();
//}




