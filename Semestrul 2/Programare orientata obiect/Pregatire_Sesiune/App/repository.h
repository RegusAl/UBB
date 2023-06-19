#pragma once

#include "domain.h"
#include "fstream"

class Repository {
private:
    string fileName;
    vector<Produs> all;
    void loadFromFile();
public:

    Repository(const Repository& ot) = delete;

    explicit Repository(string fileName) : fileName(fileName) {
        loadFromFile();
    }

    void saveToFile(vector<Produs> produse);

    vector<Produs> getAll() {
        return all;
    }

    void adaugare(Produs p);
};