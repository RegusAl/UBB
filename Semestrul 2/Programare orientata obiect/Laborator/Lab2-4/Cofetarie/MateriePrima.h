typedef struct {
    char nume[30];
    char producator[30];
    int cantitate;
} MateriePrima;

MateriePrima creeazaMateriePrima(char *nume, char *producator, int cantitate);

int valideazaMateriePrima(MateriePrima m);

void destroyMateriePrima(MateriePrima *m);

