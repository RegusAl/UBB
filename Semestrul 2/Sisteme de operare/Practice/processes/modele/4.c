#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	
	if(argc != 2) {
		perror("Dati un fisier la apelarea comenzii!");
		exit(EXIT_FAILURE);
	}

	FILE *fd;
	fd = fopen(argv[1], "r");
	if(fd == NULL) {
		perror("Eroare la deschiderea fisierului!");
		exit(EXIT_FAILURE);
	}

	int f[2];
	int res = pipe(f);
	if(res == -1) {
		perror("Eroare pipe!");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if(pid == -1) {
		perror("Eroare fork!");
		exit(EXIT_FAILURE);
	}

	char caracter;
	int numar;
	// procesul copil
	if(pid == 0) {

		while(1) {
			read(f[0], &caracter, sizeof(char));
			if(caracter == '0') 
				break;
			read(f[0], &numar, sizeof(int));
			int sum = 0, prod = 1;
			
			int copie = numar;
			while(copie) {
				sum += copie % 10;
				prod *= copie % 10;
				copie /= 10;
			}
			if(caracter == '+') 
				printf("%c %d %d\n", caracter, numar, sum);
			else if(caracter == '*')
				printf("%c %d %d\n", caracter, numar, prod);
		}
		close(f[0]);
		close(f[1]);
		exit(EXIT_SUCCESS);
	}

	// procesul parinte
	while(fscanf(fd, "%c %d\n", &caracter, &numar)!=-1) {
		write(f[1], &caracter, sizeof(char));
		write(f[1], &numar, sizeof(int));
	}
	char c = '0';
	write(f[1], &c, sizeof(char));
	int status;
	wait(&status);
	close(f[0]);
	close(f[1]);
	fclose(fd);
	return 0;
}
