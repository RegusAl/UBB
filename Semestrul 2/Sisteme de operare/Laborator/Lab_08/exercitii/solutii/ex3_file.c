//
// 3*. Să se scrie un program C care creează un proces copil cu care comunică prin pipe.
// Procesul părinte citeşte dintr-un fișier un caracter c şi un şir s şi le trimite prin pipe procesului copil,
// iar procesul copil verifică şi afişează numărul de apariţii ale caracterului c în şirul s.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int nr_aparitii(char ch, char sir[50])
{
	int count = 0;
	for(int i = 0; i < strlen(sir); i++)
		if(sir[i] == ch)
			count++;

	return count;
}


int main(int argc, char* argv[])
{
	// deschid fisierul
	FILE* fd = fopen("file1", "r");
	if (fd == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	
	int pd[2];
	int res = pipe(pd);
	if(res == -1)
	{
		perror("pipe()");
		exit(1);
	}

	int pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(1);
	}

	// in procesul copil
	if(pid == 0)
	{
		close(pd[1]);   // inchid capatul de scriere

		while(1)
		{
			char ch = '\0';
			read(pd[0], &ch, sizeof(char));
			printf("[COPIL] Am citit %c\n", ch);

			char sir[50] = "\0";
			read(pd[0], sir, sizeof(sir));
			printf("[COPIL] Am citit %s\n", sir);

			if(strcmp(sir, "stop") == 0)
				break;

			printf("Nr. aparitii: %d\n", nr_aparitii(ch, sir));
		}

		close(pd[0]);   // inchid capatul de citire
		
		exit(0);
	}

	// in procesul parinte
	close(pd[0]);   // inchid capatul de citire

	// citesc fisierul linie cu linie
	while(!feof(fd))
	{
		char ch;
		char sir[50];
		fscanf(fd, "%c %s\n", &ch, sir);
		
		write(pd[1], &ch, sizeof(char));

		sleep(1);

		write(pd[1], sir, strlen(sir));

		if(strcmp(sir, "stop") == 0)
			break;

		sleep(1);
	}

	wait(NULL);		// astept terminarea procesului copil

	close(pd[1]);   // inchid capatul de scriere
	fclose(fd);		// inchid fisierul
	
	return 0;
}
