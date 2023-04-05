#include "OfertaRepo.h"

#include <iostream>
#include <sstream>

using std::ostream;
using std::stringstream;
using std::cout;
using std::string;

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

const Oferta& OfertaRepo::cauta(string denumire, string destinatie) const {
    for(const auto& o : all) {
        if(o.getDenumire() == denumire && o.getDestinatie() == destinatie) {
            return o;
        }
    }
    throw OfertaRepoException("Nu exista oferta aceasta!");
}

const vector<Oferta>& OfertaRepo::getAll() const noexcept {
    return all;
}

ostream& operator<<(ostream& out, const OfertaRepoException& ex) {
    out<<ex.msj;
    return out;
}

