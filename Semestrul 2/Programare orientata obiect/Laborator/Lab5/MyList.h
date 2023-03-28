#pragma once
#include "medicament.h"
#include <stdlib.h>
#define _CRTDBG_MAP_ALLOC

typedef void* ElemType;
typedef void (*DestroyFct)(ElemType);
typedef ElemType(*CopyFct)(ElemType);

typedef struct {
	ElemType* elems;
	int lg;
	int capacitate;
	DestroyFct dfnc;
}MyList;

/* Creare lista goala. */
MyList* createEmpty(DestroyFct f);

/* Distrugere lista. */
void destroyList(MyList* l);

/* Extragere element din lista. */
ElemType get(MyList* l, int poz);

/* Setare element. */
ElemType set(MyList* l, int poz, ElemType el);

/* Numarul de elemente din lista. */
int size(MyList* l);

/* Adaugare element la lista. */
void add(MyList* l, ElemType el);

/* Stergere element. */
ElemType delete(MyList* l, int poz);

/* Copie lista. */
MyList* copyList(MyList* l, CopyFct copyFct);

void testCreateList();
void testIterateList();
void testCopyList();