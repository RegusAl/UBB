#pragma once

#include <string>

using namespace std;

class Device {
private:
    string Tip;
    string Model;
    int An{};
    string Culoare;
    int Pret{};
public:
    Device() = default;
    Device(const string &tip, const string &model, const int an, const string &culoare, const int pret) {
        Tip = tip;
        Model = model;
        An = an;
        Culoare = culoare;
        Pret = pret;
    }
    Device(const Device &d) : Tip{d.Tip}, Model{d.Model}, An{d.An}, Culoare{d.Culoare}, Pret{d.Pret} {}

    // gettere
    string getTip() {
        return Tip;
    }

    string getModel() const {
        return Model;
    }

    int getAn() {
        return An;
    }

    string getCuloare() {
        return Culoare;
    }

    int getPret() const {
        return Pret;
    }
};

bool cmpModel(const Device d1, const Device d2);

bool cmpPret(const Device de1, const Device de2);