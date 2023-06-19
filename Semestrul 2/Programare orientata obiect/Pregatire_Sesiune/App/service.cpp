#pragma once

#include <algorithm>
#include "service.h"

void Service::adaugare(int id, string titlu, string tip, double pret) {
    repository.adaugare(Produs(id, titlu, tip, pret));
}

vector<Produs> Service::sortare(vector<Produs> produse) {
    sort(produse.begin(), produse.end(), [this](Produs &p1, Produs &p2) {
        return p1.get_pret() < p2.get_pret();
    });
    return produse;
}
