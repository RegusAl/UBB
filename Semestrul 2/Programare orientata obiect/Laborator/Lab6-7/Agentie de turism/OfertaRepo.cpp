#include "OfertaRepo.h"

#include <iostream>
#include <sstream>

using std::ostream;
using std::stringstream;
using std::cout;
using std::string;

bool OfertaRepo::exist(const Oferta &o) const {
        cauta(o.getDenumire(), o.getDestinatie());
        return true;
}

void OfertaRepo::adauga(const Oferta &o) {
    if(exist(o)) {
        std::cout<<"Exista deja o oferta  "<<o.getTip();
    }
    else
        all.push_back(o);
}

const Oferta& OfertaRepo::cauta(string denumire, string destinatie) const {
    for(const auto& o : all) {
        if(o.getDenumire() == denumire && o.getDestinatie() == destinatie) {
            return o;
        }
    }
    cout<<"Nu exista oferta aceasta!";
}

const vector<Oferta>& OfertaRepo::getAll() const noexcept {
    return all;
}


