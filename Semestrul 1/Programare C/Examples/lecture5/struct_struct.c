#include <stdio.h>

int main(){

struct address{
	  unsigned int house_number;
	  char *street_name;
	  int zip_code;
	  char *country;
	};
struct customer{
	  char *name;
	  struct address billing;
	  struct address shipping;
	};
struct customer c1;
c1.name="John Spencer";
c1.billing.street_name="Second Avenue";
c1.shipping.street_name=c1.billing.street_name;

printf("%s, %s\n", c1.name, c1.billing.street_name);

return 0;
}

