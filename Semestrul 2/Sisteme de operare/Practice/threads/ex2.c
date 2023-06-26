#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

#define MAX_NUM 100000
#define MAX_THR 50

int numbers[MAX_NUM];
int minims[MAX_THR];

//pthread_barrier_t barr;


void* do_work(void *a) {
	int tnum = *(int*)a;
	free(a);

	int i;
	int min = INT_MAX;
	int st = tnum * (MAX_NUM / MAX_THR);
	int dr = st + MAX_NUM / MAX_THR;
	for(i = st; i < dr; i++) {
		if(numbers[i] < min)
			min = numbers[i];
	}

	minims[tnum] = min;

//	printf("[THREAD %d] a ajuns la bariera\n", tnum);
//	pthread_barrier_wait(&barr);

	int sum = 0;
	for(i = 0; i < MAX_THR; i++)
		sum += minims[i];

	float mean = sum / MAX_THR;
	float diff = fabs(mean - min);
	printf("[THREAD %d] min: %d medie: %f diferenta: %f\n", tnum, min, mean, diff);

	return NULL;
}


int main(int argc, char** argv) {

	// deschidere fisier
	int fd = open("random-file", O_RDONLY);
	if(fd == -1) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	int i;
	// citim numerele
	for(i = 0; i < MAX_NUM; i++) {
		read(fd, &numbers[i], 2);
//		printf("%d ", numbers[i]);
	}

	// cream bariera
//	pthread_barrier_init(&barr, NULL, MAX_THR);

	// cread thread-urile
	pthread_t tid[MAX_THR];
	for(i = 0; i < MAX_THR; i++) {
		int *n = (int*)malloc(sizeof(int));
		*n = i;
		pthread_create(&tid[i], NULL, do_work, n);
	}

	for(i = 0; i < MAX_THR; i++) {
		pthread_join(tid[i], NULL);
	}

//	pthread_barrier_destroy(&barr);

	close(fd);

	return 0;
}
