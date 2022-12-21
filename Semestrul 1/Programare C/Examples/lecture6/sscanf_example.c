#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int mark;
   char student_firstname[50], student_lastname[50], in_string[100];

   strcpy( in_string, "John Doe 9" );
   sscanf( in_string, "%s %s %d", student_firstname, student_lastname, &mark );

   printf("Student %s %s received %d at the exam;\n", student_firstname, student_lastname, mark );
    
   return(0);
}
