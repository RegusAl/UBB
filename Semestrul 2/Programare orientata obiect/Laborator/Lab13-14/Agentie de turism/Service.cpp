#include "Service.h"
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

void OfertaStore::addOferta(string denumire, string destinatie, string tip, int pret)
{
	Oferta o1{ denumire, destinatie, tip, pret };
	valid.validateOferta(o1);
	repo.store(o1);
	undoActions.push_back(std::make_unique<UndoAdauga>(repo, o1));
}

void OfertaStore::modifyOferta(const string& denumire, const string& destinatie, const string& tip, const int& pret) {
	Oferta old = repo.find(denumire);
	Oferta o{ denumire, destinatie,tip, pret };
	valid.validateOferta(o);
	repo.modify_of(o);
	undoActions.push_back(std::make_unique<UndoModify>(repo, old, o));
}

void OfertaStore::deleteOferta(const string& denumire) {
	Oferta o{ denumire, "a", "Altele",10 };
	valid.validateOferta(o);
	Oferta sters = repo.find(denumire);
	repo.delete_of(denumire);
	undoActions.push_back(std::make_unique<UndoSterge>(repo, sters));
}

vector<Oferta> OfertaStore::filtrareDest(string dest)
{
	const vector<Oferta>& allOferte = getAllOferte();
	vector<Oferta> filteredOferte;
	std::copy_if(allOferte.begin(), allOferte.end(), back_inserter(filteredOferte),
		[dest](const Oferta& o) {
			return o.getDestinatie() == dest;
		});
	return filteredOferte;
}

vector<Oferta> OfertaStore::filtrarePret(int pret)
{
	const vector<Oferta>& allOferte = getAllOferte();
	vector<Oferta> filteredOferte;
	std::copy_if(allOferte.begin(), allOferte.end(), back_inserter(filteredOferte),
		[pret](const Oferta& o) {
			return o.getPret() == pret;
		});
	return filteredOferte;
}

vector<Oferta> OfertaStore::sortByDenumire()
{
	vector<Oferta> sortedCopy{ repo.getAllOferte() };
	sort(sortedCopy.begin(), sortedCopy.end(), cmpDenumire);
	return sortedCopy;
}

vector<Oferta> OfertaStore::sortByDestinatie()
{
	vector<Oferta> sortedCopy{ repo.getAllOferte() };
	sort(sortedCopy.begin(), sortedCopy.end(), cmpDestinatie);
	return sortedCopy;
}

vector<Oferta> OfertaStore::sortByTipSiPret()
{
	vector<Oferta> sortedCopy{ repo.getAllOferte() };
	sort(sortedCopy.begin(), sortedCopy.end(), cmpTipPret);
	return sortedCopy;
}

void OfertaStore::addToCos(string denumire)
{
	const auto& oferta = repo.find(denumire);
	cosCurent.addOfertaToCos(oferta);
}

int OfertaStore::addRandomToCos(int howMany)
{
	cosCurent.addRandomOferte(this->getAllOferte(), howMany);
	return cosCurent.getAllOferteCos().size();
}

void OfertaStore::emptyCos()
{
	cosCurent.emptyCos();
}

const vector<Oferta>& OfertaStore::getAllOferteCos()
{
	return cosCurent.getAllOferteCos();
}

int OfertaStore::count_oferte(string destinatie)
{
	vector<Oferta> Copy{ repo.getAllOferte() };
	int nr = std::count_if(Copy.begin(), Copy.end(), [destinatie](const Oferta& o) {
		return o.getDestinatie() == destinatie;
		});
	return nr;
}

void OfertaStore::export_fisier(std::string filename)
{
	cosCurent.exportaCos(filename);
}

