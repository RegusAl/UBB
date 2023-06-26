#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THR 10

void* f(void *a) {
	int tnum = *(int*)a;
	free(a);
	printf("THREAD %d \n", tnum);
	return NULL;
}

int main(int argc, char** argv) {

	if(argc != 2) {
		perror("Dati un argument in linia de comanda!\n");
		exit(EXIT_FAILURE);
	}

	printf("%s \n", argv[1]);

	FILE *fd;
	fd = fopen(argv[1], "w");
	if(fd == NULL) {
		perror("Fisierul nu a putut fi deschis!\n");
		exit(EXIT_FAILURE);
	}

	pthread_t tid[MAX_THR];

	int i;
	for(i = 0; i < MAX_THR; i++) {
		int *n = (int*)malloc(sizeof(int));
		*n = i;
		pthread_create(&tid[i], NULL, f, n);
	}

	for(i = 0; i < MAX_THR; i++) {
		pthread_join(tid[i], NULL);
	}

	fclose(fd);

	return 0;
}

