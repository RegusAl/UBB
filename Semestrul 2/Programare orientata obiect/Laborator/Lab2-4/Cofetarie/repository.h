#include "MateriePrima.h"

typedef MateriePrima ElemType;
typedef struct {
    ElemType elements[100];
    int length;
} List;

List createEmpty();

void add(List *v, ElemType el);

void addCantitate(List *v, ElemType el, int poz);

ElemType delete(List *v, int poz);

ElemType get(List *v, int poz);

int size(List *v);

