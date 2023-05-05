#pragma once

#include "Oferta.h"

#include <utility>
#include <vector>
#include <string>
#include <ostream>
#include <fstream>

using std::vector;
using std::string;
using std::ostream;

// clasa de repo pur abstracta
class Repo {
public:
    Repo() = default;

    Repo(const Repo &o) = delete;

    // adauga oferta
    virtual void adauga(const Oferta &o) = 0;

    // sterge oferta
    virtual void stergere(const Oferta &o) = 0;

    // cauta oferta
    virtual const Oferta &cauta(string denumire, string destinatie) = 0;
    
    virtual vector<Oferta> &getAll() = 0;

//    virtual bool exist(const Oferta &o) = 0;
};

class OfertaRepo : public Repo {
private:
    vector<Oferta> all;

    bool exist(const Oferta &o);

public:
    OfertaRepo() = default;

    OfertaRepo(const OfertaRepo &o) = delete;

    /*
     * Adauga o oferta in lista de oferte
     * @param o: oferta ce se adauga (Oferta)
     */
    void adauga(const Oferta &o) override;

    /*
     * Sterge oferta o transmisa ca parametru
     * @param o: oferta ce se sterge (Oferta)
     */
    void stergere(const Oferta &o) override;

    /*
     * Cauta o oferta dupa denumire si destinatie
     * @param denumire: denumirea dupa care se cauta
     * @param destinatie: destinatia dupa care se cauta
     * @throws:
     *  Exception - daca oferta cautata nu exista
     * @return: oferta cautata
     */
    const Oferta &cauta(string denumire, string destinatie) override;

    /*
     * Lista de oferta
     * @return: lista de oferte
     */
    vector<Oferta> &getAll() override {
        return all;
    }


//    Oferta* begin();
//    Oferta* end();
};

class OfertaRepoFile : public OfertaRepo {
private:
    string fileName;

    void loadFromFile();

    void writeToFile();

public:
    OfertaRepoFile(string fileName) : OfertaRepo(), fileName{fileName} {
        loadFromFile();
    }

    void adauga(const Oferta &o) override {
        OfertaRepo::adauga(o);
        writeToFile();
    }

    void stergere(const Oferta &o) override {
        OfertaRepo::stergere(o);
        writeToFile();
    }
};


class OfertaRepoException {
    string msj;
public:
    explicit OfertaRepoException(string m) : msj{std::move(std::move(m))} {}

    friend ostream &operator<<(ostream &out, const OfertaRepoException &ex);
};

ostream &operator<<(ostream &out, const OfertaRepoException &ex);

