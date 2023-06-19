#pragma once

#include "string"
#include "vector"

using namespace std;

class Produs {
private:
    int id;
    string titlu, tip;
    double pret;
public:
    Produs(int id, string titlu, string tip, double pret) : id(id), titlu(titlu), tip(tip), pret(pret) {}

    int get_id() {
        return id;
    }

    string get_titlu() {
        return titlu;
    }

    string get_tip() {
        return tip;
    }

    double get_pret() {
        return pret;
    }

};