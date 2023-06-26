#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void* roll_dice() {
	int value = (rand() % 6) + 1;
	int* result = malloc(sizeof(int));
//	printf("%d\n", value);
	*result = value;
	return (void*) result;
}

int main(int argc, char** argv) {
	int* res;

	srand(time(NULL));

	pthread_t th[100];
	
	for(int i = 0; i < 3; i++) {
		if(pthread_create(&th[i], NULL, &roll_dice, NULL)!=0) {
                	return 1;
		}
        }
	
	for(int i = 0; i < 3; i++) {
		if(pthread_join(th[i], (void**) &res)!=0) {
                	return 2;
        	}
		printf("result: %d\n", *res);
	}
	

	free(res);

	return 0;
}
