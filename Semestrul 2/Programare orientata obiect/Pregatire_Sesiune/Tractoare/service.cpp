//
// Created by albert on 13/06/23.
//
#pragma once
#include <cstring>
#include "service.h"

vector<Tractor> Service::sortare(vector<Tractor> tractoare) {
    sort(tractoare.begin(), tractoare.end(), [this](Tractor &t1, Tractor &t2) {
        return t1.get_denumire() < t2.get_denumire();
//          return strcmp(t1.get_denumire(), t2.get_denumire());
    });
    return tractoare;
}

int Service::nrTip(Tractor t) {
    int nr = 0;
    for(auto &tr : getAll()) {
        if(tr.get_tip() == t.get_tip()) {
            nr++;
        }
    }
    return nr;
}

string Service::adaugare(int id, string denumire, string tip, int numarRoti) {
    string exceptii;
    if(denumire.empty() || tip.empty())
        exceptii.append("Denumirea sau Tipul nu poate di vid!!!  ");
    if(numarRoti%2==1 || numarRoti < 2 || numarRoti > 16)
        exceptii.append("Numarul de roti este invalid!!!  ");
    for(auto &t : getAll()) {
        if(t.get_id() == id)
            exceptii.append("Id-ul trebuie sa fie unic!!!  ");
    }
    if(exceptii.empty()) {
        repository.adaugare(Tractor(id, denumire, tip, numarRoti));
        return "";
    } else {
        return exceptii;
    }
}

vector<string> Service::getTipuri(vector<Tractor> tractoare) {
    vector<string> tipuri;
    for(auto &t : tractoare) {
        int ok = 1;
        for(auto &tip : tipuri) {
            if(t.get_tip() == tip) {
                ok = 0;
            }
        }
        if(ok == 1) {
            tipuri.push_back(t.get_tip());
        }
        ok = 1;
    }
    return tipuri;
}
