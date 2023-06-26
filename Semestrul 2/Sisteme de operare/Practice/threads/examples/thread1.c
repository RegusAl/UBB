#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 100		// max threads

void *f(void *a) {
	int k = *(int*)a;
	printf("Thred-ul %d\n", k);
	return NULL;
}

int main(int argc, char** argv) {
	pthread_t t[MAX_NUM];

	int i;

	for(int i = 0; i < MAX_NUM; i++) {
		pthread_create(&t[i], NULL, f, &i); // create a thread
	}

	for(int i = 0; i < MAX_NUM; i++) {
		pthread_join(t[i], NULL);
	}

	return 0;
}
