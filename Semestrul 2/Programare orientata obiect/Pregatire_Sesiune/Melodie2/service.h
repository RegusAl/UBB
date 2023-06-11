#pragma once

#include "repository.h"

class Service {
private:
    Repository& repository ;
public:
    Service(class Repository& repository) : repository(repository) {};

    static vector<Melodie> sortare(vector<Melodie> nesortate);

    vector<Melodie> getAll() {
        return sortare(repository.getAll());
    }

    void adaugare(string titlu, string artist, string gen);

    void stergere(int id);

    int acelasiArtist(Melodie m);

    int acelasiGen(Melodie m);
};