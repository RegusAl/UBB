#pragma once

#include <QDebug>
#include <utility>
#include "service.h"

#include "algorithm"
#include "functional"
#include "exception"

//int Service::numarVocale(string nume) {
//    int nr = 0;
//    for(auto &litera : nume) {
//        if(litera == 'a')
//            nr++;
//        if(litera == 'e')
//            nr++;
//        if(litera == 'i')
//            nr++;
//        if(litera == 'o')
//            nr++;
//        if(litera == 'u')
//            nr++;
//    }
//    return nr;
//}

vector<Produs> Service::sortare(vector<Produs> produse) {
    sort(produse.begin(), produse.end(), [this](Produs& p1, Produs& p2) {
        return p1.get_pret() < p2.get_pret();
    });
    return produse;
}

string Service::adaugare(int id, const string& nume, const string& tip, double pret) {
    string exceptii;
    if(nume.empty())
        exceptii.append("Numele este invalid!  ");
    if(pret < 1.0 || pret > 100.0)
        exceptii.append("Pretul nu este valid!  ");
    for(auto &p : getAll()) {
        if(p.get_id() == id)
            exceptii.append("Id-ul trebuie sa fie unic!  ");
    }
    qDebug()<<QString::fromStdString(exceptii);
    if(!exceptii.empty())
        return exceptii;
    else {
        repository.adaugare(Produs(id, nume, tip, pret));
        notify();
    }
    return "";

}

int Service::nr_tipuri(string tip) {
    int nr = 0;
    for(auto &p : getAll()) {
        if(tip == p.get_tip())
            nr++;
    }
    return nr;
}

map<string, int> Service::get_tipuri() {
    map<string, int> rez;
    for(auto &p : getAll()) {
        rez[p.get_tip()]++;
    }
    return rez;
}
