#include "Oferta.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using std::vector;

class CosOferte {
private:
    vector<Oferta> cosOferte;
public:
    CosOferte() = default;

    void adaugaOfertaCos(const Oferta& o);

    void adaugaOfertaRandomCos(vector<Oferta> oferte, int numar);

    const vector<Oferta>& getAllCos();

    void stergeCos();
};