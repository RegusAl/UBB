#include "CosOferte.h"
#include <algorithm>
#include <random>

using std::shuffle;

void CosOferte::adaugaOfertaCos(const Oferta &o) {
    this->cosOferte.push_back(o);
}

void CosOferte::adaugaOfertaRandomCos(vector<Oferta> oferte, int numar) {
    shuffle(oferte.begin(), oferte.end(), std::default_random_engine(std::random_device{}())); //amesteca vectorul v
    while (cosOferte.size() < numar && !oferte.empty()) {
        cosOferte.push_back(oferte.back());
        oferte.pop_back();
    }
}

const vector<Oferta> &CosOferte::getAllCos() {
    return this->cosOferte;
}

void CosOferte::stergeCos() {
    this->cosOferte.clear();
}
