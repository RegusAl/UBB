#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "AgentieService.h"

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
     const vector<Oferta>& oferte = getAll();
     vector<Oferta> oferteFiltrate;
     std::copy_if(oferte.begin(), oferte.end(), back_inserter(oferteFiltrate), [destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
     return oferteFiltrate;
}

vector<Oferta> AgentieService::filtrarePret(int pret) {
    const vector<Oferta>& oferte = getAll();
    vector<Oferta> oferteFiltrate;
    std::copy_if(oferte.begin(), oferte.end(), back_inserter(oferteFiltrate), [pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
    return oferteFiltrate;
}

vector<Oferta> AgentieService::sortByDenumire()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDenumire);
    return sortedCopy;
}

vector<Oferta> AgentieService::sortByDestinatie()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDestinatie);
    return sortedCopy;
}

vector<Oferta> AgentieService::sortByTipSiPret()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpTipPret);
    return sortedCopy;
}

void AgentieService::cosAdauga(string denumire, string destinatie) {
    const auto & oferta = Repo.cauta(denumire, destinatie);
    cosCurent.adaugaOfertaCos(oferta);
}

int AgentieService::cosAdaugaRandom(int howMany)
{
    cosCurent.adaugaOfertaRandomCos(this->getAll(), howMany);
    return cosCurent.getAllCos().size();
}

const vector<Oferta>& AgentieService::getAllCos()
{
    return cosCurent.getAllCos();
}

void AgentieService::cosSterge() {
    cosCurent.stergeCos();
}


