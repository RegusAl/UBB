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

void Consola::afisareUI(const vector<Oferta>& oferte) {
    cout<<"OFERTE"<<endl;
    for(const auto& oferta : oferte) {
        cout<<oferta.getDenumire()<<" are loc in "<<oferta.getDestinatie()<<" si este "<<oferta.getTip()<<" si costa "<<oferta.getPret()<<" lei."<<endl;
    }
}

void Consola::modificaUI() {
    cout<<"Modificare: "<<endl;
    string denumire, destinatie, tip_nou;
    float pret_nou;
    cout<<"Denumirea ofertei pe care vreti sa o schimbati: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o schimbati: ";
    cin>>destinatie;
    cout<<"Tipul nou: ";
    cin>>tip_nou;
    cout<<"Pretul nou: ";
    cin>>pret_nou;
    service.modificaOferta(denumire, destinatie, tip_nou, pret_nou);
}

void Consola::stergereUI() {
    cout<<"Stergere Oferta"<<endl;
    string denumire, destinatie;
    cout<<"Denumirea ofertei pe care vreti sa o stergeti: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o stergeti: ";
    cin>>destinatie;
    service.stergereOferta(denumire, destinatie);
}

void Consola::run() {
    while(true) {
        cout<<"Meniu"<<endl;
        cout<<"1. Adaugare oferta\n2. Afisare oferte\n3. Modifica tipul si pretul unei oferte\n4. Stergere oferta\n0. Iesire\n";
        int optiune;
        cin>>optiune;
        try{
            switch (optiune) {
                case 1:
                    adaugaUI();
                    break;
                case 2:
                    afisareUI(service.getAll());
                    break;
                case 3:
                    modificaUI();
                    break;
                case 4:
                    stergereUI();
                    break;
                case 0:
                    cout << "Iesire din aplicatie...";
                    return;
                default:
                    cout << "Comanda invalida!!!\n";
            }
        }
        catch (const OfertaRepoException& ex) {
            cout<<ex<<endl;
        }
    }
}