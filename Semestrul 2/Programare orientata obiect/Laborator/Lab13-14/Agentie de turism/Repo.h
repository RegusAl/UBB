#pragma once
#include "oferta.h"
#include <vector>
#include <string>

using std::vector;

class RepoException {
private:
	string errorMsg;
public:
	RepoException(string errorMsg) :errorMsg{ errorMsg } {};
	string getErrorMessage() {
		return this->errorMsg;
	}
};

class OfertaRepo {
private:
	vector<Oferta> allOferte;
public:
	OfertaRepo() = default;

	//punem delete fiindca nu vrem sa se faca nicio copie la Repository
	OfertaRepo(const OfertaRepo& ot) = delete;

	/*
	Adauga o oferta in lista
	@param o: oferta care se adauga (Oferta)
	@return -
	post: Oferta va fi adaugata in lista
	@throws: Exception daca exista o oferta cu aceeasi denumirea
	*/
	virtual void store(const Oferta& o) ;

	/*
	Sterge o oferta in lista
	@param denumire: denumirea ofertei care se va sterge
	@return -
	post: Oferta va fi stearsa din lista
	@throws: Exception daca o oferta nu exista
	*/
	virtual void delete_of(string denumire) ;

	/*
	Modifica o oferta din lista
	@param o: oferta care se modifica (Oferta)
	@return -
	post: Oferta va fi modificata
	@throws: Exception daca nu exista oferta 
	*/
	virtual void modify_of(const Oferta& o) ;

	/*
	Returneaza o lista cu toate ofertele
	@return: lista cu ofertele (vector of Oferta objects)
	*/
	const vector<Oferta>& getAllOferte() ;

	vector<Oferta> getAll() const {
		return allOferte;
	}

	/*
	Cauta o oferta cu o denumire data
	@param denumire: denumirea dupa care se cauta
	@returns: entitatea Oferta cu denumirea data (daca aceasta exista)
	@throws: Exception daca nu exista Oferta cu denumirea data*/
	const Oferta& find(string denumire);

	/*
	Verifica daca o oferta data exista in lista
	@param o: oferta care se cauta in lista
	@return: true daca oferta exista, false altfel
	*/
	bool exists(const Oferta& o);

};

class OfertaRepoFile : public OfertaRepo {
private:
	string filename;
	/*
	Incarca datele din fisier
	*/
	void loadFromFile();

	/*
	Salveaza datele in fisier
	Format: denumire, destinatie, tip, pret
	*/
	void saveToFile();
public:
	OfertaRepoFile(string fname) : OfertaRepo(), filename{ fname } {
		loadFromFile();
	};

	void store(const Oferta& o) override;
	void modify_of(const Oferta& o) override;
	void delete_of(string denumire) override;
};