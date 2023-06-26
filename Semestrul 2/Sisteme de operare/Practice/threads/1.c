#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

pthread_t citire, thr[30];
int n, nb, fr[100], v[10000];

int sum = 0, avr, minim = INT_MAX;

pthread_barrier_t barr;

void* cititor(void* a) {
	int fd = open("random-file", O_RDONLY);
	int i;
	for(i = 0; i < n; i++) {
		read(fd, &v[i], 1);
	}
	close(fd);
	return NULL;
}

void* worker(void* a) {
	int i, indice = *(int*)a;

	for(i = 0; i < n; i++) {
		if(v[i] == indice)
			fr[indice]++;
	}

	sum += fr[indice];

	
}

int prim(x) {
	if(x == 2) 
		return 1;
	for(int d = 2; d * d < x; d++) {
		if(x % d == 0)
			return 0;
	}
	return 1;
}


int main(int argc, char** argv) {

	int cnt = -1, i;
	int *aux;

	scanf("%d", &n);
	pthread_create(&citire, NULL, cititor, NULL);
	pthread_join(citire, NULL);

//	pthread_barrier_init(&barr, NULL, 25);

	for(i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}

	for(i = 2; i < 100; i++) {
		aux = (int*)malloc(sizeof(int));
		*aux = i;
		if(prim(i)==1) 
			pthread_create(&thr[++cnt], NULL, worker, aux);
	}

	return 0;
}
