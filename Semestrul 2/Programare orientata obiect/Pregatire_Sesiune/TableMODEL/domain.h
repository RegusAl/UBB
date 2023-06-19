#pragma once
#include "string"
#include "vector"

using namespace std;

class Entitate {
    int id;
    string nume, tip;
public:
    Entitate(int id, string nume, string tip) : id(id), nume(nume), tip(tip) {}

    Entitate(const Entitate& e) : id(e.id), nume(e.nume), tip(e.tip) {}

    int getId() {
        return id;
    }

    string getNume() {
        return  nume;
    }

    string getTip() {
        return tip;
    }
};