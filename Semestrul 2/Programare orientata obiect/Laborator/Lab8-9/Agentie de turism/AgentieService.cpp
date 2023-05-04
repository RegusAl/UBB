#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "AgentieService.h"

void AgentieService::adaugaOferta(const std::string &denumire, const std::string &destinatie, const std::string& tip, int pret) {
    Validator::validateOferta(denumire, destinatie, tip, pret);
    Oferta o{denumire, destinatie, tip, pret};
    Repo.adauga(o);
}

void AgentieService::modificaOferta(const string& denumire, const string& destinatie, const string& tip, int pret)  {
    Validator::validateOferta(denumire, destinatie, tip, pret);
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
    Oferta new_o{denumire, destinatie, tip, pret};
    Repo.adauga(new_o);
}

void AgentieService::stergereOferta(const string& denumire, const string& destinatie) {
    Validator::validateOferta(denumire, destinatie, "exemplu", 1);
    Oferta o = Repo.cauta(denumire, destinatie);
    Repo.stergere(o);
}

vector<Oferta> AgentieService::filtrareDestinatie(const string& destinatie) {
     const vector<Oferta>& oferte = getAll();
     vector<Oferta> oferteFiltrate;
     std::copy_if(oferte.begin(), oferte.end(), back_inserter(oferteFiltrate), [destinatie](const Oferta& o) {
         return o.getDestinatie() == destinatie;
     });
     return (oferteFiltrate);
}

vector<Oferta> AgentieService::filtrarePret(int pret) {
    const vector<Oferta>& oferte = getAll();
    vector<Oferta> oferteFiltrate;
    std::copy_if(oferte.begin(), oferte.end(), back_inserter(oferteFiltrate), [pret](const Oferta& o) {
        return o.getPret() <= pret;
    });
    return (oferteFiltrate);
}

vector<Oferta> AgentieService::sortByDenumire()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDenumire);
    return (sortedCopy);
}

vector<Oferta> AgentieService::sortByDestinatie()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpDestinatie);
    return (sortedCopy);
}

vector<Oferta> AgentieService::sortByTipSiPret()
{
    vector<Oferta> sortedCopy{ Repo.getAll() };
    sort(sortedCopy.begin(), sortedCopy.end(), cmpTipPret);
    return (sortedCopy);
}

unordered_map<string, int> AgentieService::frecventeDestinatie() {
    unordered_map<string, int> map;
    vector<Oferta> v = this->getAll();
    for(const auto & i : v) {
        if(map.find(i.getDestinatie()) != map.end())
            map[i.getDestinatie()]++;
        else
            map[i.getDestinatie()] = 1;
    }
    return map;
}

void AgentieService::cosAdauga(const string& denumire, const string& destinatie) {
    const auto & oferta = Repo.cauta(denumire, destinatie);
    cosCurent.adaugaOfertaCos(oferta);
}

int AgentieService::cosAdaugaRandom(int howMany)
{
    cosCurent.adaugaOfertaRandomCos(this->getAll(), howMany);
    return cosCurent.getAllCos().size();
}

const vector<Oferta>& AgentieService::getAllCos()
{
    return cosCurent.getAllCos();
}

void AgentieService::cosSterge() {
    cosCurent.stergeCos();
}

void AgentieService::cosExport(const string& filename) {
    if(filename.find(".csv") == std::string::npos && filename.find(".html") == std::string::npos) {
//        cout<<"Fisierul nu este valid! Fisierul poate fi doar .CSV sau .HTML"<<endl;
//        throw OfertaRepoException("Fisierul nu este valid!");
        throw Exception("Fisierul nu este valid!");
    } else {
        ofstream fout(filename);
        if(filename.find(".html") != std::string::npos) {
            fout << "<html>";
            fout << "<style> table, th, td {border:1px solid black} body{background-color: #E6E6FA;} </style>";
            fout << "<body>";
            fout << "<h1> WISHLIST </h1>";
            fout << "<table><tr><th>Denumire</th> <th>Destinatie</th> <th>Tip</th> <th>tip </th><th>Pret</th></tr>";
            for (auto& o : getAllCos())
            {
                fout << "<tr><td>" << o.getDenumire() << "<td>" << o.getDestinatie() << "</td><td>" << o.getTip()
                     << "</td><td>" << o.getPret() << "</td></tr>";
            }
            fout << "</table></body>";
            fout << "<html>";
        }
        else {
            for (auto& o : getAllCos())
            {
                fout << o.getDenumire() << ";" << o.getDestinatie() << ";" << o.getTip()
                     << ";" << o.getPret() << endl;
            }
        }
        fout.close();
    }
}


