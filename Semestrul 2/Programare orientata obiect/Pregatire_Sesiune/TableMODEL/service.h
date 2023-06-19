#pragma once
#include "repository.h"

class Service {
private:
    Repository& repository;
public:
    Service(Repository& repo) : repository{repo} {}

    Service(const Service &service) : repository{service.repository} {}

    vector<Entitate> getAll() {
        return repository.getAll();
    }

    void adaugare(int id, string nume, string tip);

    void stergere(int id, string nume, string tip);


};