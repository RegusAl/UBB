#include <algorithm>
#include "OfertaRepo.h"
#include "Errors.h"

void RepoLab::pass() const {
    double random = ((double) rand() / (RAND_MAX));
    if (random > probabilitate) {
        throw (Exception("Nu se poate executa aceasta functie!!!"));
    }
}

bool RepoLab::exist(const Oferta &o) {
    pass();
    for(int i = 0; i<oferte.size(); i++) {
        if(oferte[i].getDenumire() == o.getDenumire() && oferte[i].getDestinatie() == o.getDestinatie()) {
            return true;
        }
        return false;
    }
}

void RepoLab::setProbabilitate(double p) {
    probabilitate = p;
}

void RepoLab::adauga(const Oferta &o) {
    pass();
    if (exist(o)) {
        throw Exception("Oferta exista deja in lista.");
    }
    int i = int(oferte.size());
    oferte.insert(std::make_pair(i, o));
}

void RepoLab::stergere(const Oferta &o) {
    pass();
    int i = 0;
    while (i < oferte.size() && oferte.at(i).getDenumire() != o.getDenumire() &&
           oferte.at(i).getDestinatie() != o.getDestinatie()) {
        i++;
    }
    if (i > oferte.size()) throw Exception("Oferta nu exista!");
    for (int j = i; j < oferte.size() - 1; j++) {
        oferte[j] = oferte[j + 1];
    }
    oferte.erase((int) oferte.size() - 1);
}

const Oferta &RepoLab::cauta(std::string denumire, std::string destinatie) {
    pass();
    auto it = find_if(oferte.begin(), oferte.end(), [=](const std::pair<int, Oferta> o) {
        return o.second.getDenumire() == denumire && o.second.getDestinatie() == destinatie;
    });
    if (it == oferte.end())
        throw Exception("Oferta nu exista.");
    return (*it).second;
}

vector<Oferta> OF;

vector<Oferta> &RepoLab::getAll() {
    pass();
    OF.clear();
    for (auto &o: oferte) {
        OF.push_back(o.second);
    }
    return OF;
}