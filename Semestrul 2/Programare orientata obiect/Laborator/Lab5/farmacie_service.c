 #include "farmacie_service.h"
#include "customSort.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Farmacie createFarmacie()
{
	Farmacie farmacie;
	farmacie.allMedicament = createEmpty(destroyMedicament);
	farmacie.undoList = createEmpty(destroyList);
	return farmacie;
}

void destroyFarmacie(Farmacie* farmacie) {
	destroyList(farmacie->allMedicament);
	destroyList(farmacie->undoList);
}

int addMedicament(Farmacie* farmacie, char* cod, char* nume, float concentratie, int stoc) {
	Medicament* m = createMedicament(cod, nume, concentratie, stoc);
	int succ = valideaza(m);
	if (succ != 0) {
		destroyMedicament(m);
		return succ;
	}
	int poz = findMedicament(farmacie, cod);
	MyList* toUndo = copyList(farmacie->allMedicament, copyMedicament);
	if (poz == -1) {
		add(farmacie->allMedicament, m);
	}
	else {
		Medicament* m2 = get(farmacie->allMedicament, poz);
		stoc = m2->stoc + m->stoc;
		modifyMedicament(farmacie, cod, nume, concentratie, stoc);
        destroyMedicament(m);
	}
	add(farmacie->undoList, toUndo);
	return 0;
}

int findMedicament(Farmacie* farmacie, char* cod) {
	int poz = -1;
	for (int i = 0; i < farmacie->allMedicament->lg; i++) {
		Medicament* m = get(farmacie->allMedicament, i);
		if (strcmp(m->cod, cod) == 0) {
			poz = i;
			break;
		}
	}
	return poz;
}

int modifyMedicament(Farmacie* farmacie, char* cod, char* nume, float concentratie, int stoc) {
	int poz = findMedicament(farmacie, cod);

	if (poz != -1) {
		MyList* toUndo = copyList(farmacie->allMedicament, copyMedicament);
		add(farmacie->undoList, toUndo);

		Medicament* m2 = createMedicament(cod, nume, concentratie, stoc);
		Medicament* m = get(farmacie->allMedicament, poz);
		destroyMedicament(m);
		set(farmacie->allMedicament, poz, m2);
		return 1;
	}
	else 
		return 0;
}

int deleteMedicament(Farmacie* farmacie, char* cod) {
	int poz = findMedicament(farmacie, cod);
	if (poz != -1) {
		MyList* toUndo = copyList(farmacie->allMedicament, copyMedicament);
		add(farmacie->undoList, toUndo);

		Medicament* m = delete(farmacie->allMedicament, poz);
		destroyMedicament(m);
		return 1;
	}
	else 
		return 0;
}

int undo(Farmacie* farmacie) {
	if (size(farmacie->undoList) == 0)
		//nothing to undo
		return 0;
	MyList* l = delete(farmacie->undoList, farmacie->undoList->lg - 1);
	destroyList(farmacie->allMedicament);
	farmacie->allMedicament = l;
	return 1;
}

MyList* getAllMedicamentChar(Farmacie* farmacie, char* typeSubstring) {
	if (typeSubstring == NULL || strlen(typeSubstring) == 0) {
		return copyList(farmacie->allMedicament, copyMedicament);
	}
	MyList* rez = createEmpty(destroyMedicament);
	for (int i = 0; i < farmacie->allMedicament->lg; i++) {
		Medicament* m = get(farmacie->allMedicament, i);
		if (strstr(m->nume, typeSubstring) != NULL) {
			add(rez, createMedicament(m->cod, m->nume, m->concentratie, m->stoc));
		}
	}
	return rez;
}

MyList* getAllMedicamentNr(Farmacie* farmacie, int n) {
	if (n <= 0) {
		return copyList(farmacie->allMedicament, copyMedicament);
	}
	MyList* rez = createEmpty(destroyMedicament);
	for (int i = 0; i < farmacie->allMedicament->lg; i++) {
		Medicament* m = get(farmacie->allMedicament, i);
		if (m->stoc<n) {
			add(rez, createMedicament(m->cod, m->nume, m->concentratie, m->stoc));
		}
	}
	return rez;
}

int cmpStoc(Medicament* m1, Medicament* m2) {
	if (m1->stoc == m2->stoc)
		return 0;
	if (m1->stoc > m2->stoc)
		return 1;
	else
		return -1;
}

