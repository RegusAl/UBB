#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// afiseaza matricea linie cu linie
void afiseaza_matrice(int rows, int cols, int **array)
{
	for (int i = 0; i < rows; i++)
	{
		printf ("( ");
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf(")\n");
	}
}


// Sa se scrie un program C care:
// - citeste o matrice cu 3 randuri si 4 coloane dintr-un fisier de tip text;
// - afiseaza pe ecran matricea citita din fisier.
int main(int argc, char *argv[])
{
	// aloc dinamic memoria necesara matricei
	int nrows = 3;      // numarul de linii
    int ncols = 4;      // numarul de coloane
	int **matrix = (int **)malloc(nrows * sizeof(int *));
	if (matrix == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < nrows; i++)
	{
		matrix[i] = (int *)malloc(ncols * sizeof(int));
		if (matrix[i] == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	// deschid fisierul
	char filename[] = "matrix.txt";
	FILE *fd = fopen(filename, "r");
	if (fd == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	// citesc fisierul caracter cu caracter
	int i = 0;
	int j = 0;
	char c = '\0';
	while ((c = fgetc(fd)) != EOF)
	{
		if (!isspace(c))
		{
			matrix[i][j] = (c - 48);
			j++;
			if (j == ncols)
			{
				i++;
				j = 0;
			}
		}
		if (i == nrows)
			break;
	}

	// afisez matricea
	afiseaza_matrice(nrows, ncols, matrix);

	// eliberez memoria alocata dinamic
	for (int i = 0; i < nrows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	// inchid fisierul
	fclose(fd);

	return 0;
}
