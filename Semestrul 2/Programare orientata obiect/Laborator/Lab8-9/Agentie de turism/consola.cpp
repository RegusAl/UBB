#include "consola.h"
#include "Oferta.h"
#include "Errors.h"

#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

// MENIU PRINCIPAL

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

void Consola::afisareUI(vector<Oferta> oferte) {
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

void Consola::sortare() {
    cout<<"SORTARE"<<endl;
    cout<<"1. Denumire | 2. Destinatie | 3. Tip si Pret"<<endl;
    string optiune;
    cout<<"Optiunea: ";
    cin>>optiune;
    if (optiune == "1") {
        auto lista_sortata = service.sortByDenumire();
        afisareUI(lista_sortata);
    } else if(optiune == "2") {
        auto lista_sortata = service.sortByDestinatie();
        afisareUI(lista_sortata);
    } else if(optiune == "3") {
        auto lista_sortata = service.sortByTipSiPret();
        afisareUI(lista_sortata);
    }
}

void Consola::cosAdaugaUI() {
    string denumire, destinatie;
    cout<<"Denumirea ofertei pe care vreti sa o adaugati in Wishlist: ";
    cin>>denumire;
    cout<<"Destinatia ofertei pe care vreti sa o adaugati in Wishlist: ";
    cin>>destinatie;
    try {
        service.cosAdauga(denumire, destinatie);
        cout<<"Oferta s-a adaugat in Wishlist\n";
    } catch (Exception ex) {
        cout<<ex.getMessage()<<endl;
    }
}

void Consola::cosAdaugaRandomUI() {
    int numar;
    char str[101];
    cout<<"Cate oferte random vreti in WISHLIST: ";
    cin>>str;
    numar = stoi(str);
    if( !(numar < 0 || strlen(str)>10)) {
        try {
            int numar_oferte = service.cosAdaugaRandom(numar);
            cout<<"S-au adaugat "<<numar_oferte<<" oferte random in WISHLIST"<<endl;
        } catch (Exception ex) {
            cout<<ex.getMessage()<<endl;
        }
    } else cout<<"Numarul este invalid!"<<endl;
}

void Consola::cosStergeUI() {
    service.cosSterge();
    cout<<"S-au sters toate ofertele din WISHLIST!"<<endl;
}


// MENIU COS - WISHLIST
void Consola::MeniuCos() {
    while(true) {
        cout << "---\t---\tMENIU WISHLIST\t---\t---" << endl;
        cout
                << "1. Adaugare oferta in wishlist\n2. Adaugare oferte random in wishlist\n3. Goleste wishlist\n4. Afisare wishlist\n5. Export\n6. Iesire\n---\t---\t---\n";
        int optiune;
        cout<<"Optiunea: ";
        cin>>optiune;
        try {
            switch (optiune) {
                case 1:
                    cosAdaugaUI();
                    break;
                case 2:
                    cosAdaugaRandomUI();
                    break;
                case 3:
                    cosStergeUI();
                    break;
                case 4:
                    afisareUI(service.getAllCos());
                    break;
//                case 4:
//                    cosExportUI();
//                    break;
                case 6:
                    cout<<"Iesire din WISHLIST";
                    return;
                default:
                    cout<<"Comanda invalida!";
            }
        } catch (const OfertaRepoException& ex) {
            cout<<ex<<endl;
        }
    }
}


void Consola::run() {
    while(true) {
        cout<<"---\tMENIU\t---\n---\t---\t---"<<endl;
        cout<<"1. Adaugare oferta\n2. Afisare oferte\n3. Modifica tipul si pretul unei oferte\n4. Stergere oferta\n5. Filtrare dupa destinatie\n6. Filtrare dupa pretul maxim\n7. Sortare \n8. MENIU WISHLIST\n0. Iesire\n---\t---\t---\n";
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
                case 7:
                    sortare();
                    break;
                case 8:
                    MeniuCos();
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