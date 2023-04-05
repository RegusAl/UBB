#include <string>
#include <utility>
#include "AgentieService.h"

const vector<Oferta> AgentieService::getAll() noexcept {
    return Repo.getAll();
}

void AgentieService::adaugaOferta(const std::string &denumire, const std::string &destinatie, const std::string& tip, float pret) {
    Oferta o{denumire, destinatie, tip, pret};
    Repo.adauga(o);
}

void AgentieService::modificaOferta(const string& denumire, const string& destinatie, const string& tip, float pret)  {
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
    Oferta new_o{denumire, destinatie, tip, pret};
    Repo.adauga(new_o);
}

void AgentieService::stergereOferta(string denumire, string destinatie) {
    Oferta o = Repo.cauta(std::move(denumire), std::move(destinatie));
    Repo.stergere(o);
}

vector<Oferta> AgentieService::filtrare(function<bool(const Oferta &)> fct) {
    vector<Oferta> rez;
    for(const auto& oferta:Repo.getAll()) {
        if(fct(oferta)) {
            rez.push_back(oferta);
        }
    }
    return rez;
}

vector<Oferta> AgentieService::filtrareDestinatie(string destinatie) {
     return filtrare([destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
}

vector<Oferta> AgentieService::filtrarePret(float pret) {
    return filtrare([pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
}

