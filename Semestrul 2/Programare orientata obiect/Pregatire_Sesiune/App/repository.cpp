#pragma once
#include <sstream>
#include "repository.h"

void Repository::loadFromFile() {
    all.clear();
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        int id;
        string titlu, tip;
        double pret;
        string curent;
        stringstream linestream(line);
        int nr = 0;
        while(getline(linestream, curent, ',')) {
            if(nr == 0) {
                id = stoi(curent);
            }
            if(nr == 1) {
                titlu = curent;
            }
            if(nr == 2) {
                tip = curent;
            }
            if(nr == 3) {
                pret = stod(curent);
            }
            nr++;
        }
        all.push_back(Produs(id, titlu, tip, pret));
    }
    fin.close();
}

void Repository::saveToFile(vector<Produs> produse) {
    ofstream fout(fileName);
    for(auto &p : produse) {
        fout<<p.get_id()<<","<<p.get_titlu()<<","<<p.get_tip()<<","<<p.get_pret()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Produs p) {
    all.push_back(p);
    saveToFile(all);
}
