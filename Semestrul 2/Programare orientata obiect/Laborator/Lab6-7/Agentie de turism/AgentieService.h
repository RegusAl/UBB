#pragma once

#include "Oferta.h"
#include "OfertaRepo.h"

#include <string>
#include <vector>
#include <functional>

using std::vector;
using std::string;
using std::function;

class AgentieService {
    OfertaRepo& Repo;
    vector<Oferta> filtrare(const function<bool(const Oferta&)>& fct);
public:
    explicit AgentieService(OfertaRepo& repo):Repo{repo}{}
    AgentieService() = delete;
    AgentieService(const AgentieService& ot) = delete;

    vector<Oferta> getAll() noexcept;

    void adaugaOferta(const string& denumire, const string& destinatie, const string& tip, float pret);
    void modificaOferta(const string& denumire, const string& destinatie, const string& tip, float pret);
    void stergereOferta(const string& denumire, const string& destinatie);
    vector<Oferta> filtrareDestinatie(const string& destinatie);
    vector<Oferta> filtrarePret(float pret);
};


