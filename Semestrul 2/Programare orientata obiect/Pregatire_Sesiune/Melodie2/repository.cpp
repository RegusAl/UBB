#pragma once

#include <sstream>
#include "repository.h"

void Repository::loadFromFile() {
    all.clear();
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        int id;
        string titlu, artist, gen;
        stringstream linestream(line);
        string curent; // aici se va stoca cuvantul curent
        int nr = 0;
        while(getline(linestream, curent, ',')) {
            if(nr == 0)
                id = stoi(curent);
            if(nr == 1)
                titlu = curent;
            if(nr == 2)
                artist = curent;
            if(nr == 3)
                gen = curent;
            nr++;
        }
        all.push_back(Melodie(id, titlu, artist, gen));
    }
    fin.close();
}

void Repository::saveToFile(vector<Melodie> listaNoua) {
    ofstream fout(fileName);
    for(auto &m : listaNoua) {
        fout<<m.get_id()<<","<<m.get_titlu()<<","<<m.get_artist()<<","<<m.get_gen()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Melodie m) {
    all.push_back(m);
    saveToFile(all);
}

void Repository::stergere(int id) {
    auto lista = getAll();
    int i = 0;
    for(auto &m : getAll()) {
        if(id == m.get_id())
            break;
        i++;
    }
    all.erase(all.begin()+i);
    saveToFile(all);
}
