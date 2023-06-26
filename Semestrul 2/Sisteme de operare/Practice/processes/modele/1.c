#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	if(argc!=2) {
		perror("Da un fisier ca argument!");
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

	int n, k, rez;
	
	// procesul copil
	if(pid == 0) {
		FILE *fd;
		fd = fopen(argv[1], "w");
		if(fd == NULL) {
			perror("Eroare la deschiderea fisierului!");
			exit(EXIT_FAILURE);
		}
		int rez1, rez2;
		while(1) {
			read(f[0], &n, sizeof(int));
			rez1 = 0;
			rez2 = 1;
			read(f[0], &k, sizeof(int));
			if(k==0)
				break;
			int copy = k;
			if(n%2==0) {
				// facem suma cifrelor
				while(k) {
					rez1 = rez1 + k%10;
					k = k/10;
				}
				rez = rez1;
			} else {
				while(k) {
					rez2 = rez2*(k%10);
					k = k/10;
				}
				rez = rez2;
			}
			fprintf(fd, "n: %d, k: %d -> %d\n", n, copy, rez);
			printf("n: %d, k: %d -> %d\n", n, copy, rez);
		}
		close(f[1]);
		close(f[0]);
		exit(0);
	}

	// procesul parinte
	while(1) {
		n = rand() % 100;
		printf("K: ");
		scanf("%d", &k);
		write(f[1], &n, sizeof(int));
		write(f[1], &k, sizeof(int));
		if(k==0) break;
	}
	
	close(f[1]);
	close(f[0]);

	int status;
	wait(&status);
	


	return 0;
}
