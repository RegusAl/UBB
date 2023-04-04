#include "AgentieService.h"

void AgentieService::adaugaOferta(const std::string &denumire, const std::string destinatie, const std::string tip,
                                  float pret) {
    Oferta o{denumire, destinatie, tip, pret};
    Repo.adauga(o);
}


