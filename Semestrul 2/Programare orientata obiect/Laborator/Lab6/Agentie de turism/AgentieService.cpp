#include <string>
#include "AgentieService.h"


vector<Oferta> AgentieService::filtrare(const function<bool(const Oferta &)>& fct) {
    vector<Oferta> rez;
    for(const auto& oferta:Repo.getAll()) {
        if(fct(oferta)) {
            rez.push_back(oferta);
        }
    }
    return (rez);
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

void AgentieService::stergereOferta(const string& denumire, const string& destinatie) {
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
}

vector<Oferta> AgentieService::filtrareDestinatie(const string& destinatie) {
     return filtrare([destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
}

vector<Oferta> AgentieService::filtrarePret(float pret) {
    return filtrare([pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
}

