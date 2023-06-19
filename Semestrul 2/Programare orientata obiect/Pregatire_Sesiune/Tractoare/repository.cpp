#pragma once

#include <sstream>
#include "repository.h"
#include "fstream"

void Repository::loadFromFile() {
    all.clear();
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        int id, numarRoti;
        string denumire, tip;
        int nr = 0;
        stringstream linestream(line);
        string curent;
        while(getline(linestream, curent, ',')) {
            if(nr == 0) {
                id = stoi(curent);
            }
            if(nr == 1) {
                denumire = curent;
            }
            if(nr == 2) {
                tip = curent;
            }
            if(nr == 3) {
                numarRoti = stoi(curent);
            }
            nr++;
        }
        all.push_back(Tractor(id, denumire, tip, numarRoti));
    }
    fin.close();
}

void Repository::saveToFile(vector<Tractor> tractoare) {
    ofstream fout(fileName);
    for(auto &t : tractoare) {
        fout<<t.get_id()<<","<<t.get_denumire()<<","<<t.get_tip()<<","<<t.get_numarRoti()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Tractor t) {
    all.push_back(t);
    saveToFile(all);
}
