#pragma once

#include "Oferta.h"
#include "OfertaRepo.h"
#include "Validator.h"
#include "CosOferte.h"
#include "Errors.h"

#include <string>
//#include <vector>
#include <functional>
#include <vector>
#include <memory>
#include <unordered_map>

using std::vector;
using std::string;
using std::function;

//typedef bool(*Compare)(const Oferta&, const string&);
//typedef int(*Sort)(const Oferta&, const Oferta&);

class AgentieService {
    OfertaRepo& Repo;
    Validator& Valid;

    CosOferte& cosCurent;
//    vector<Oferta> filtrare(const function<bool(const Oferta&)>& fct);
public:
    explicit AgentieService(OfertaRepo& repo, Validator& valid, CosOferte& cos):Repo{repo}, Valid{valid}, cosCurent{cos} {}
    //constructor de copiere; punem delete fiindca nu vrem sa se faca nicio copie la Service
    AgentieService() = delete;
    AgentieService(const AgentieService& ot) = delete;

    /*
     * Returneaza toate ofertele
     */
    vector<Oferta>& getAll() noexcept {
        return Repo.getAll();
    }

    /*
     * Adauga o oferta
     * @param denumire: denumirea ofertei
     * @param destinatie: destinatia ofertei
     * @param tip: tipul ofertei
     * @param pret: pretul ofertei
     * @throws:
     *	Exception daca mai exista oferta cu denumirea data
	 *	Exception daca oferta nu este valida
     */
    void adaugaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);

    /*
	 * Modifica o oferta
	 * @param denumire: denumirea ofertei care se modifica (string)
	 * @param destinatie: destinatia noua (string)
	 * @param tip: tipul nou (string)
	 * @param pret: pretul nou (string)
	 * @throws:
	 *	Exception daca nu exista oferta cu denumirea data
	 *	Exception daca oferta nu este valida
	 */
    void modificaOferta(const string& denumire, const string& destinatie, const string& tip, int pret);

    /*
	 * Sterge o oferta cu denumirea si destinatia data
	 * @param denumire: denumirea dupa care se sterge oferta
     * @param destinatie: destinatia dupa care se sterge
	 * @throws:
	 *	Exception daca denumirea sau destinatia nu este valida
	 */
    void stergereOferta(const string& denumire, const string& destinatie);

    /*
     * Filtreaza ofertele in functie de destinatie
     * @return: lista cu oferte filtrate dupa destinatie
     */
    vector<Oferta> filtrareDestinatie(const string& destinatie);

    /*
     * Filtreaza ofertele in functie de pret
     * @return: lista cu oferte filtrate dupa pret
     */
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

    /*
     * Calculeaza frecventa ofertelor in functie de destinatie si construieste un dictionar
     * @return dictionar
     */
    unordered_map<string, int> frecventeDestinatie();

    /*
     * Adauga oferta cu denumirea si destinatia cautata in cos
     * @param denumire: denumirea ofertei
     * @param destinatie: destinatia ofertei
     */
    void cosAdauga(const string& denumire, const string& destinatie);

    /*
     * Adauga un numar de oferte random in cos
     * @param nr: numarul de oferte random ce se adauga
     * @return: numarul de oferte random ce au fost adaugate
     */
    int cosAdaugaRandom(int nr);

    /*
     * Returneaza toate ofertele din cos
     */
    const vector<Oferta>& getAllCos();

    /*
     * Goleste toate ofertele din cos
     */
    void cosSterge();

    /*
     * Exporta cosul in fisierul dat ca parametru
     */
    void cosExport(string filename);
};


