#include "medicament.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

Medicament* createMedicament(char* cod, char* nume, float concentratie, int stoc){
	Medicament* rez = malloc(sizeof(Medicament));
	int nrC = (int)strlen(cod)+1;
	rez->cod = malloc(nrC * sizeof(char));
	strcpy(rez->cod, cod);
	nrC = (int)strlen(nume)+1;
	rez->nume = malloc(nrC * sizeof(char));
	strcpy(rez->nume, nume);
	rez->concentratie = concentratie;
	rez->stoc = stoc;
	return rez;
}

void destroyMedicament(Medicament* m) {
	//m->cod[0] = '\0';
	//m->nume[0] = '\0';
	free(m->cod);
	free(m->nume);
	//m->concentratie = -1;
	//m->stoc = -1;
	free(m);
}

Medicament* copyMedicament(Medicament* m) {
	return createMedicament(m->cod, m->nume, m->concentratie, m->stoc);
}

int valideaza(Medicament* m) {
	if (strlen(m->cod) == 0) {
		return 1;
	}
	if (strlen(m->nume) == 0) {
		return 2;
	}
	if (m->concentratie < 0) {
		return 3;
	}
	if (m->stoc < 0) {
		return 4;
	}
	return 0;
}

void testCreateDestroy() {
	Medicament* m = createMedicament("5Y11320", "Oscilococcinum", 12, 3);
	assert(strcmp(m->cod, "5Y11320") == 0);
	assert(strcmp(m->nume, "Oscilococcinum") == 0);
	assert(m->concentratie == 12.0);
	assert(m->stoc == 3.0);

	destroyMedicament(m);
}