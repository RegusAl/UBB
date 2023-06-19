#pragma once
#include "domain.h"

#include "vector"

class Repository {
private:
    vector<Tractor> all;
    string fileName;
    void loadFromFile();
public:
    Repository(Repository &ot)  = delete;
    Repository(string fileName) : fileName(fileName) {
        loadFromFile();
    }

    vector<Tractor> getAll() {
        return all;
    }

    void saveToFile(vector<Tractor> tractoare);

    void adaugare(Tractor t);


};