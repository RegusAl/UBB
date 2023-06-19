#pragma once

#include "repository.h"
#include "functional"
#include "algorithm"

class Service {
private:
    Repository &repository;
public:

    Service(Repository& repository) : repository(repository) {}

    vector<Tractor> getAll() {
        return sortare(repository.getAll());
    }

    vector<Tractor> sortare(vector<Tractor> tractoare);

    int nrTip(Tractor t);

    vector<string> getTipuri(vector<Tractor> tractoare);

    string adaugare(int id, string denumire, string tip, int numarRoti);
};