int cmpStocD(Medicament* m1, Medicament* m2) {
	if (m1->stoc == m2->stoc)
		return 0;
	if (m1->stoc < m2->stoc)
		return 1;
	else
		return -1;
}

int cmpNume(Medicament* m1, Medicament* m2) {
	return strcmp(m1->nume, m2->nume);
}

int cmpNumeD(Medicament* m1, Medicament* m2) {
	if (strcmp(m1->nume, m2->nume) > 0)
		return -1;
	if (strcmp(m1->nume, m2->nume) < 0)
		return 1;
	else
		return 0;
}

MyList* sortStoc(Farmacie* farmacie) {
	MyList* l = copyList(farmacie->allMedicament, copyMedicament);
	sort(l, cmpStoc);
	return l;
}

MyList* sortStocD(Farmacie* farmacie) {
	MyList* l = copyList(farmacie->allMedicament, copyMedicament);
	sort(l, cmpStocD);
	return l;
}

MyList* sortNume(Farmacie* farmacie) {
	MyList* l = copyList(farmacie->allMedicament, copyMedicament);
	sort(l, cmpNume);
	return l;
}

MyList* sortNumeD(Farmacie* farmacie) {
	MyList* l = copyList(farmacie->allMedicament, copyMedicament);
	sort(l, cmpNumeD);
	return l;
}

