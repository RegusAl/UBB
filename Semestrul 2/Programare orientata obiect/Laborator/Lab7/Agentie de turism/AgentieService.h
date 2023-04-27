#pragma once

#include "Oferta.h"
#include "OfertaRepo.h"
#include "Validator.h"

#include <string>
//#include <vector>
#include <functional>
#include "VectorDinamic.h"

//using std::vector;
using std::string;
using std::function;

//typedef bool(*Compare)(const Oferta&, const string&);
typedef int(*Sort)(const Oferta&, const Oferta&);

class AgentieService {
    OfertaRepo& Repo;
    Validator& Valid;
    VectorDinamic<Oferta> filtrare(const function<bool(const Oferta&)>& fct);
public:
    explicit AgentieService(OfertaRepo& repo, Validator& valid):Repo{repo}, Valid{valid} {}
    AgentieService() = delete;
    AgentieService(const AgentieService& ot) = delete;

    VectorDinamic<Oferta>& getAll() noexcept {
        return Repo.getAll();
    }

    void adaugaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);
    void modificaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);
    void stergereOferta(const string& denumire, const string& destinatie);
    VectorDinamic<Oferta> filtrareDestinatie(const string& destinatie);
    VectorDinamic<Oferta> filtrarePret(int pret);

    VectorDinamic<Oferta> sortareOferte(Sort functieSortare);
};


