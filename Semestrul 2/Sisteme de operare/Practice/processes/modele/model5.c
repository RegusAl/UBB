/*
model5: acelasi lucru ca la 4, dar avem in fisier o litera si un cuvant, trebuie sa spunem ultima poz pe care
apare litera in cuvant (-1 daca nu apare deloc)
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv) {

	if(argc != 2) {
		perror("Dati un fisier in lina de comanda!");
		exit(EXIT_FAILURE);
	}

	FILE* fd;
	fd = fopen(argv[1], "r");
	if(fd == NULL) {
		perror("Fisierul nu a putut fi deschis!");
		exit(EXIT_FAILURE);
	}

	int f[2];
	int res = pipe(f);
	if(res == -1) {
		perror("Pipe-ul a esuat!");
		exit(EXIT_FAILURE);
	}

	int pid = fork();
	if(pid == -1) {
		perror("Fork-ul a esuat!");
		exit(EXIT_FAILURE);
	}

	char litera, sir[100];
	// procesul copil
	if(pid == 0) {
		
		while(1) {
			read(f[0], &litera, sizeof(char));
			if(litera == '0') break;
			read(f[0], &sir, sizeof(sir));
			int poz = -1;
			for(int i = 0; i<strlen(sir); i++) {
				if(sir[i] == litera) {
					poz = i;
					break;
				}
			}		
			printf("Litera: %c, Cuvantul: %s, Pozitia: %d\n", litera, sir, poz);
		}
		close(f[0]);
		close(f[1]);
		exit(0);
	}


	// procesul parinte
	while(fscanf(fd, "%c %s\n", &litera, sir)!=-1) {
		//printf("%c\n", litera);
		write(f[1], &litera, sizeof(char));
		write(f[1], &sir, sizeof(sir));
	}
	char c = '0';
	write(f[1], &c, sizeof(char));
	close(f[1]);
	close(f[0]);
	
	int signal;
	wait(&signal);
	
	fclose(fd);

	return 0;
}