void testAddMedicament() {
	Farmacie farmacie = createFarmacie();
	int error = addMedicament(&farmacie, "", "ff", 12, 9);
	assert(error != 0);

	error = addMedicament(&farmacie, "ufiewhnh", "", 3, 4);
	assert(error != 0);

	error = addMedicament(&farmacie, "ufnh", "thrfh", -3, 4);
	assert(error != 0);

	error = addMedicament(&farmacie, "ufh", "iukyjt", 3, -4);
	assert(error != 0);

	assert(size(farmacie.allMedicament) == 0);

	addMedicament(&farmacie, "a", "b", 12, 9);
	addMedicament(&farmacie, "aa", "bb", 9, 45);
	addMedicament(&farmacie, "aa", "bb", 9, 3);

	MyList* filtered = getAllMedicamentChar(&farmacie, "b");
	assert(size(filtered) == 2);
    destroyList(filtered);
	filtered = getAllMedicamentNr(&farmacie, 15);
	assert(size(filtered) == 1);

	destroyList(filtered);
	destroyFarmacie(&farmacie);
}
void testFindMedicament() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "a", "b", 1, 3);
	addMedicament(&farmacie, "c", "d", 3, 123);
	int x = findMedicament(&farmacie, "a");
	assert(x == 0);
	destroyFarmacie(&farmacie);
}
void testModify() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "a", "b", 1, 3);
	addMedicament(&farmacie, "c", "d", 3, 123);
	int m3 = modifyMedicament(&farmacie, "c", "dana", 4, 123);
	assert(size(farmacie.allMedicament) == 2);
	assert(m3 == 1);
	m3 = modifyMedicament(&farmacie, "d", "e", 1, 2);
	assert(m3 == 0);
	destroyFarmacie(&farmacie);
}
void testDelete() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "a", "b", 1, 3);
	addMedicament(&farmacie, "c", "d", 3, 123);
	assert(size(farmacie.allMedicament) == 2);
	int succ = deleteMedicament(&farmacie, "a");
	assert(succ == 1);
	succ = deleteMedicament(&farmacie, "e");
	assert(succ == 0);
	destroyFarmacie(&farmacie);
}
void testGetAllChar() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "tusin", 1, 3);
	addMedicament(&farmacie, "cfren", "strepsils", 3, 123);
	addMedicament(&farmacie, "dfkwn", "tusocalm", 7, 5);
	assert(size(farmacie.allMedicament) == 3);
	MyList* rez = getAllMedicamentChar(&farmacie, "tu");
	assert(size(rez) == 2);
	destroyList(rez);
	rez = getAllMedicamentChar(&farmacie, "ci");
	assert(size(rez) == 0);
	destroyList(rez);
	rez = getAllMedicamentChar(&farmacie, "");
	assert(size(rez) == 3);
	destroyList(rez);
	destroyFarmacie(&farmacie);
}
void testGetAllNr() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "tusin", 1, 3);
	addMedicament(&farmacie, "cfren", "strepsils", 3, 123);
	addMedicament(&farmacie, "dfkwn", "tusocalm", 7, 5);
	assert(size(farmacie.allMedicament) == 3);
	MyList* rez = getAllMedicamentNr(&farmacie, 7);
	assert(size(rez) == 2);
	destroyList(rez);
	rez = getAllMedicamentNr(&farmacie, 2);
	assert(size(rez) == 0);
	destroyList(rez);
	rez = getAllMedicamentNr(&farmacie, -1);
	assert(size(rez) == 3);
	destroyList(rez);
	destroyFarmacie(&farmacie);
}
void testSortStoc() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "tusin", 1, 3);
	addMedicament(&farmacie, "cfren", "strepsils", 3, 123);
	addMedicament(&farmacie, "dfkwn", "tusocalm", 7, 3);
	assert(size(farmacie.allMedicament) == 3);
	MyList* sorted = sortStoc(&farmacie);
	Medicament* a = get(sorted, 0);
	Medicament* b = get(sorted, 1);
	Medicament* c = get(sorted, 2);
	assert(a->stoc == 3);
	assert(b->stoc == 3);
	assert(c->stoc == 123);
	destroyList(sorted);
	destroyFarmacie(&farmacie);
}
void testSortStocD() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "tusin", 1, 3);
	addMedicament(&farmacie, "cfren", "strepsils", 3, 123);
	addMedicament(&farmacie, "dfkwn", "tusocalm", 7, 3);
	assert(size(farmacie.allMedicament) == 3);
	MyList* sorted = sortStocD(&farmacie);
	Medicament* a = get(sorted, 0);
	Medicament* b = get(sorted, 1);
	Medicament* c = get(sorted, 2);
	assert(a->stoc == 123);
	assert(b->stoc == 3);
	assert(c->stoc == 3);
	destroyList(sorted);
	destroyFarmacie(&farmacie);
}
void testSortNume() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "b", 1, 3);
	addMedicament(&farmacie, "cfren", "a", 3, 123);
	addMedicament(&farmacie, "dfkwn", "a", 7, 5);
	assert(size(farmacie.allMedicament) == 3);
	MyList* sorted = sortNume(&farmacie);
	Medicament* a = get(sorted, 0);
	Medicament* b = get(sorted, 1);
	Medicament* c = get(sorted, 2);
	assert(strcmp(a->nume,"a")==0);
	assert(strcmp(b->nume, "a") == 0);
	assert(strcmp(c->nume, "b") == 0);
	destroyList(sorted);
	destroyFarmacie(&farmacie);
}
void testSortNumeD() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "aewoh", "a", 1, 3);
	addMedicament(&farmacie, "cfren", "c", 3, 123);
	addMedicament(&farmacie, "dfkwn", "a", 7, 5);
	assert(size(farmacie.allMedicament) == 3);
	MyList* sorted = sortNumeD(&farmacie);
	Medicament* a = get(sorted, 0);
	Medicament* b = get(sorted, 1);
	Medicament* c = get(sorted, 2);
	assert(strcmp(a->nume, "c") == 0);
	assert(strcmp(b->nume, "a") == 0);
	assert(strcmp(c->nume, "a") == 0);
	destroyList(sorted);
	destroyFarmacie(&farmacie);
}
void testUndo() {
	Farmacie farmacie = createFarmacie();
	addMedicament(&farmacie, "rem", "a", 1, 2);
	modifyMedicament(&farmacie, "rem", "b", 4, 2);
	deleteMedicament(&farmacie, "rem");

	undo(&farmacie);
	MyList* rez = getAllMedicamentChar(&farmacie, "");
	assert(size(rez) == 1);
	Medicament* m = get(rez, 0);
	assert(m->concentratie == 4);
	destroyList(rez);

	undo(&farmacie);
	rez = getAllMedicamentChar(&farmacie, "");
	assert(size(rez) == 1);
	m = get(rez, 0);
	assert(m->concentratie == 1);
	destroyList(rez);

	undo(&farmacie);
	rez = getAllMedicamentChar(&farmacie, "");
	assert(size(rez) == 0);
	destroyList(rez);

	int moreUndo = undo(&farmacie);
	assert(moreUndo == 0);
	destroyFarmacie(&farmacie);
}