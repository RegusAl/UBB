typedef struct {
    char* nume;
    char* producator;
    int cantitate;
} MateriePrima;

/*
 * Creeaza o entitate de tipul Materie Prima
 * param nume: numele entitatii (char)
 * param producator: producatorul entitatii (char)
 * param cantitate: cantitatea (int)
 * return: Materie Prima
 */
MateriePrima creeazaMateriePrima(char *nume, char *producator, int cantitate);

/*
 * Valideaza o entitate de tipul Materie Prima
 * param: m (struct)
 * return: 1 - daca entitatea este valida
 *         0 - daca entitatea nu este valida
 */
int valideazaMateriePrima(MateriePrima m);

/*
 * Sterge elementele entitatii de tipul Materie Prima
 * param: m (struct)
 */
void destroyMateriePrima(MateriePrima *m);

