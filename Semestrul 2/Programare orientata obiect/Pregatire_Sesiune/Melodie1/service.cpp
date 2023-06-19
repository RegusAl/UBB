#pragma once
#include "service.h"
#include "exception"

vector<Melodie> Service::sortare(vector<Melodie> melodii) {
    vector<Melodie> rez;
    sort(melodii.begin(), melodii.end(), [](Melodie& m1, Melodie& m2) {
       return m1.get_rank() < m2.get_rank();
    });
    return melodii;
}

void Service::modificare_rank(int id, std::string titlu, int rank) {
    if(rank > 10 || rank < 0 || titlu == "")
        throw exception();
    repo.modifica(id, titlu, rank);
}

void Service::sterge(int id) {
    string artist;
    for(auto& m : getAll()) {
        if(id == m.get_id())
            artist = m.get_artist();
    }
    int i = 0;
    for(auto& m : getAll()) {
        if(artist == m.get_artist())
            i++;
    }
    if(i > 1)
        repo.sterge(id);
    else
        throw exception();
}

vector<int> Service::rank_fr() {
    int rank = 0;
    vector<int> fr;
    for(int i = 0; i < 10; i++) {
        int nr = 0;
        for(auto& m : getAll()) {
            if(m.get_rank() == rank)
                nr++;
        }
        fr.push_back(nr);
        rank++;
    }
    return fr;
}