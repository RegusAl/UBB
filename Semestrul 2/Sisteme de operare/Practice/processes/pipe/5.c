/*
5. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte dintr-un fişier de tip text două numere întregi pe care le trimite prin pipe procesului copil,
iar procesul copil returnează prin pipe suma lor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	int f2c[2];
	// verificam daca s-a efectuat pipe-ul
	int res1 = pipe(f2c);
	if(res1 == -1) {
		perror("Eroare la pipe catre CHILD\n");
		exit(EXIT_FAILURE);
	}

	int c2f[2];
	int res2 = pipe(c2f);
	if(res2 == -1) {
		perror("Eroare la pipe catre FATHER");
	}

	// verificam daca s-a efectuat fork
	int pid = fork();
	if(pid == -1) {
		perror("Eroare la fork\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {

		close(c2f[0]);
		close(f2c[1]);

		while(1) {
			int a;
			read(f2c[0], &a, sizeof(int));
			printf("[CHILD] a = %d\n", a);

			if(a == 0)
				break;

			int b;
			read(f2c[0], &b, sizeof(int));
			printf("[CHILD] b = %d\n", b);

			int sum = a + b;
			write(c2f[1], &sum, sizeof(int));
		}

		close(f2c[0]);
		close(c2f[1]);
		exit(EXIT_SUCCESS);
	}

	close(c2f[1]);
	close(f2c[0]);

	while(1) {

		int a, b;
		printf("[PARENT] a = ");
		scanf("%d", &a);
		write(f2c[1], &a, sizeof(int));

		if(a == 0)
			break;

		sleep(1);

		printf("[PARENT] b = ");
		scanf("%d", &b);
		write(f2c[1], &b, sizeof(int));

		int sum = 0;
		read(c2f[0], &sum, sizeof(int));
		printf("[PARENT] sum = %d\n", sum);
	}

	int status;
	wait(&status);
	printf("[PARENT] status: %d\n", status);
	close(c2f[0]);
	close(f2c[1]);

	return 0;
}
