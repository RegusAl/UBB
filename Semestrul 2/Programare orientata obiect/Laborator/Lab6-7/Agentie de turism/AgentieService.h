#pragma once

#include "Oferta.h"
#include "OfertaRepo.h"

#include <string>
#include <vector>

using std::vector;

class AgentieService {
    OfertaRepo& Repo;
public:
    AgentieService(OfertaRepo& repo):Repo{repo}{}

    AgentieService(const AgentieService& ot) = delete;

    const vector<Oferta>& getAll() noexcept {
        return Repo.getAll();
    }

    void adaugaOferta(const string& denumire, const string destinatie, const string tip, float pret);

};