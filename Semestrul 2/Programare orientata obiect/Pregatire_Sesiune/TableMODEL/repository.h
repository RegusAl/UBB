#pragma once
#include "domain.h"

class Repository {
private:
    vector<Entitate> all;
    string fileName;
    void loadFromFile();
public:

    Repository(string filename) : fileName(filename) {
        loadFromFile();
    }

    void saveToFile(vector<Entitate> entitati);

    vector<Entitate> getAll() {
        return all;
    }

    void adaugare(Entitate e);

    void stergere(Entitate e);

};