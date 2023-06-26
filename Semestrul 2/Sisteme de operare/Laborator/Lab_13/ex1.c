/*

31. Scrieti un program C care primeste un numar N ca argument la linia de comanda. Programul creeaza N thread-uri care vor genera numere aleatoare intre 0 si 111111 (inclusiv) pana cand un thread va genera un numar divizibil cu 1001. Thread-urile vor afisa numerele generate, iar ultimul numar afisat trebuie sa fie cel divizibil cu 1001. Niciun thread nu va incepe sa genereze numere pana cand toate celelalte thread-uri au fost create. Nu se vor folosi variabile globale.

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>


typedef struct
{
	int id;
	int *flag;
    pthread_mutex_t *m;
    pthread_barrier_t *b;
} data;


void* generate(void* arg)
{
	data td = *((data*)arg);
	
	// niciun thread nu va incepe sa genereze numere pana cand toate celelalte thread-uri au fost create
	pthread_barrier_wait(td.b);
	
	// generez numere aleatoare
	while(1)
	{
        int nr = random() % 111112;
        pthread_mutex_lock(td.m);
        if(*(td.flag) == 0)
		{
            printf("Thread %d: %d\n", td.id, nr);
            if(nr % 1001 == 0)
			{
                *(td.flag) = 1;
                break;
            }
        }
		else
		{
            break;
		}
        pthread_mutex_unlock(td.m);
        usleep(100);
    }
    pthread_mutex_unlock(td.m);
	
	return NULL;
}


int main(int argc, char* argv[])
{
	// verific numarul de argumente
	if (argc < 2)
	{
		printf("Trebuie sa furnizati un argument.\n");
		printf("Utilizare: %s N\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	// obtin numarul de thread-uri
	int N = atoi(argv[1]);
	
	// initializez generatorul de numere aleatoare
	srand(time(NULL));
	
	// aloc dinamic variabilele
	int *flg = malloc(sizeof(int));
	*flg = 0;
	
	pthread_mutex_t *mtx = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mtx, NULL);
	
	pthread_barrier_t *barr = malloc(sizeof(pthread_barrier_t));
	pthread_barrier_init(barr, NULL, N);
	
	// creez cele N thread-uri
	pthread_t tid[N];
	data *args = malloc(N * sizeof(data));
	for (int i = 0; i < N; i++)
	{
		args[i].id = i;
        args[i].flag = flg;
        args[i].m = mtx;
        args[i].b = barr;
		pthread_create(&tid[i], NULL, generate, &args[i]);
	}
	
	// astept terminarea thread-urilor
	for (int i = 0; i < N; i++)
	{
		pthread_join(tid[i], NULL);
	}
	
	// dealoc variabilele
    pthread_mutex_destroy(mtx);
	pthread_barrier_destroy(barr);
    free(args);
    free(barr);
    free(mtx);
    free(flg);
	
	return 0;
}
