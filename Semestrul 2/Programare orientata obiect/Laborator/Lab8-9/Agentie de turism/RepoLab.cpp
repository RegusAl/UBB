#include <algorithm>
#include "OfertaRepo.h"
#include "Errors.h"

void RepoLab::random() const {
    double random = ((double) rand() / (RAND_MAX));
    if (random > probabilitate) {
        random *= 100;
        cout << "Probabilitatea: " << random;
        throw (Exception("Nu se poate executa aceasta functie!!!"));
    }
}

bool RepoLab::exist(const Oferta &o) {
    random();
    for (auto &of: oferte) {
        if (of.second.getDenumire() == o.getDenumire() && of.second.getDestinatie() == o.getDestinatie()) {
            return true;
        }
        return false;
    }
    return false;
}

void RepoLab::setProbabilitate(double p) {
    probabilitate = p;
}

void RepoLab::adauga(const Oferta &o) {
    random();
    if (exist(o)) {
        throw Exception("Oferta exista deja in lista.");
    }
    int i = int(oferte.size());
    oferte.insert(std::make_pair(i, o));
}

void RepoLab::stergere(const Oferta &o) {
    random();
    int i = 0;
    while (i < oferte.size() && oferte.at(i).getDenumire() != o.getDenumire() &&
           oferte.at(i).getDestinatie() != o.getDestinatie()) {
        i++;
    }
    if (i > oferte.size()) throw Exception("Oferta nu exista!");
    for (int j = i; j < oferte.size() - 1; j++) {
        oferte.at(j) = oferte.at(j + 1);
    }
    oferte.erase((int) oferte.size() - 1);
}

const Oferta &RepoLab::cauta(std::string denumire, std::string destinatie) {
    random();
    auto it = find_if(oferte.begin(), oferte.end(), [=](const std::pair<int, Oferta> o) {
        return o.second.getDenumire() == denumire && o.second.getDestinatie() == destinatie;
    });
    if (it == oferte.end())
        throw Exception("Oferta nu exista.");
    return (*it).second;
}

vector<Oferta> OFERTE;

vector<Oferta> &RepoLab::getAll() {
    random();
//    if (OFERTE.empty())
//        throw Exception("Nu exista oferte!");
    OFERTE.clear();
    for (auto &o: oferte) {
        OFERTE.push_back(o.second);
    }
    return OFERTE;
}