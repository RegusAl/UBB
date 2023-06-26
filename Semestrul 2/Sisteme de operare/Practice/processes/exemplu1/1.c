#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int p;
	p = fork();
	if (p == -1) {
		perror("fork imposibil");
		exit(1);
	}
	printf("merge pana aici!!!\n");
	if(p == 0) {
		for(int i = 0; i < 10; i++) {
			printf("Fiu: i=%d pid=%d, ppid=%d\n", i, getpid(), getppid());
		}
		exit(0);
	} else {
		for(int i = 0; i < 10; i++) {
			printf("Parinte: i=%d pid=%d ppid=%d\n", i, getpid(), getppid());
		}
		exit(0);
	}
	printf("terminat; pid = %d ppid = %d\n", getpid(), getppid());
}
