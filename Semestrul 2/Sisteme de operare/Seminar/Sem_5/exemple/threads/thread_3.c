//
// thread_3.c - Thread creation example
//
// pthread_create() - create a thread
// pthread_join()   - wait for termination of another thread
//

#include <stdio.h>
#include <pthread.h>

#define MAX_THR 100                             // maximum number of threads

//
// The thread start routine
//
void* f(void* a)
{
    int k = *(int*)a;
    printf("Eu sunt thread-ul %d\n", k);

    return NULL;
}


int main(int argc, char* argv[])
{
	int p[MAX_THR];
	pthread_t tid[MAX_THR];                     	// an array of thread IDs
    for (int i = 0; i < MAX_THR; i++)
    {
        p[i] = i;
        pthread_create(&tid[i], NULL, f, &p[i]);	// create a thread
    }

    for (int i = 0; i < MAX_THR; i++)
    {
        pthread_join(tid[i], NULL);             	// wait for each thread to finish
    }

    return 0;
}
