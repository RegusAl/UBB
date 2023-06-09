#include "Validator.h"

#include "Errors.h"

bool validString(const string &str) {
    if (str.empty()) return false;
    for (char i: str) {
        if (!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || i == ' ' || i == '-')) return false;
    }
    return true;
}

void Validator::validateOferta(const string &denumire, const string &destinatie, const string &tip, int pret) {
    string errors;

    if (!validString(denumire)) errors.append("Denumirea este invalida!\n");
    if (!validString(destinatie)) errors.append("Destinatia este invalida!\n");
    if (!validString(tip)) errors.append("Tipul este invalid!\n");
    if (pret <= 0) errors.append("Pretul este invalid!\n");
    if (!errors.empty()) throw Exception(errors);
}
