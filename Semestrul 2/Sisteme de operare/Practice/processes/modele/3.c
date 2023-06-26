#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv) {
	
	// verificam fisierul
	if (argc != 2) {
		perror("Dati un fisier in linia de comanda!");
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
		perror("Eroare la pipe!");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if(pid == -1) {
		perror("Eroare la fork!");
		exit(EXIT_FAILURE);
	}

	char caracter, sir[100];
	// procesul copil
	if(pid == 0) {
		int poz = -1;
		while(1) {
		
			read(f[0], &caracter, sizeof(char));
			if(caracter == '0')
				break;
			read(f[0], sir, sizeof(sir));
			poz = -1;
			for(int i = 0; i<strlen(sir); i++) {
				if(caracter == sir[i]) {
					poz = i;
					break;
				}	
			}
			printf("%c %s %d\n", caracter, sir, poz);
		}
		close(f[0]);
		close(f[1]);
		exit(EXIT_SUCCESS);
	}


	// procesul parinte
	while(fscanf(fd, "%c %s\n", &caracter, sir)!=-1) {
		write(f[1], &caracter, sizeof(char));
		write(f[1], sir, sizeof(sir));
	}
	char c = '0';
	write(f[1], &c, sizeof(char));
	close(f[0]);
	close(f[1]);
	int status;
	wait(&status);
	return 0;
}
