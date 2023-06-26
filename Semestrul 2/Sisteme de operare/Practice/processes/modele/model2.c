/*
model2: Se fac 2 procese, unul din ele genereaza random un n si citeste de la tastatura un k, 
le trimite prin pipe la celalalt proces. Al doilea proces, daca k e par face suma cifrelor lui n, altfel 
face produsul cifrelor lui n si scrie in fisier rezultatul obtinut.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	
	if(argc != 2) {
		perror("Dati un fisier in linia de comanda!");
		exit(EXIT_FAILURE);
	}

	FILE *fd;
	fd = fopen(argv[1], "w");
	if(fd == NULL) {
		perror("Fisierul nu s-a putut deschide!");
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

	int n, k;
	// procesul copil
	if(pid == 0) {

		while(1) {
			read(f[0], &n, sizeof(int));
			read(f[0], &k, sizeof(int));
			if(k == 0) break;
			int sum = 0, prod = 1, copie = n;
			while(copie) {
				sum += copie%10;
				prod *= copie%10;
				copie = copie / 10;
			}
			if(k%2==0) {
				fprintf(fd, "k = %d, n = %d, suma = %d\n", k, n, sum);
			} else {
				fprintf(fd, "k = %d, n = %d, produsul = %d\n", k, n, prod);
			}
		}
		close(f[1]);
		close(f[0]);
		exit(0);
	}


	// procesul parinte
	while(1) {
		n = rand()%100;
		printf("K = ");
		scanf("%d", &k);
		write(f[1], &n, sizeof(int));
		write(f[1], &k, sizeof(int));
		if(k == 0) break;

	}
	close(f[0]);
	close(f[1]);
	int signal;
	wait(&signal);
	fclose(fd);


	return 0;
}

