/*
2. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură un număr natural şi îl trimite prin pipe procesului copil,
iar procesul copil verifică şi afişează dacă acest număr este prim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int prim(int n) {
	for(int d = 2; d <= n/2; d++) {
		if(n%d==0)
			return 0;
	}
	return 1;
}

int main(int argc, char * argv[]) {

	int n, fd[2];
	int res = pipe(fd);
	if(res == -1) {
		perror("Eroare la pipe!");
		exit(EXIT_FAILURE);
	}	

	int pid = fork();
	if(pid == -1) {
		perror("Eroare la fork!");
		exit(EXIT_FAILURE);
	}

	// procesul copil
	if(pid == 0) {
		close(fd[1]);
		while(1) {
			read(fd[0], &n, sizeof(int));
			if(n == 0)
				break;
			printf("[CHILD] n = %d\n", n);
			if(prim(n)==1)
				printf("[CHILD] n este prim\n");
			else
				printf("[CHILD] n este neprim\n");
			sleep(2);	
		}
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}

	// procesul parinte
	while(1) {
		close(fd[0]);

		printf("N: ");
		scanf("%d", &n);

		write(fd[1], &n, sizeof(int));

		if(n == 0)
			break;

		sleep(2);
	}

	int status;
	wait(&status);
	close(fd[1]);

	return 0;
} 
