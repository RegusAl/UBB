#pragma once
#include "Oferta.h"

#include <utility>
#include <vector>
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class OfertaRepo {
    vector <Oferta> all;
    vector <Oferta>::iterator getIterator(Oferta*);
    bool exist(const Oferta& o) const;
public:
    OfertaRepo() = default;
    OfertaRepo(const OfertaRepo& of) = delete;

    // adaugare Oferta
    void adauga(const Oferta& o);

    // stergere Oferta
    void stergere(Oferta& o);

    // cautare Oferta
    const Oferta& cauta(string denumire, string destinatie) const;

    // getAll Oferte
    const vector<Oferta>& getAll() const noexcept;

//    Oferta* begin();
//    Oferta* end();
};

class OfertaRepoException {
    string msj;
public:
    OfertaRepoException(string m): msj{ m } {}
    friend ostream& operator<<(ostream& out, const OfertaRepoException& ex);
};

ostream& operator<<(ostream& out, const OfertaRepoException& ex);
