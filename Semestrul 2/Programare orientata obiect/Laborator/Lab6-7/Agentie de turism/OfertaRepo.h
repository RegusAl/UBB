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
    bool exist(const Oferta& o) const;
public:
    OfertaRepo() = default;

    OfertaRepo(const OfertaRepo& of) = delete;

    // adaugare Oferta
    void adauga(const Oferta& o);

    const Oferta& cauta(string denumire, string destinatie) const;

    const vector<Oferta>& getAll() const noexcept;
};

class OfertaRepoException {
    string msj;
public:
    OfertaRepoException(string m): msj{ m } {}
    friend ostream& operator<<(ostream& out, const OfertaRepoException& ex);
};

ostream& operator<<(ostream& out, const OfertaRepoException& ex);

