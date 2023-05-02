#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;

class Oferta {
    string Denumire;
    string Destinatie;
    string Tip;
    int Pret;

public:
    Oferta() = default;

    Oferta(const string& denumire, const string& destinatie, const string& tip, int pret) {
        Denumire = denumire;
        Destinatie = destinatie;
        Tip = tip;
        Pret = pret;
    }

    Oferta(const Oferta& o):Denumire{o.Denumire}, Destinatie{o.Destinatie}, Tip{o.Tip}, Pret{o.Pret} {
//        cout<<"copie efectuata\n";
    }

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
//    void setTip(string tip) {
//        Tip = tip;
//    }
//
//    void setPret(float pret) {
//        Pret = pret;
//    }

};

bool cmpDenumire(const Oferta& o1, const Oferta& o2);

bool cmpDestinatie(const Oferta& o1, const Oferta& o2);

bool cmpTipPret(const Oferta& o1, const Oferta& o2);
