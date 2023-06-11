#pragma once
#include "service.h"
#include "functional"

vector<Melodie> Service::sortare(vector<Melodie> nesortate) {
    vector <Melodie> sortate;
    sort(nesortate.begin(), nesortate.end(), [](Melodie &m1, Melodie &m2) {
        return m1.get_artist() < m2.get_artist();
    });
    return (nesortate);
}

void Service::adaugare(string titlu, string artist, string gen) {
    if(titlu == "" || artist == "" || gen == "") {
        throw exception();
    }
    int ok = 1, i = 0;
    while(ok) {
        ok = 0;
        i++;
        for(auto &m : getAll()) {
            if(m.get_id() == i)
                ok = 1;
        }

    }
    repository.adaugare(Melodie(i, titlu, artist, gen));
}

void Service::stergere(int id) {
    repository.stergere(id);
}

int Service::acelasiArtist(Melodie m) {
    int nr = 0;
    for(auto &melo : getAll()) {
        if(m.get_artist() == melo.get_artist())
            nr++;
    }
    return nr;
}

int Service::acelasiGen(Melodie m) {
    int nr = 0;
    for(auto &melo : getAll()) {
        if(m.get_gen() == melo.get_gen())
            nr++;
    }
    return nr;
}
