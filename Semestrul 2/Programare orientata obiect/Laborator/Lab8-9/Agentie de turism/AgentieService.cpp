#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "AgentieService.h"


vector<Oferta> AgentieService::filtrare(const function<bool (const Oferta &)>& fct) {
    vector<Oferta> rez;
    for(const auto& oferta:Repo.getAll()) {
        if(fct(oferta)) {
            rez.push_back(oferta);
        }
    }
    return (rez);
}

void AgentieService::adaugaOferta(const std::string &denumire, const std::string &destinatie, const std::string& tip, int pret) {
    Valid.validateOferta(denumire, destinatie, tip, pret);
    Oferta o{denumire, destinatie, tip, pret};
    Repo.adauga(o);
}

void AgentieService::modificaOferta(const string& denumire, const string& destinatie, const string& tip, int pret)  {
    Valid.validateOferta(denumire, destinatie, tip, pret);
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
    Oferta new_o{denumire, destinatie, tip, pret};
    Repo.adauga(new_o);
}

void AgentieService::stergereOferta(const string& denumire, const string& destinatie) {
    Valid.validateOferta(denumire, destinatie, "exemplu", 1);
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
}

vector<Oferta> AgentieService::filtrareDestinatie(const string& destinatie) {
     return filtrare([destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
}

vector<Oferta> AgentieService::filtrarePret(int pret) {
    return filtrare([pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
}

vector<Oferta> AgentieService::sortByDenumire()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDenumire); return sortedCopy;
}

vector<Oferta> AgentieService::sortByDestinatie()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDestinatie); return sortedCopy;
}

vector<Oferta> AgentieService::sortByTipSiPret()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpTipPret); return sortedCopy;
}


