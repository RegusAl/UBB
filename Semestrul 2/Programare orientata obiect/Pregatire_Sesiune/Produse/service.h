#pragma once

#include "repository.h"
#include "observer.h"

class Service : public Observable{
private:
    Repository &repository;
public:

    explicit Service(Repository& repository) : repository(repository) {}

    vector<Produs> getAll() {
        return sortare(repository.getAll());
    }

//    int numarVocale(string nume);

    vector<Produs> sortare(vector<Produs> produse);

    string adaugare(int id, const string& nume, const string& tip, double pret);

    int nr_tipuri(string tip);

    map<string, int> get_tipuri();

};