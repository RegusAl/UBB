#include <string>
#include "AgentieService.h"


VectorDinamic<Oferta> AgentieService::filtrare(const function<bool (const Oferta &)>& fct) {
    VectorDinamic<Oferta> rez;
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

VectorDinamic<Oferta> AgentieService::filtrareDestinatie(const string& destinatie) {
     return filtrare([destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
}

VectorDinamic<Oferta> AgentieService::filtrarePret(int pret) {
    return filtrare([pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
}

VectorDinamic<Oferta> AgentieService::sortareOferte(Sort functieSortare) {
    VectorDinamic<Oferta> lista_sortata;
    VectorDinamic<Oferta> lista = Repo.getAll();
    for(int i = 0; i<lista.size(); i++) {
        lista_sortata.push_back(Oferta(lista.get(i)));
    }
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 0; i<lista_sortata.size()-1; i++) {
            if(functieSortare(lista_sortata.get(i), lista_sortata.get(i+1))>0) {
                Oferta aux = lista_sortata.get(i);
                lista_sortata.get(i) = lista_sortata.get(i+1);
                lista_sortata.get(i+1) = aux;
                sorted = false;
            }
        }
    }
    return lista_sortata;
}
