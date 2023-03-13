#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 11

// sorteaza lista de cuvinte in ordine alfabetica
void sort_words(int count, char words[][11])
{
	for(int i = 0; i < (count-1); i++)
	{
		for(int j = (i+1); j < count; j++)
		{
			if (strcmp(words[i], words[j]) > 0)
			{
				char tmp[11];
				strcpy(tmp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], tmp);
			}
		}
	}
}


// Sa se scrie un program C care:
// - citeste un numar N de la tastatura;
// - citeste N cuvinte care contin maximum 10 litere;
// - sorteaza cuvintele in ordine alfabetica si le afiseaza pe ecran.
int main(int argc, char* argv[])
{
	// citesc N
    int N = 0;
    printf("N: ");
    scanf("%d", &N);

	// aloc static lista de cuvinte
	char cuvinte[N][MAX];

	// citesc cuvintele
	printf("Dati cuvintele:\n");
    for (int i = 0; i < N; i++)
    {
		printf("  cuvinte[%d]: ", i);
		scanf("%s", cuvinte[i]);
	}

	// sortez cuvintele in ordine alfabetica
	sort_words(N, cuvinte);

	// afisez cuvintele sortate
	printf("Cuvinte:");
	for (int i = 0; i < N; i++)
    {
		printf(" %s", cuvinte[i]);
	}
	printf("\n");

	return 0;
}
