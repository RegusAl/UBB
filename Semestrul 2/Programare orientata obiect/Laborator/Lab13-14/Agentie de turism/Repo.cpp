#include "Repo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <functional>

using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::endl;
using std::getline;
using std::stod;
using namespace std;

void OfertaRepo::store(const Oferta& o)
{
	if (exists(o)) {
		throw RepoException("Oferta exista deja in lista.");
	}
	this->allOferte.push_back(o);
}

void OfertaRepo::delete_of(string denumire)
{
	int i = 0;
	while (i < this->allOferte.size() && this->allOferte.at(i).getDenumire() != denumire) {
		i++;
	}
	if (i < this->allOferte.size()) this->allOferte.erase(this->allOferte.begin() + i);
	else throw RepoException("Oferta nu exista!\n");
}

void OfertaRepo::modify_of(const Oferta& o)
{
	int i = 0;
	while (i < this->allOferte.size() && !(this->allOferte.at(i).getDenumire() == o.getDenumire()))
		i++;
	if (i < this->allOferte.size()) {
		this->allOferte.at(i).setDestinatie(o.getDestinatie());
		this->allOferte.at(i).setTip(o.getTip());
		this->allOferte.at(i).setPret(o.getPret());
	}
	else throw RepoException("Oferta nu exista!\n");
}

const vector<Oferta>& OfertaRepo::getAllOferte()
{
	return this->allOferte;
}

const Oferta& OfertaRepo::find(string denumire)
{
	vector<Oferta>::iterator f = std::find_if(this->allOferte.begin(), this->allOferte.end(),
		[=](const Oferta& s) {
			return s.getDenumire() == denumire;
		});

	if (f != this->allOferte.end())
		return (*f);
	else
		throw RepoException("Oferta nu exista in lista.\n");
}

bool OfertaRepo::exists(const Oferta& o)
{
	try {
		find(o.getDenumire());
		return true;
	}
	catch (RepoException) {
		return false;
	}
}

void OfertaRepoFile::loadFromFile()
{
	ifstream ofertaFile(this->filename);
	if (!ofertaFile.is_open()) {
		throw RepoException("Cannot read from file " + filename);
	}
	string line;
	while (getline(ofertaFile, line))
	{
		string denumire, destinatie, tip;
		int pret;

		stringstream linestream(line);
		string current_item;
		int item_no = 0;
		while (getline(linestream, current_item, ','))
		{
			if (item_no == 0) denumire = current_item;
			if (item_no == 1) destinatie = current_item;
			if (item_no == 2) tip = current_item;
			if (item_no == 3) pret = stoi(current_item);
			item_no++;
		}
		Oferta o{ denumire, destinatie, tip, pret };
		OfertaRepo::store(o);
	}
	ofertaFile.close();
}

void OfertaRepoFile::saveToFile()
{
	ofstream ofertaOutput(this->filename);
	if (!ofertaOutput.is_open())
		throw RepoException("Cannot write to file " + filename);
	for (auto& oferta : getAllOferte()) {
		ofertaOutput << oferta.getDenumire() << "," << oferta.getDestinatie() << "," << oferta.getTip() << "," << oferta.getPret() << endl;
	}
	ofertaOutput.close();
}

void OfertaRepoFile::store(const Oferta& o)
{
	OfertaRepo::store(o);
	saveToFile();
}

void OfertaRepoFile::modify_of(const Oferta& o)
{
	OfertaRepo::modify_of(o);
	saveToFile();
}

void OfertaRepoFile::delete_of(string denumire)
{
	OfertaRepo::delete_of(denumire);
	saveToFile();
}
