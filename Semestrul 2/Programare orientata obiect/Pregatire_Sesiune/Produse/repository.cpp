#pragma once

#include "repository.h"
#include <fstream>
#include <sstream>

void Repository::loadFromFile() {
    all.clear();
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        string nume, tip;
        int id;
        double pret;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while(getline(linestream, curent, ',')) {
            if(nr == 0)
                id = stoi(curent);
            if(nr == 1)
                nume = curent;
            if(nr == 2)
                tip = curent;
            if(nr == 3)
                pret = stod(curent);
            nr++;
        }
        all.push_back(Produs(id, nume, tip, pret));
    }
    fin.close();
}

void Repository::saveToFile(vector<Produs> produse) {
    ofstream fout(fileName);
    for(auto &p : produse) {
        fout << p.get_id()<<","<< p.get_nume()<<","<<p.get_tip()<<","<<p.get_pret()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Produs p) {
    all.push_back(p);
    saveToFile(all);
}
