#pragma once
#include "repo.h"
#include <fstream>
#include <sstream>

void Repo::load_from_file() {
    m.clear();
    ifstream fin(filename);
    string line;
    while(getline(fin, line)) {
        string titlu, artist;
        int id, rank;
        stringstream linestream(line);
        string curent;
        int nr = 0;
        while(getline(linestream, curent, ',')) {
            if(nr == 0)
                id = stoi(curent);
            if(nr == 1)
                titlu = curent;
            if(nr == 2)
                artist = curent;
            if(nr == 3)
                rank = stoi(curent);
            nr++;
        }
        m.push_back(Melodie(id, titlu, artist, rank));
    }
    fin.close();
}

void Repo::save_to_file(vector<Melodie> lista) {
    ofstream fout(filename);
    for(auto &m : lista) {
        fout<<m.get_id()<<","<<m.get_titlu()<<","<<m.get_artist()<<","<<m.get_rank()<<endl;
    }
    fout.close();
}

void Repo::modifica(int id, std::string titlu, int rank) {
    for(auto &melodie : m) {
        if(melodie.get_id() == id) {
            melodie.set_titlu(titlu);
            melodie.set_rank(rank);
        }
        save_to_file(getAll());
//        load_from_file();
    }
}

void Repo::sterge(int id) {
    int i = 0;
    for(auto &melodie : m) {
        if(melodie.get_id() == id) {
            m.erase(m.begin()+i);
        }
        i++;
    }
    save_to_file(getAll());
}