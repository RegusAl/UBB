#include <string>
#include "AgentieService.h"

void AgentieService::adaugaOferta(const std::string &denumire, const std::string &destinatie, const std::string tip, float pret) {
    Oferta o{denumire, destinatie, tip, pret};
    Repo.adauga(o);
}

void AgentieService::modificaOferta(string denumire, string destinatie, string tip, float pret)  {
    Oferta o = Repo.cauta(denumire, destinatie);
    o.setTip(tip);
    o.setPret(pret);
}

void AgentieService::stergereOferta(string denumire, string destinatie) {
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
}


