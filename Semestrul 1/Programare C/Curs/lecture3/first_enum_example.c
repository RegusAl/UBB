#include <stdio.h> 

int main()
{
	enum Days {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

	enum Days aDay;

	int i = 0;
	printf("Please enter the day of the week (0 to 6)\n");
	scanf("%d",&i);
	aDay=i;

	if(aDay == Sunday || aDay == Saturday)
		printf("Hurray it is the weekend\n");
	else
		printf("Curses still at work\n");

	return 0;
}

