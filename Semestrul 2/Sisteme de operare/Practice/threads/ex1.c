#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <limits.h>

#define MAX_THR 50
#define MAX_NUM 100000

int minims[MAX_THR];
int numbers[MAX_NUM];
int i;

void* do_work(void *a) {
	int tnum = *(int*)a;
	free(a);
	int min = INT_MAX;
	int st = tnum * (MAX_NUM / MAX_THR);
	int dr = st + MAX_NUM / MAX_THR;
	for(int i = st; i < dr; i++) {
		if(numbers[i] < min)
			min = numbers[i];
	}
	printf("[THREAD %d] minim: %d\n", tnum, min);

	minims[tnum] = min;

	return NULL;
}


int main(int argc, char** argv) {

//	srand(time(NULL));
//	for(int i = 0; i < MAX_NUM; i++) {
//		numbers[i] = rand() % 100;
//		printf("%d ", numbers[i]);
//	}

	int fd = open("random-file", O_RDONLY);
	if(fd == -1) {
		perror("open()");
		exit(EXIT_FAILURE);
	}

	for(int i = 0; i < MAX_NUM; i++) {
		read(fd, &numbers[i], 2);
	}

	pthread_t tid[MAX_THR];
	for(i = 0; i < MAX_THR; i++) {
		int *n = (int*)malloc(sizeof(int));
		*n = i;
		pthread_create(&tid[i], NULL, do_work, n);
	}

	for(i = 0; i < MAX_THR; i++) {
		pthread_join(tid[i], NULL);
	}

	int min = INT_MAX;
	for(i = 0; i < MAX_THR; i++) {
		printf("%d ", minims[i]);
		if(minims[i] < min)
			min = minims[i];
		//printf("%d ", min);
	}

	printf("MINIM: %d\n", min);

	close(fd);

	return 0;
}
