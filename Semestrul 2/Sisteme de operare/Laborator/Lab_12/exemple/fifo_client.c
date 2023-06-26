//
// fifo_client.c - Using a POSIX named semaphore
//
// Semaphores allow processes and threads to synchronize their actions.
// A semaphore is an integer whose value is never allowed to fall below zero.
// Two operations can be performed on semaphores:
// - decrement the semaphore value by one: sem_wait()
// - increment the semaphore value by one: sem_post()
// If the value of a semaphore is currently zero, then a sem_wait() operation will block until the value becomes greater than zero.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Not enough arguments !\n");
		printf("Usage: %s seed_value\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sem_t* sem = sem_open("/semlock", 0);
	if (sem == NULL)
	{ 
		perror("sem_open()");
		exit(EXIT_FAILURE);
	}

	int pd = open("test-fifo", O_WRONLY);
	if (pd < 0)
	{
		perror("open(): ");
		exit(EXIT_FAILURE);
	}
	
	int i = 0;
	int seed = atoi(argv[1]);
	srand(seed);
	while (i < 10)
	{
		int n1 = rand() % 100;
		int n2 = rand() % 100;

		sem_wait(sem);
		printf("\n[Client] Semaphore is locked.\n");

		printf("[Client] n1: %3d\n", n1);
		write(pd, &n1, sizeof(int));
		printf("[Client] n2: %3d\n", n2);
		write(pd, &n2, sizeof(int));

		sem_unlock(sem);
		printf("[Client] Semaphore is unlocked.\n");

		i++;

		sleep(2);
	}
	
	close(pd);
	sem_close(sem);
	
	return 0;
} 
