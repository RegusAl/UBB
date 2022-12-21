#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
int i;

for(i = 0; i < argc; i++)
	printf("arg %d: %s\n", i, argv[i]);
i=0;
do{
	printf("env %d: %s\n", i, envp[i++]);
}while (envp[i]!=NULL);
return 0;
}
