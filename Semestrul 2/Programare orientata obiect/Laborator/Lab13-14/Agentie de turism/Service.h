#pragma once
#include "Cos_Oferte.h"
#include "Repo.h"
#include "Validator.h"
#include "Undo.h"
#include <functional>
#include <memory>
#include <unordered_map>

using std::function;

class OfertaStore {
private:
	OfertaRepo& repo;
	Validator& valid;

	CosOferte cosCurent;
	vector<std::unique_ptr<ActiuneUndo>> undoActions;
public:
	OfertaStore(OfertaRepo& repo, Validator& val) :repo{ repo }, valid{ val }, cosCurent{ repo }{};

	//constructor de copiere; punem delete fiindca nu vrem sa se faca nicio copie la Service
	//(in aplicatie avem 1 singur Service)
	OfertaStore(const OfertaStore& ot) = delete;

	/*
	Adauga o oferta cu denumirea denumire, destinatia destinatie, tipul tip si pretul pret
	*@param denumire: denumirea ofertei care se adauga (string)
	*@param destinatie: destinatia ofertei care se adauga (string)
	*@param tip: tipul ofertei care se adauga (string)
	*@param pret: pretul ofertei care se adauga (string)
	* @throws:
	*	Exception daca mai exista oferta cu denumirea data
	*	Exception daca oferta nu este valida
	*/
	void addOferta(string denumire, string destinatie, string tip, int pret);

	Oferta findof(const string& denumire) {
		Oferta o{ denumire, "Altele", "Altele", 10 };
		valid.validateOferta(o);
		return repo.find(denumire);
	}

	/*
	* Modifica o oferta cu denumirea denumire
	*@param denumire: denumirea ofertei care se modifica (string)
	*@param destinatie: destinatia noua (string)
	*@param tip: tipul nou (string)
	*@param pret: pretul nou (string)
	* @throws:
	*	Exception daca nu exista oferta cu denumirea data
	*	Exception daca oferta nu este valida
	*/
	void modifyOferta(const string& denumire, const string& destinatie, const string& tip, const int& pret);

	/*
	* Sterge o oferta cu denumirea data
	* @param denumire: denumirea dupa care se sterge oferta
	* @throws:
	*	Exception daca denumirea nu este valida
	*/
	void deleteOferta(const string& denumire);

	/*
	Returneaza un vector cu toate ofertele disponibile
	@return: lista cu toate ofertele disponibile (vector cu obiecte de tip Oferta)
	*/
	const vector<Oferta>& getAllOferte() {
		return this->repo.getAllOferte();
	}


	/*
	* Returneaza o lista de oferte cu destinatia data
	* @param dest: destinatia dupa care se filtreaza
	* @return: lista cu ofertele care au destinatia data (vector cu elemente de tip Oferta)
	*/
	vector<Oferta> filtrareDest(string dest);

	/*
	* Returneaza o lista de oferte cu pretul dat
	* @param pret: pretul ofertelor cautate (int)
	* @return: lista cu ofertele care au pretul dat (vector cu elemente de tip Oferta)
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
	* Adauga o oferta cu denumirea denumire in cos
	* @param denumire: denumirea ofertei care se adauga (string)
	* post: oferta este adaugata in cos
	* @throws: Exception daca nu exista oferta cu denumirea data
	*/
	void addToCos(string denumire);

	/*
	* Adauga un numar random de oferte in cos
	* @param howMany: cate oferte se adauga (int)
	* @return: numarul de oferte adaugate in cos
	* post: se adauga un numar random de oferte in cos
	*/
	int addRandomToCos(int howMany);

	/*
	* Elimina toate ofertele din cos
	* post: cosul nu contine nicio oferta
	*/
	void emptyCos();

	/*
	* Returneaza un vector cu toate ofertele din cos
	*/
	const vector<Oferta>& getAllOferteCos();

	/*
		Returneaza nr de oferte care au o destinatie data
	*/
	int count_oferte(string destinatie);

	void export_fisier(std::string filename);

	void sterge_of(string denumire) {
		cosCurent.sterge_of(denumire);
	}

	void undo()
	{
		if (undoActions.empty())
			throw RepoException{ "Nu mai exista operatii" };
		undoActions.back()->doUndo();
		undoActions.pop_back();
	}

	CosOferte& getCos() {
		return cosCurent;
	}
};
