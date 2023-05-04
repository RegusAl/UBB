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

    bool exist(const Oferta &o) const;

public:
    OfertaRepo() = default;

    OfertaRepo(const OfertaRepo &o) = delete;

    /*
     * Adauga o oferta in lista de oferte
     * @param o: oferta ce se adauga (Oferta)
     */
    void adauga(const Oferta &o);

    /*
     * Sterge oferta o transmisa ca parametru
     * @param o: oferta ce se sterge (Oferta)
     */
    void stergere(Oferta &o);

    /*
     * Cauta o oferta dupa denumire si destinatie
     * @param denumire: denumirea dupa care se cauta
     * @param destinatie: destinatia dupa care se cauta
     * @throws:
     *  Exception - daca oferta cautata nu exista
     * @return: oferta cautata
     */
    const Oferta &cauta(const string &denumire, const string &destinatie) const;

    /*
     * Lista de oferta
     * @return: lista de oferte
     */
    vector<Oferta> &getAll() {
        return all;
    }


//    Oferta* begin();
//    Oferta* end();
};

class OfertaRepoException {
    string msj;
public:
    explicit OfertaRepoException(string m) : msj{std::move(std::move(m))} {}

    friend ostream &operator<<(ostream &out, const OfertaRepoException &ex);
};

ostream &operator<<(ostream &out, const OfertaRepoException &ex);

