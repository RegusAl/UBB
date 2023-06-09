#include "Cos_Oferte.h"
using std::shuffle;
#include <fstream>
#include "observer.h"
//#include <QApplication>

void CosOferte::addOfertaToCos(const Oferta& o)
{
	vector<Oferta> of = this->getAllOferteCos();
	for (auto elem : of)
		if (o.getDenumire() == elem.getDenumire())
			throw RepoException("Oferta exista deja!\n");
	this->cosOferte.push_back(o);
	notify();
}

void CosOferte::emptyCos()
{
	this->cosOferte.clear();
	notify();
}

void CosOferte::sterge_of(string denumire)
{
	int i = 0;
	while (i < this->cosOferte.size() && this->cosOferte.at(i).getDenumire() != denumire) {
		i++;
	}
	if (i < this->cosOferte.size()) this->cosOferte.erase(this->cosOferte.begin() + i);
	else throw RepoException("Oferta nu exista!\n");
	notify();
}

bool gasit(vector<Oferta> originalOferte, vector<Oferta> cosof) {
	for (auto of : cosof)
		if (of.getDenumire() == originalOferte.back().getDenumire())
			return false;
	return true;
}

void CosOferte::addRandomOferte(vector<Oferta> originalOferte, int howMany)
{
	shuffle(originalOferte.begin(), originalOferte.end(), std::default_random_engine(std::random_device{}())); //amesteca vectorul v
	while (cosOferte.size() < howMany && originalOferte.size() > 0) {
		if (gasit(originalOferte, cosOferte) == true) {
			cosOferte.push_back(originalOferte.back());
		}
		originalOferte.pop_back();
	}
	notify();
}

const vector<Oferta>& CosOferte::getAllOferteCos()
{
	return this->cosOferte;
}

void CosOferte::exportaCos(string numeFisier)
{
	std::ofstream fout(numeFisier);
	for (auto& oferta : cosOferte)
		fout << oferta.getDenumire() << ":" << oferta.getDestinatie() << ":" << oferta.getTip() << ":" << oferta.getPret() << std::endl;
	fout.close();
}
