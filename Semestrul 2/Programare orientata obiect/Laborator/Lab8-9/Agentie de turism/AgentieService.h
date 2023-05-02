#pragma once

#include "Oferta.h"
#include "OfertaRepo.h"
#include "Validator.h"

#include <string>
//#include <vector>
#include <functional>
#include <vector>
#include <memory>

using std::vector;
using std::string;
using std::function;

//typedef bool(*Compare)(const Oferta&, const string&);
typedef int(*Sort)(const Oferta&, const Oferta&);

class AgentieService {
    OfertaRepo& Repo;
    Validator& Valid;
    vector<Oferta> filtrare(const function<bool(const Oferta&)>& fct);
public:
    explicit AgentieService(OfertaRepo& repo, Validator& valid):Repo{repo}, Valid{valid} {}
    AgentieService() = delete;
    AgentieService(const AgentieService& ot) = delete;

    vector<Oferta>& getAll() noexcept {
        return Repo.getAll();
    }

    void adaugaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);
    void modificaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);
    void stergereOferta(const string& denumire, const string& destinatie);
    vector<Oferta> filtrareDestinatie(const string& destinatie);
    vector<Oferta> filtrarePret(int pret);

    /*
	* Sorteaza ofertele dupa denumire
	* @return: lista cu ofertele sortate dupa denumire
	*/
    vector<Oferta> sortByDenumire();

    /*
    * Sorteaza ofertele dupa destinatie
    * @return: lista cu ofertele sortate dupa destinatie
    */
    vector<Oferta> sortByDestinatie();

    /*
    * Sorteaza ofertele dupa tip si pret
    * @return: lista cu ofertele sortate dupa tip si pret
    */
    vector<Oferta> sortByTipSiPret();

//    vector<Oferta> sortareOferte(Sort functieSortare);
};


