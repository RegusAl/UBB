#pragma once

#include <sstream>
#include "repository.h"
#include "fstream"

void Repository::loadFromFile() {
    all.clear();
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        int id;
        string nume, tip;
        int nr = 0;
        string curent;
        stringstream linestream(line);
        while(getline(linestream, curent, ',')) {
            if(nr == 0) {
                id = stoi(curent);
            }
            if(nr == 1) {
                nume = curent;
            }
            if(nr == 2) {
                tip = curent;
            }
            nr++;
        }
        Entitate e(id, nume, tip);
        all.push_back(e);
    }
    fin.close();
}



void Repository::saveToFile(vector<Entitate> entitati) {
    ofstream fout(fileName);
    for(auto &e : entitati) {
        fout<<e.getId()<<","<<e.getNume()<<","<<e.getTip()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Entitate e) {
    all.push_back(e);
    saveToFile(all);
}

void Repository::stergere(Entitate e) {
    int i = 0;
    for(auto &el : all) {
        if(el.getId() == e.getId() && el.getNume() == e.getNume() && el.getTip() == e.getTip()) {
            break;
        }
        i++;
    }
    all.erase(all.begin()+i);
    saveToFile(all);
}
