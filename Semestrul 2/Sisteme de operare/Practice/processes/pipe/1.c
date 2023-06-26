#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int n; // numarul 
	int fd[2]; // descriptor de fisier
	int res = pipe(fd);
	if(res == -1) {			// daca a esuat pipe-ul
		perror("pipe()");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if(pid == -1) {			// daca a esuat fork-ul
		perror("fork()");
		exit(EXIT_FAILURE);
	}

	// procesul copil
	if(pid == 0) {
		close(fd[1]); // inchidem descriptorul de scriere
		while(1) {
			read(fd[0], &n, sizeof(int));
			if(n == 0)
				break;
			printf("[CHILD] n = %d\n", n);
			if(n % 2 == 0)
				printf("[CHILD] n este par!\n");
			else
				printf("[CHILD] n este impar!\n");
			sleep(2);
		}
		close(fd[0]);
		exit(EXIT_SUCCESS);
	}

	// procesul parinte
	while(1) {
		close(fd[0]);

		printf("n: ");
		scanf("%d", &n);

		write(fd[1], &n, sizeof(int));

		if (n == 0) {
			printf("Iesire din program!\n");
			break;
		}

		sleep(2);
	}

	int status;
	wait(&status);

	close(fd[1]);

	return 0;
}
	
