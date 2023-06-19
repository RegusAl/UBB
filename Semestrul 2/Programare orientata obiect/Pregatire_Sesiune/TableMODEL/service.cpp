#pragma once
#include "service.h"

void Service::adaugare(int id, string nume, string tip) {
    repository.adaugare(Entitate(id, nume, tip));
}

void Service::stergere(int id, string nume, string tip) {
    repository.stergere(Entitate(id, nume, tip));
}
