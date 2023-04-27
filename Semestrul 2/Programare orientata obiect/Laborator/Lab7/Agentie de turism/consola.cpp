#include "consola.h"
#include "Oferta.h"
#include "VectorDinamic.h"
#include "Errors.h"

#include <iostream>
#include <cstring>
#include <string>

using std::cout;
using std::cin;
using std::endl;

void Consola::adaugaUI() {
    cout<<"ADAUGARE OFERTA"<<endl;
    string denumire, destinatie, tip;
    char pr[100];
    int pret;
    cout<<"Denumirea: ";
    cin>>denumire;
    cout<<"Destinatia: ";
    cin>>destinatie;
    cout<<"Tipul: ";
    cin>>tip;
    cout<<"Pretul: ";
    cin>>pr;
    pret = atoi(pr);
    try {
        service.adaugaOferta(denumire, destinatie, tip, pret);
        cout<<"Oferta a fost adaugata cu succes!"<<endl;

    }
    catch(Exception exception) {
        cout<<exception.getMessage();
    }
}

void Consola::afisareUI(VectorDinamic<Oferta> oferte) {
    cout<<"OFERTE"<<endl;
    for(const auto& oferta : oferte) {
        cout<<"DENUMIRE: "<<oferta.getDenumire()<<" | DESTINATIE: "<<oferta.getDestinatie()<<" | TIP: "<<oferta.getTip()<<" | PRET: "<<oferta.getPret()<<" RON |"<<endl;
    }
}

void Consola::modificaUI() {
    cout<<"MODIFICARE OFERTA: "<<endl;
    string denumire, destinatie, tip_nou;
    char pr[100];
    int pret_nou;
    cout<<"Denumirea ofertei pe care vreti sa o schimbati: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o schimbati: ";
    cin>>destinatie;
    cout<<"Tipul nou: ";
    cin>>tip_nou;
    cout<<"Pretul nou: ";
    cin>>pr;
    pret_nou = atoi(pr);
    try {
        service.modificaOferta(denumire, destinatie, tip_nou, pret_nou);

    }
    catch(Exception exception) {
        cout<<exception.getMessage();
    }
}

void Consola::stergereUI() {
    cout<<"STERGERE OFERTA"<<endl;
    string denumire, destinatie;
    cout<<"Denumirea ofertei pe care vreti sa o stergeti: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o stergeti: ";
    cin>>destinatie;
    try {
        service.stergereOferta(denumire, destinatie);
        cout<<"Oferta s-a sters cu succes!"<<endl;
    }
    catch(Exception exception) {
        cout<<exception.getMessage();
    }
}

void Consola::filtrareDestinatieUI() {
    cout<<"FILTRARE DUPA DESTINATIE"<<endl;
    string destinatia;
    cout<<"Dati destinatia pentru care vreti sa vedeti ofertele: ";
    cin>>destinatia;
    afisareUI(service.filtrareDestinatie(destinatia));
}

void Consola::filtrarePretUI() {
    cout<<"FILTRARE DUPA PRETUL MAXIM"<<endl;
    float pret;
    cout<<"Dati pretul maxim pentru care vreti sa vedeti ofertele: ";
    cin>>pret;
    afisareUI(service.filtrarePret(pret));
}

void Consola::run() {
    while(true) {
        cout<<"---\tMENIU\t---\n---\t---\t---"<<endl;
        cout<<"1. Adaugare oferta\n2. Afisare oferte\n3. Modifica tipul si pretul unei oferte\n4. Stergere oferta\n5. Filtrare dupa destinatie\n6. Filtrare dupa pretul maxim\n0. Iesire\n---\t---\t---\n";
        int optiune;
        cout<<"Optiunea: ";
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
                case 5:
                    filtrareDestinatieUI();
                    break;
                case 6:
                    filtrarePretUI();
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