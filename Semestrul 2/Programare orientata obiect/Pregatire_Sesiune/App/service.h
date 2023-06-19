#pragma once

#include "repository.h"

class Service {
private:
    Repository &repository;
public:

    explicit Service(Repository& repository) : repository(repository) {}

    vector<Produs> getAll() {
        return sortare(repository.getAll());
    }

    void adaugare(int id, string titlu, string tip, double pret);

    vector<Produs> sortare(vector<Produs> produse);
};