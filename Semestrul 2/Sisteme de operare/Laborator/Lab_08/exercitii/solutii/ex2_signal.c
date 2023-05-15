//
// ex_2.c
//
// Să se scrie un program C care creează un proces copil cu care comunică prin pipe. Procesul părinte citeşte de la tastatură
// un număr natural şi îl trimite prin pipe procesului copil, iar procesul copil verifică şi afişează dacă acest număr este prim.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>


unsigned int flag = 0;


void signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		//flag = 1;
		//printf("[In PARENT] Caught SIGUSR1 signal.\n");
		char msg[] = "[In PARENT] Caught SIGUSR1 signal.\n";
		write(STDOUT_FILENO, msg, sizeof(msg));
	}
}


int main(int argc, char* argv[])
{
	int pd[2];
	int res = pipe(pd);	// cream un pipe
	if (res == -1)
	{
		perror("pipe() error: ");
		exit(EXIT_FAILURE);
	}

	int pid = fork();	// cream procesul copil
	if (pid == -1)
	{
		perror("fork() error: ");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)		// in procesul copil
	{
		close(pd[1]);	// inchidem capatul pentru scriere

		while(1)
		{
			int n = 0;
			read(pd[0], &n, sizeof(int));	// citim din pipe
			printf("\t[In CHILD] Numarul citit este: %d\n", n);

			if (n % 2 == 0)
				kill(getppid(), SIGUSR1);

			if (n == 0)
				break;

			//sleep(2);
		}

		// inchidem capatul pentru citire
		close(pd[0]);	// inchidem capatul pentru citire

		printf("\t[In CHILD] I finished my job.\n");

		exit(EXIT_SUCCESS);
	}
	
	// in procesul parinte
	close(pd[0]);	// inchidem capatul pentru citire
	
	signal(SIGUSR1, signal_handler);

	while(1)
	{
		// citim numarul natural de la tastatura
		int n = 0;
		printf("[In PARENT] Introduceti un numar natural n: ");
		scanf("%d", &n);

		write(pd[1], &n, sizeof(int));	// scriem numarul citit in pipe

		if (n == 0)
			break;

		sleep(2);

		if (flag)
		{
			printf("[In PARENT] Child has said that number is ODD.\n");
			flag = 0;
		}
	}

	close(pd[1]);	// inchidem capatul pentru scriere

	// asteptam terminarea procesului copil
	int status;
	wait(&status);

	printf("[In PARENT] Child has finished with exit status: %d\n", status);

	printf("[In PARENT] I finished my job.\n");

	return 0;
}
