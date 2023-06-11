#pragma once

#include "domain.h"
#include <fstream>

#include "vector"

class Repository {
private:
    vector<Melodie> all;
    string fileName;
    void loadFromFile();
public:
    Repository(Repository &ot)  = delete;
    Repository(string fileName) : fileName(fileName) {
        loadFromFile();
    }

    void saveToFile(vector<Melodie> listaNoua);

    vector<Melodie> getAll() {
        return all;
    }

    void adaugare(Melodie m);

    void stergere(int id);
};