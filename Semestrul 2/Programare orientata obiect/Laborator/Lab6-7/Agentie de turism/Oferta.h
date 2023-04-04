#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;

class Oferta {
    string Denumire;
    string Destinatie;
    string Tip;
    float Pret;

public:
    Oferta(const string denumire, const string destinatie, const string tip, float pret) {
        Denumire = denumire;
        Destinatie = destinatie;
        Tip = tip;
        Pret = pret;
    }

    Oferta(const Oferta& o):Denumire{o.Denumire}, Destinatie{o.Destinatie}, Tip{o.Tip}, Pret{o.Pret} {}

    // getters
    string getDenumire() const {
        return Denumire;
    }

    string getDestinatie() const {
        return Destinatie;
    }

    string getTip() const {
        return Tip;
    }

    float getPret() const {
        return Pret;
    }

    // setters
    void setTip(string tip) {
        Tip = tip;
    }

    void setPret(float pret) {
        Pret = pret;
    }
};

