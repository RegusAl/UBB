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
    vector<Oferta> all;
    bool exist(const Oferta& o) const;
public:
    OfertaRepo() = default;
    OfertaRepo(const OfertaRepo& o) = delete;

    // adaugare Oferta
    void adauga(const Oferta& o);

    // stergere Oferta
    void stergere(Oferta& o);

    // cautare Oferta
    const Oferta& cauta(const string& denumire, const string& destinatie) const;

    // getAll Oferte

    vector<Oferta>& getAll() {
        return all;
    }


//    Oferta* begin();
//    Oferta* end();
};

class OfertaRepoException {
    string msj;
public:
    explicit OfertaRepoException(string m): msj{std::move( std::move(m) )} {}
    friend ostream& operator<<(ostream& out, const OfertaRepoException& ex);
};

ostream& operator<<(ostream& out, const OfertaRepoException& ex);
