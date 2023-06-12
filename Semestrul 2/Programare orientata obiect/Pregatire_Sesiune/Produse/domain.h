#pragma once

#include "string"

using namespace std;

class Produs {
private:
    int id;
    double pret;
    string nume, tip;
public:
    Produs(int id, string nume, string tip, double pret) : id(id), nume(nume), tip(tip), pret(pret) {}

    int get_id() {
        return id;
    }

    string get_nume() {
        return nume;
    }

    string get_tip() {
        return tip;
    }

    double get_pret() {
        return pret;
    }

    int get_vocale() {
        int nr = 0;
        for(auto &litera : nume) {
            if(litera == 'a')
                nr++;
            if(litera == 'e')
                nr++;
            if(litera == 'i')
                nr++;
            if(litera == 'o')
                nr++;
            if(litera == 'u')
                nr++;
        }
    return nr;
    }
};