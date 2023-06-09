#include "oferta.h"
#include <assert.h>

string Oferta::getDenumire() const
{
	return this->denumire;
}

string Oferta::getDestinatie() const
{
	return this->destinatie;
}

string Oferta::getTip() const
{
	return this->tip;
}

int Oferta::getPret() const noexcept
{
	return this->pret;
}

void Oferta::setDenumire(string denumire_noua)
{
	this->denumire = denumire_noua;
}

void Oferta::setDestinatie(string destinatie_noua)
{
	this->destinatie = destinatie_noua;
}

void Oferta::setTip(string tip_nou)
{
	this->tip = tip_nou;
}

void Oferta::setPret(int pret_nou)
{
	this->pret = pret_nou;
}

bool cmpDenumire(const Oferta& o1, const Oferta& o2)
{
	return o1.getDenumire() < o2.getDenumire();
}

bool cmpDestinatie(const Oferta& o1, const Oferta& o2)
{
	return o1.getDestinatie() < o2.getDestinatie();
}

bool cmpTipPret(const Oferta& o1, const Oferta& o2)
{
	if (o1.getTip() == o2.getTip())
		return o1.getPret() < o2.getPret();
	else
		return o1.getTip() < o2.getTip();
}
