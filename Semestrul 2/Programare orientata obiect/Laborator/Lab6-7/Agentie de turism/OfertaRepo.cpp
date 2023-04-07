#include "OfertaRepo.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

using std::ostream;
using std::stringstream;
using std::cout;
using std::string;
using std::exception;
//using std::vector;

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
    if(!exist(o))
        throw OfertaRepoException("Nu se poate sterge o oferta ce nu exista!!\n");
    for(unsigned int i = 0; i<all.size(); i++) {
        if(all[i].getDestinatie() == o.getDestinatie()) {
            all.erase(all.begin()+i);
        }
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

const vector<Oferta>& OfertaRepo::getAll() const noexcept {
    return all;
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




