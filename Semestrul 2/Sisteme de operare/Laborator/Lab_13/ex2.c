/*

27. Scrieti un program C care primeste doua numere, N si M, ca argumente la linia de comanda. Programul creeaza N thread-uri "generator" care genereaza litere mici ale alfabetului aleator si le adauga unui sir de caractere cu 128 de pozitii. Programul mai creeaza un thread "printer" care asteapta ca toate pozitiile sirului de caractere sa fie ocupate, moment in care afiseaza sirul si apoi seteaza toate pozitiile sirului la NULL. Cele N thread-uri "generator" vor genera M astfel de string-uri, iar thread-ul "printer" va afisa fiecare string imediat ce ajunge la lungimea 128.

*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define SIZE 128

typedef struct
{
    char *buf;
	int *curr_pos;
	int *string_counter;
	pthread_mutex_t *m;
    pthread_cond_t *cg;
	pthread_cond_t *cp;
} data;


void* generate(void* arg)
{
	data td = *((data*)arg);
	
	while(1)
	{
		char ch = 'a' + rand() % ('z' - 'a' + 1);
	
		pthread_mutex_lock(td.m);
		if (*td.curr_pos == SIZE)
		{
			pthread_cond_signal(td.cp);
			while (*td.curr_pos == SIZE)
			{
				pthread_cond_wait(td.cg, td.m);
			}
		}
		
		if (*td.string_counter == 0)
		{
			break;
		}
		
		td.buf[*td.curr_pos] = ch;
		(*td.curr_pos)++;
		pthread_mutex_unlock(td.m);
	}
	pthread_mutex_unlock(td.m);
	
	return NULL;
}


void* print(void* arg)
{
	data td = *((data*)arg);
	
	while(1)
	{
		pthread_mutex_lock(td.m);
		if (*td.curr_pos != SIZE)
		{
			pthread_cond_signal(td.cg);
			while (*td.curr_pos != SIZE)
			{
				pthread_cond_wait(td.cp, td.m);
			}
		}
		
		// afisez sirul de caractere
		printf("%s\n", td.buf);
	
		// reinitializez sirul de caractere
		memset(td.buf, 0, SIZE * sizeof(char));
	
		*td.curr_pos = 0;
		(*td.string_counter)--;
		pthread_cond_broadcast(td.cg);
		
		if (*td.string_counter == 0)
		{
			break;
		}
		pthread_mutex_unlock(td.m);
	}
	pthread_mutex_unlock(td.m);
	
	return NULL;
}


int main(int argc, char* argv[])
{
	// verific numarul de argumente
	if (argc < 3)
	{
		printf("Trebuie sa furnizati 2 argumente.\n");
		printf("Utilizare: %s N M\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	struct timeval start;
	gettimeofday(&start, NULL);
	
	// obtin N, M
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	
	// initializez generatorul de numere aleatoare
	srand(time(NULL));
	
	// aloc dinamic variabilele necesare
	char *s = malloc((SIZE + 1) * sizeof(char));		// aloc sirul de caractere
	memset(s, 0, (SIZE + 1) * sizeof(char) * );			// initializez
	
	int *pos = malloc(sizeof(int));						// pozitia curenta in sirul de caractere
	*pos = 0;
	
	pthread_mutex_t *mtx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mtx, NULL);
	
	pthread_cond_t *c1 = malloc(sizeof(pthread_cond_t));
	pthread_cond_init(c1, NULL);
	pthread_cond_t *c2 = malloc(sizeof(pthread_cond_t));
	pthread_cond_init(c2, NULL);
	
	// creez cele N thread-uri "generator"
	int i;
	pthread_t tid[N + 1];
	data *args = malloc((N + 1) * sizeof(data));
	for (i = 0; i < N; i++)
	{
		args[i].curr_pos = pos;
        args[i].string_counter = &M;
		args[i].buf = s;
        args[i].m = mtx;
        args[i].cg = c1;
		args[i].cp = c2;
		pthread_create(&tid[i], NULL, generate, &args[i]);
	}
	
	// creez thread-ul "printer"
	args[i].curr_pos = pos;
	args[i].string_counter = &M;
	args[i].buf = s;
	args[i].m = mtx;
	args[i].cg = c1;
	args[i].cp = c2;
	pthread_create(&tid[N], NULL, print, &args[N]);
	
	// astept terminarea thread-urilor
	for (i = 0; i < (N + 1); i++)
	{
		pthread_join(tid[i], NULL);
	}
	
	// masor timpul de executie
	struct timeval stop;
	gettimeofday(&stop, NULL);
	long secs = stop.tv_sec - start.tv_sec;
	long usecs = stop.tv_usec - start.tv_usec;
	double elapsed = secs + 1e-6*usecs;
	printf("Timp executie: %.3f secunde\n", elapsed);
	
	// dealoc variabilele
	pthread_cond_destroy(c1);
	pthread_cond_destroy(c2);
    pthread_mutex_destroy(mtx);
    free(args);
    free(c1);
	free(c2);
    free(mtx);
	free(pos);
	free(s);
	
	return 0;
}
