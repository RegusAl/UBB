/*
3. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
Procesul părinte citeşte de la tastatură un caracter c şi un şir s şi le trimite prin pipe procesului copil,
iar procesul copil verifică şi afişează numărul de apariţii ale caracterului c în şirul s.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int fd[2];
	// verificam daca s-a creat pipe-ul
	int res = pipe(fd);
	if(res == -1) {
		perror("Eroare la crearea pipe-ului!");
		exit(EXIT_FAILURE);
	}
	// verificam daca s-a facut fork-ul
	int pid = fork();
	if(pid == -1) {
		perror("Eroare la fork!");
		exit(EXIT_FAILURE);
	}

	if(pid == 0) {
		close(fd[1]);
		while(1) {
			char c = '\0';
			read(fd[0], &c, sizeof(char));
			printf("[CHILD] Am citit %c\n", c);

			char sir[50] = "\0";
			read(fd[0], sir, sizeof(sir));
			printf("[CHILD] Am citit %s\n", sir);

			if(strcmp(sir, "stop") == 0) {
				break;
			}

			int nr = 0;
			for(int i = 0; i<strlen(sir); i++) {
				if(sir[i] == c) {
					nr++;
				}
			}		
			printf("Numarul de aparitii: %d", nr);	

			sleep(2);		
		}
		close(fd[0]);
		exit(0);
	}

//	close(fd[0]);
	while(1) {
		
		close(fd[0]);
		char caracter;
		printf("Caracterul: ");
		scanf("%c", &caracter);
		write(fd[1], &caracter, sizeof(char));

		getchar();
		sleep(2);

		char sir[50];
		printf("Sirul: ");
		scanf("%s", sir);
		write(fd[1], &sir, strlen(sir));

		if(strcmp(sir, "stop") == 0)
			break;
		
		getchar();
		sleep(2);
	}	
	
	int status;
	wait(&status);
	//wait(NULL);
	close(fd[1]);

	return 0;
}
