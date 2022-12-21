#include <stdio.h>
int main ()
{
   FILE *fp;
   int i, c, cnt=0;
   char buff[1000];
   fp = fopen("file1.txt","r");
   if(fp == NULL) 
   {
      perror("Error in opening file\n");
      return(-1);
   }
   do{
	for (cnt = 0; (c = fgetc(fp)) != '\n' && c != EOF; cnt++){
		buff[cnt] = c;
	}
	buff[cnt] = '\0';
	for(i=cnt-1;i>=0;i--)
		printf("%c", buff[i]);
	printf("\n");
	cnt=0;
	if( feof(fp) )
		break ;
   }while(1);
   fclose(fp);
   return(0);
}
