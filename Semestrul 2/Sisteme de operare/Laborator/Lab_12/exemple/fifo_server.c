//
// fifo_server.c - Using a POSIX named semaphore
//
// Semaphores allow processes and threads to synchronize their actions.
// A semaphore is an integer whose value is never allowed to fall below zero.
// Two operations can be performed on semaphores:
// - decrement the semaphore value by one: sem_wait()
// - increment the semaphore value by one sem_post()
// If the value of a semaphore is currently zero, then a sem_wait() operation will block until the value becomes greater than zero.
//
// Launch this program first in order to create the semaphore.
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	sem_t* sem = sem_open("/semlock", O_CREAT, 0600, 1);
	if (sem == NULL)
	{ 
		perror("sem_open()");
		exit(EXIT_FAILURE);
	}
	printf("[Server] Semaphore is created.\n");

	int pd = open("test-fifo", O_RDONLY);
	if (pd < 0)
	{
		perror("open(): ");
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		int n1;
		int rc = read(pd, &n1, sizeof(int));
		if (rc == 0)
		{
			printf("\n[Server] Client has gone. Trying to break ...\n");
			break;
		}

		int n2;
		read(pd, &n2, sizeof(int));

		printf("[Server]  n1: %3d\n", n1);
		printf("[Server]  n2: %3d\n", n2);
		printf("[Server] Sum: %3d\n", n1 + n2);
	}
	
	close(pd);
	sem_close(sem);

	sem_unlink("/semlock");
	printf("[Server] Semaphore is destroyed.\n");

	return 0;
} 
