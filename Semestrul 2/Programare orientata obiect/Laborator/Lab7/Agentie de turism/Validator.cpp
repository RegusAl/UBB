#include "Validator.h"
#include "Errors.h"

bool validString(string str) {
	if (str.size() == 0) return false;
	for (int i = 0; i < str.size(); i++) {
		if (!((str.at(i) >= 'a' && str.at(i) <= 'z') || (str.at(i) >= 'A' && str.at(i) <= 'Z') || str.at(i) == ' ')) return false;
	}
	return true;
}

void Validator::validateOferta(string denumire, string destinatie, string tip, int pret) {
	string errors;

	if (!validString(denumire)) errors.append("Denumirea este invalida!\n");
	if (!validString(destinatie)) errors.append("Destinatia este invalida!\n");
	if (!validString(tip)) errors.append("Tipul este invalid!\n");
	if (pret <= 0) errors.append("Pretul este invalid!\n");
	if (errors.size() != 0) throw Exception(errors);
}