//
// with_lock.c
//
// Increment a variable in 100 threads using a mutex (mutual exclusion lock)
//
// pthread_mutex_lock()   - acquire a lock on the specified mutex variable. If the mutex is already locked by another thread,
//                          this call will block the calling thread until the mutex is unlocked.
//
// pthread_mutex_unlock() - unlock a mutex variable. An error is returned if mutex is already unlocked or owned by another thread.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THR 100                             	// maximum number of threads

int val = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;	// create a mutex

//
// The thread start routine
//
void* f(void* a)
{
    int k = *(int*)a;
    free(a);

    //int b = val;
    //sleep(1);
    //val = b + 1;

	pthread_mutex_lock(&mtx);		// lock
    val = val + 1;
	pthread_mutex_unlock(&mtx);		// unlock
    printf("Thread %2d - val: %d\n", k, val);

    return NULL;
}


int main(int argc, char* argv[])
{
    pthread_t tid[MAX_THR];                     // an array of thread IDs
    for (int i = 0; i < MAX_THR; i++)
    {
        int* p = (int*)malloc(sizeof(int));
        *p = i;
        pthread_create(&tid[i], NULL, f, p);    // create a thread
    }

    for (int i = 0; i < MAX_THR; i++)
    {
        pthread_join(tid[i], NULL);             // wait for each thread to finish
    }

    return 0;
}
