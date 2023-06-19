#pragma once

#include "string"

using namespace std;

class Tractor {
    int id, numarRoti;
    string denumire, tip;
public:
    Tractor(int id, string denumire, string tip, int numarRoti) : id(id), denumire(denumire), tip(tip), numarRoti(numarRoti) {}

    int get_id() {
        return id;
    }

    int get_numarRoti() {
        return numarRoti;
    }

    string get_denumire() {
        return denumire;
    }

    string get_tip() {
        return tip;
    }
};