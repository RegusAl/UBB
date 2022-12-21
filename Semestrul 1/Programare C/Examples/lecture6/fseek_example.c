#include <stdio.h>
int main ()
{
   FILE *fp;
   fp = fopen("file.txt","w+");
   fputs("The first  string written", fp);
   fseek( fp, 4, SEEK_SET );
   fputs("second", fp);
   fclose(fp);
   return(0);
}
