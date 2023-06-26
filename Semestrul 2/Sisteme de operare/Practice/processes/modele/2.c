#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {

	if(argc != 2) {
		perror("Dati fisierul ca argument!");
		exit(EXIT_FAILURE);
	}

	// verificam daca s-a efectuat pipe
	int f[2];
	int res = pipe(f);
	if(res == -1) {
		perror("Pipe-ul a esuat!");
		exit(EXIT_FAILURE);
	}

	// verificam daca s-a efectuat fork-ul
	int pid = fork();
	if(pid == -1) {
		perror("Fork-ul a esuat!");
		exit(EXIT_FAILURE);
	}

	char semn;
	int a, b;
	// procesul copil
	if(pid == 0) {
		
		while(1) {
			read(f[0], &semn, sizeof(char));
			if(semn == '0')
				break;
			read(f[0], &a, sizeof(int));
			//sleep(2);
			read(f[0], &b, sizeof(int));
			if(semn == '+') 
				printf("%d + %d = %d\n", a, b, a + b);
			if(semn == '-')
				printf("%d - %d = %d\n", a, b, a - b);	
		}
		close(f[1]);
		close(f[0]);
		exit(0);
	}
	



	// procesul parinte
	FILE *fd;
	fd = fopen(argv[1], "r");
	if(fd == NULL) {
		perror("Eroare la deschiderea fisierului!");
		exit(EXIT_FAILURE);
	}

	while(fscanf(fd, "%c %d %d\n", &semn, &a, &b)!=-1) {
		
				
		//printf("Semnul: ");
		//scanf("%c", &semn);
		write(f[1], &semn, sizeof(char));
		//if(semn == 'x')
                  //      break;  
	//	sleep(2);
	//	printf("A = ");
	//	scanf("%d", &a);
		write(f[1], &a, sizeof(int));
	//	sleep(2);
	//	printf("B = ");
	//	scanf("%d", &b);
                write(f[1], &b, sizeof(int));
	//	sleep(2);
			
	}
	char c = '0';
	write(f[1], &c, sizeof(char));
	close(f[0]);
	close(f[1]);
	int signal;
	wait(&signal);
	fclose(fd);
	return 0;
}
