#include "OfertaRepo.h"

#include <iostream>
#include <sstream>
#include <exception>
#include <functional>
#include <algorithm>
#include <fstream>

using std::ostream;
using std::stringstream;
using std::cout;
using std::string;
using std::exception;

bool OfertaRepo::exist(const Oferta &o) {
    try {
        cauta(o.getDenumire(), o.getDestinatie());
        return true;
    }
    catch (OfertaRepoException &) {
        return false;
    }
}

void OfertaRepo::adauga(const Oferta &o) {
    if (exist(o)) {
        throw OfertaRepoException("Exista deja o oferta de acest fel!\n");
    }
    all.push_back(o);
}

void OfertaRepo::stergere(const Oferta &o) {
    int i = 0;
    while (i < this->all.size()) {
        if (all.at(i).getDenumire() == o.getDenumire() && all.at(i).getDestinatie() == o.getDestinatie()) {
            this->all.erase(this->all.begin() + i);
            break;
        }
        i++;
    }
}

const Oferta &OfertaRepo::cauta(string denumire, string destinatie) {
    auto f = std::find_if(this->all.begin(), this->all.end(), [=](const Oferta &o) {
        return (o.getDenumire() == denumire && o.getDestinatie() == destinatie);
    });
    if (f != this->all.end())
        return (*f);
    else
        throw OfertaRepoException("Oferta nu exista!\n");
}

void OfertaRepoFile::loadFromFile() {
    std::ifstream in(fileName);
    if (!in.is_open()) throw OfertaRepoException("Eroare la deschiderea fisierului!!!");
    while (!in.eof()) {
        string denumire, destinatie, tip;
        int pret;
        if (in.eof()) break;
        in >> denumire;
        if (in.eof()) break;
        in >> destinatie;
        if (in.eof()) break;
        in >> tip;
        if (in.eof()) break;
        in >> pret;
        Oferta o{denumire, destinatie, tip, pret};
        OfertaRepo::adauga(o);
    }
    in.close();
}

void OfertaRepoFile::writeToFile() {
    std::ofstream out(fileName);
    if (!out.is_open()) throw OfertaRepoException("Eroare la deschiderea fisierului!!!");
    for (auto &o: OfertaRepo::getAll()) {
        out << o.getDenumire();
        out << std::endl;
        out << o.getDestinatie();
        out << std::endl;
        out << o.getTip();
        out << std::endl;
        out << o.getPret();
        out << std::endl;
    }
    out.close();
}

ostream &operator<<(ostream &out, const OfertaRepoException &ex) {
    out << ex.msj;
    return out;
}

//Oferta* OfertaRepo::begin() {
//    return all.begin().base();
//}
//
//Oferta* OfertaRepo::end() {
//    return all.end().base();
//}







