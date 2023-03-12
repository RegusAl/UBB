#include "repository.h"

int adaugaMateriePrima(List *v, char *nume, char *producator, int cantitate);

int stergeMateriePrima(List *v, char *nume, char *producator);

int modificaMateriePrima(List *v, char *nume, char *producator, char *nume_nou, char *producator_nou, int cantitate);

List filtruMateriePrima(List *v, char l, int cantitate_max);

List sortMateriaPrima(List *v);