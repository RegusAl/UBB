#pragma once
#include "oferta.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "observer.h"
#include "Repo.h"

using std::vector;

class CosOferte: public Observable {
private:
	vector<Oferta> cosOferte;
	const OfertaRepo& rep;
public:
	CosOferte(const OfertaRepo& rep) :rep{rep}{};

	/*
	* Adauga o oferta in cos
	* @param o: oferta care se adauga (Oferta)
	* post: oferta va fi adaugata in cos
	*/
	void addOfertaToCos(const Oferta& o);

	/*
	* Elimina toate ofertele din cos
	* post: cosul este gol
	*/
	void emptyCos();

	void sterge_of(string denumire);

	/*
	* Adauga un numar random de oferte in cos
	* @param originalOferte: ofertele din care se alege (vector<Oferta>)
	* @param howMany: cate oferte se adauga (int)
	* post: ofertele sunt adaugate in cosul curent
	*/
	void addRandomOferte(vector<Oferta> originalOferte, int howMany);

	// Returneaza un vector care contine toate ofertele din cos
	const vector<Oferta>& getAllOferteCos();

	void umple(int cate) {
		int seed = std::chrono::system_clock::now().time_since_epoch().count();
		vector<Oferta> all = rep.getAll();
		std::shuffle(all.begin(), all.end(), std::default_random_engine(seed)); //amesteca vectorul v
		while (cosOferte.size() < cate && all.size() > 0) {
			cosOferte.push_back(all.back());
			all.pop_back();
		}
		//notificam can dse schimba ceva in cos
		notify();
	}

	void exportaCos(string numeFisier);
};