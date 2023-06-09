#include "Validator.h"

bool validString(string str) {
	if (str.size() == 0) return false;
	for (int i = 0; i < str.size(); i++) {
		if (!((str.at(i) >= 'a' && str.at(i) <= 'z') || (str.at(i) >= 'A' && str.at(i) <= 'Z'))) return false;
	}
	return true;
}

void Validator::validateOferta(const Oferta& o) {
	vector<string> errors;

	if (validString(o.getDenumire()) == false) errors.push_back("Denumirea este invalida!\n");
	if (validString(o.getDestinatie()) == false) errors.push_back("Destinatia este invalida!\n");
	if (validString(o.getTip()) == false) errors.push_back("Tipul este invalid!\n");
	if (o.getTip() != "CityBreak" && o.getTip() != "AllInclusive" && o.getTip() != "Croaziere" && o.getTip() != "MultiCountry" && o.getTip() != "Altele") errors.push_back("Tipul introdus nu exista!\n");
	if (o.getPret() <= 0) errors.push_back("Pretul este invalid!\n");
	if (errors.size() > 0) throw ValidationException(errors);
}