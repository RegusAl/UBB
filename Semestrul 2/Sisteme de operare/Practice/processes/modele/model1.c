//model1: 
//Un proces A genereaza 2 numere random si citeste de la tastatura un simbol aritmetic sau 0 (*/:)
//Procesul A ii transmite procesului B prin pipe cele doua numere si simbolul aritmetic iar 
//procesul B realizeaza 
//operatia si o scrie intr un fisier.Cele doua procese isi incheie executia doar cand simbolul este citit 0.
//Deci trebuie un loop.
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
	
	// verificam daca este fisier dat in linia de comanda
	if(argc != 2) {
		perror("Dati un fisier in linia de comanda! Exemplu: comanda [fisier]");
		exit(EXIT_FAILURE);
	}

	// verificam daca s-a deschis fisierul
	FILE *fd;
	fd = fopen(argv[1], "w");
	if(fd == NULL) {
		perror("Fisierul nu a putut fi deschis!");
		exit(EXIT_FAILURE);
	}
	
	// verificam pipe-ul
	int f[2];
	int res = pipe(f);
	if(res == -1) {
		perror("Pipe-ul a esuat!");
		exit(EXIT_FAILURE);
	}

	// verificam fork-ul
	int pid = fork();
	if(pid == -1) {
		perror("Fork-ul a esuat!");
		exit(EXIT_FAILURE);
	}
	int a, b;
	char semn;
	// procesul copil
	if(pid == 0) {
		
		while(1) {
			read(f[0], &semn, sizeof(char));
			
			read(f[0], &a, sizeof(int));
			read(f[0], &b, sizeof(int));
			if(semn == 'x') break;
			if(semn == '*') {
				fprintf(fd, "%d * %d = %d\n", a, b, a*b);
			} else if(semn == '/') {
				fprintf(fd, "%d / %d = %d\n", a, b, a/b);
			}
		}
		close(f[0]);
		close(f[1]);
		exit(EXIT_SUCCESS);
	}


	// procesul parinte
	while(1) {
		int a = rand()%100;
		int b = rand()%100;
		char semn;
		printf("Semn (*, /, 0) : ");
		scanf("%c", &semn);
	
		write(f[1], &semn, sizeof(char));
		
		write(f[1], &a, sizeof(int));
	
		write(f[1], &b, sizeof(int));
	
		if(semn == 'x') break;
	//	sleep(2);
	}
	close(f[0]);
	close(f[1]);
	int signal;
	wait(&signal);
	fclose(fd);
	return 0;
}
