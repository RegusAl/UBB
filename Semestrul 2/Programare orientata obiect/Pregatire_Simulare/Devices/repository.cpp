#include "repository.h"

void Repository::loadFromFile() {
    ifstream fin(fileName);
    if(!fin.is_open()) throw exception();
    while(!fin.eof()) {
        string tip, model, culoare;
        int an, pret;
        fin>>tip;
        fin>>model;
        fin>>an;
        fin>>culoare;
        fin>>pret;
        Device device(tip, model, an, culoare, pret);
        all.push_back(device);
    }
    fin.close();
}

