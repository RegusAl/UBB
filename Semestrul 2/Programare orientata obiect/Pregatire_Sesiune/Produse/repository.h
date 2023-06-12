#pragma once

#include "domain.h"
#include "vector"

class Repository {
private:
    vector<Produs> all;

    string fileName;
    void loadFromFile();
public:
    Repository(const Repository& ot) = delete;

    explicit Repository(string fileName) : fileName(fileName) {
        loadFromFile();
    }

    vector<Produs> getAll() {
        return all;
    }

    void saveToFile(vector<Produs> produse);

    void adaugare(Produs p);
};