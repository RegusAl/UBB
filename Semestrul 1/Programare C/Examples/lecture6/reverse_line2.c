#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
   FILE *fp;
   int c;
   char buff[1000];
   fp = fopen("file1.txt", "r");
   while (1) {
        if (fgets(buff,1000, fp) == NULL) break;
	for(c=(int)strlen(buff);c>=0;c--)
		printf("%c",buff[c]);
  }
return 0;
}
