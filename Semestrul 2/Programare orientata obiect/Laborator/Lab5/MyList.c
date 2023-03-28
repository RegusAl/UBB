#include "MyList.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

MyList* createEmpty(DestroyFct f) {
	MyList* rez = malloc(sizeof(MyList));
	rez->capacitate = 1;
	rez->lg = 0;
	rez->elems = malloc(sizeof(ElemType) * rez->capacitate);
	rez->dfnc = f;
	return rez;
}

void destroyList(MyList* l) {
	for (int i = 0; i < size(l); i++) {
		l->dfnc(l->elems[i]);
	}
	l->lg = 0;
	free(l->elems);
	free(l);
}

ElemType get(MyList* l, int poz) {
	return l->elems[poz];
}

ElemType set(MyList* l, int poz, ElemType el) {
	ElemType replacedElement = l->elems[poz];
	l->elems[poz] = el;
	return replacedElement;
}

int size(MyList* l) {
	return l->lg;
}

void add(MyList* l, ElemType el) {
	if (l->lg >= l->capacitate) {
		int newCap = l->capacitate * 2;
		ElemType* aux_elems = malloc(sizeof(ElemType) * newCap);
		for (int i = 0; i < l->lg; i++) {
			aux_elems[i] = l->elems[i];
		}
		free(l->elems);
		l->elems = aux_elems;
		l->capacitate = newCap;
	}
	l->elems[l->lg] = el;
	l->lg++;
}

ElemType delete(MyList* l, int poz) {
	ElemType el = l->elems[poz];
	for (int i = poz; i < l->lg - 1; i++) {
		l->elems[i] = l->elems[i + 1];
	}
	l->lg--;
	return el;
}

MyList* copyList(MyList* l, CopyFct copyFct) {
	MyList* rez = createEmpty(l->dfnc);
	for (int i = 0; i < size(l); i++) {
		ElemType m = get(l, i);
		add(rez, copyFct(m));
	}
	return rez;
}

void testCreateList() {
	MyList* l = createEmpty((DestroyFct) destroyMedicament);
	assert(size(l) == 0);
	destroyList(l);
}
void testIterateList() {
	MyList* l = createEmpty((DestroyFct) destroyMedicament);
	add(l, createMedicament("df34", "rfe", 13, 65));
	add(l, createMedicament("sdhfij4n", "rfvfd", 3, 5));
	assert(size(l) == 2);
	Medicament* m = get(l, 0);

	assert(strcmp(m->cod, "df34") == 0);
	m = get(l, 1);
	assert(strcmp(m->nume, "rfvfd") == 0);
	destroyList(l);
}
void testCopyList() {
	MyList* l = createEmpty((DestroyFct) destroyMedicament);
	add(l, createMedicament("a", "b", 1, 2));
	add(l, createMedicament("c", "d", 3, 4));
	MyList* l2 = copyList(l, (CopyFct) copyMedicament);
	assert(size(l2) == 2);
	Medicament* m = get(l2, 0);
	assert(strcmp(m->cod, "a") == 0);
	destroyList(l);
	destroyList(l2);
}