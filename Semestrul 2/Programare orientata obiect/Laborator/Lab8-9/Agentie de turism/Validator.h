#pragma once

#include <string>

using namespace std;

class Validator {
public:
    static void validateOferta(const string &denumire, const string &destinatie, const string &tip, int pret);
};
