#pragma once
#include <string>
#include <vector>
#include "oferta.h"
using namespace std;

class ValidationException {
	vector<string> errorMsg;
public:
	ValidationException(vector<string> errorMessages) :errorMsg{ errorMessages } {};

	string getErrorMessages() {
		string fullMsg = "";
		for (const string e : errorMsg) {
			fullMsg += e + "\n";
		}
		return fullMsg;
	}
};

class Validator {
public:
	void validateOferta(const Oferta& o);
};