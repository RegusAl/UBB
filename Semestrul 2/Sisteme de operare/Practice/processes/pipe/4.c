/*
4. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură două numere întregi pe care le trimite prin pipe procesului copil, iar procesul copil returnează prin pipe suma lor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int fd[2];

	// verificam daca s-a creat pipe-ul
	int res = pipe(fd);
	if(res == -1) {
		perror("Eroare pipe()");
		exit(EXIT_FAILURE);
	}

	// verificam daca s-a facut fork
	int pid = fork();
	if(pid == -1) {
		perror("Eroare fork()");
		exit(EXIT_FAILURE);
	}

	// procesul copil
	if (pid == 0) {
		
		close(fd[1]);
		int nr1, nr2;
		read(fd[0], &nr1, sizeof(int));
		printf("[CHILD] nr1 = %d\n", nr1);
		read(fd[0], &nr2, sizeof(int));
                printf("[CHILD] nr1 = %d\n", nr2);

		printf("Suma este: %d\n", nr1+nr2);
		close(fd[0]);
		exit(0);
	}


	// procesul parinte
	close(fd[0]);
	
	int nr1, nr2;
	printf("nr1 = ");
	scanf("%d", &nr1);

	write(fd[1], &nr1, sizeof(int));

	sleep(1);
	printf("nr2 = ");
	scanf("%d", &nr2);


	write(fd[1], &nr2, sizeof(int));

	sleep(1);	

	int status;
	wait(&status);
	
	close(fd[1]);
	return 0;
}
