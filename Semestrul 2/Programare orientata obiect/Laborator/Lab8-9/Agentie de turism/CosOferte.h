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
    /*
     * Constructorul cosului.
     */
    CosOferte() = default;

    /*
     * Adauga o oferta in cos.
     * @param o: oferta ce trebuie adaugata in cos.
     */
    void adaugaOfertaCos(const Oferta& o);

    /*
     * Adauga un numar de oferte in cos.
     * @param oferte: ofertele random ce trebuie adaugate in cos.
     * @param numar: numarul de oferte ce trebuie adaugate.
     */
    void adaugaOfertaRandomCos(vector<Oferta> oferte, int numar);

    /*
     * Returneaza un vector cu toate ofertele din cos.
     */
    const vector<Oferta>& getAllCos();

    /*
     * Sterge toate ofertele din cos.
     */
    void stergeCos();
};