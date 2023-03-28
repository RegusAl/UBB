#include "farmacie_service.h"
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void testAll() {
	testCreateDestroy();
	testCreateList();
	testIterateList();
	testCopyList();
	testAddMedicament();
	testFindMedicament();
	testModify();
	testDelete();
	testGetAllChar();
	testGetAllNr();
    testGetAllStocuri();
	testSortStoc();
	testSortStocD();
	testSortNume();
	testSortNumeD();
	testUndo();
}

void readMedicament(Farmacie* farmacie) {
	printf("Cod: ");
	char cod[30];
	scanf("%s", cod);
	printf("Nume: ");
	char nume[30];
	scanf("%s", nume);
	printf("Concentratie: ");
	float concentratie;
	scanf("%f", &concentratie);
	printf("Cantitate: ");
	int stoc;
	scanf("%d", &stoc);
	int error = addMedicament(farmacie, cod, nume, concentratie, stoc);
	if (error != 0) {
		printf(ANSI_COLOR_RED "\nMedicament invalid.\n" ANSI_COLOR_RESET);
	}
	else {
		printf(ANSI_COLOR_GREEN "\nMedicament adaugat.\n" ANSI_COLOR_RESET);
	}
}

void printAllMedicament(MyList* l) {
	printf("\nMedicamente: \n");
	for (int i = 0; i < size(l); i++) {
		Medicament* m = get(l, i);
		printf("Cod:%s Nume:%s Concentratie:%f Cantitate in stoc : % d\n", m->cod, m->nume, m->concentratie, m->stoc);
	}
}

void deleteStoc(Farmacie* farmacie) {
	printf("Cod: ");
	char cod[30];
	scanf("%s", cod);
	int succ = deleteMedicament(farmacie, cod);
	if (succ)
		printf(ANSI_COLOR_GREEN "\nAcest medicament nu mai exista in farmacie.\n" ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "\nNu exista medicament cu aceste date.\n" ANSI_COLOR_RESET);
}

void filterMedicamentChar(Farmacie* farmacie) {
	printf("Introduceti un caracter: ");
	char filterStr[30]; 
	scanf("%s", filterStr, 30);

	MyList* filteredL = getAllMedicamentChar(farmacie, filterStr);
	printAllMedicament(filteredL);
}

void filterMedicamentNr(Farmacie* farmacie) {
	printf("Introduceti un numar: ");
	int filterNr;
	scanf("%d", &filterNr);

	MyList* filteredL = getAllMedicamentNr(farmacie, filterNr);
	printAllMedicament(filteredL);
}

// filtrare dupa stocuri
void filterMedicamentStoc(Farmacie *farmacie) {
    int stocMin, stocMax;
    printf("Introduceti stocul minim: ");
    scanf("%d", &stocMin);
    printf("Introduceti stocul maxim: ");
    scanf("%d", &stocMax);
    MyList* filteredL = getAllMedicamentStoc(farmacie, stocMin, stocMax);
    printAllMedicament(filteredL);

}

void Modify(Farmacie* farmacie) {
	printf("Cod: ");
	char cod[30];
	scanf("%s", cod, 30);
	printf("Nume nou: ");
	char nume[30];
	scanf("%s", nume, 30);
	printf("Concentratie noua: ");
	float concentratie;
	scanf("%f", &concentratie);
	printf("Cantitate: ");
	int stoc;
	scanf("%d", &stoc);
	int successful = modifyMedicament(farmacie, cod, nume, concentratie, stoc);
	if (successful){
		printf(ANSI_COLOR_GREEN "\nMedicament modificat cu succes.\n" ANSI_COLOR_RESET);
	}
	else{
		printf(ANSI_COLOR_RED "\nNu exista medicament cu datele date.\n" ANSI_COLOR_RESET);
	}
}

void undoMain(Farmacie* farmacie) {
	int succ = undo(farmacie);
	if (succ)
		printf(ANSI_COLOR_GREEN "Undo a fost realizat.\n" ANSI_COLOR_RESET);
	else
		printf(ANSI_COLOR_RED "Nu se mai poate face undo.\n" ANSI_COLOR_RESET);
}

void sortByStoc(Farmacie* farmacie) {
	MyList* l = sortStoc(farmacie);
	printAllMedicament(l);
	destroyList(l);
}

void sortByStocD(Farmacie* farmacie) {
	MyList* l = sortStocD(farmacie);
	printAllMedicament(l);
	destroyList(l);
}

void sortByNume(Farmacie* farmacie) {
	MyList* l = sortNume(farmacie);
	printAllMedicament(l);
	destroyList(l);
}

void sortByNumeD(Farmacie* farmacie) {
	MyList* l = sortNumeD(farmacie);
	printAllMedicament(l);
	destroyList(l);
}

void run() {
	Farmacie farmacie = createFarmacie();
	int ruleaza = 1;
	while (ruleaza) {
		printf(ANSI_COLOR_CYAN "\n1 Adauga medicament\n2 Afiseaza lista cu medicamente\n3 Sterge un medicament dat\n4 Modifica un medicament\n5 Filtreaza dupa o litera\n6 Filtreaza dupa nr stoc\n7 Sorteaza dupa nume\n8 Sorteaza dupa nume desc\n9 Sorteaza dupa cantitate\n10 Sorteaza dupa cantitate desc\n11 Undo\n12 Filtrare dupa stocuri\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_RED "0 Exit\n" ANSI_COLOR_RESET);
		printf(ANSI_COLOR_MAGENTA "\nNr. comenzii:" ANSI_COLOR_RESET);
		int cmd = 0;
		scanf("%d", &cmd);
		switch (cmd) {
		    case 1:
			    readMedicament(&farmacie);
			    break;
		    case 2:
			    printAllMedicament(farmacie.allMedicament);
			    break;
		    case 3:
			    deleteStoc(&farmacie);
			    break;
		    case 4:
			    Modify(&farmacie);
			    break;
		    case 5:
			    filterMedicamentChar(&farmacie);
			    break;
		    case 6:
			    filterMedicamentNr(&farmacie);
			    break;
		    case 7:
			    sortByNume(&farmacie);
			    break;
		    case 8:
			    sortByNumeD(&farmacie);
                break;
            case 9:
			    sortByStoc(&farmacie);
			    break;
		    case 10:
			    sortByStocD(&farmacie);
			    break;
		    case 11:
			    undoMain(&farmacie);
			    break;
            case 12:
                filterMedicamentStoc(&farmacie);
                break;
		    case 0:
			    ruleaza = 0;
			    destroyFarmacie(&farmacie);
			    break;
		    default:
			    printf(ANSI_COLOR_RED "Comanda invalida!!!\n" ANSI_COLOR_RESET);
		}
	}
}

int main() {
	testAll();
	run();
}
