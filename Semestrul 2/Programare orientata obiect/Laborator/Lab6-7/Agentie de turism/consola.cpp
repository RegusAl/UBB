#include "consola.h"
#include "Oferta.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

void Consola::adaugaUI() {
    string denumire, destinatie, tip;
    float pret;
    cout<<"Denumirea: ";
    cin>>denumire;
    cout<<"Destinatia: ";
    cin>>destinatie;
    cout<<"Tipul: ";
    cin>>tip;
    cout<<"Pretul: ";
    cin>>pret;
    service.adaugaOferta(denumire, destinatie, tip, pret);
    cout<<"Oferta a fost adaugata cu succes!"<<endl;
}

void Consola::run() {
    while(true) {
        cout<<"Meniu"<<endl;
        int optiune;
        cin>>optiune;
        switch (optiune) {
            case 1:
                adaugaUI();
                break;
            case 2:
                return;
        }
    }
}