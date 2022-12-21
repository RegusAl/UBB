#include <stdio.h>

int main(){
	typedef struct node{
		int value;
		struct node* next;
	} nodes;
	nodes n1, n2, n3;
	nodes *start, *ptr;
	n1.value=1;
	n2.value=2;
	n3.value=3;
	n1.next=&n2;
	n2.next=&n3;
	n3.next=NULL;
	start=&n1;
	ptr=start;
	printf("\n%d", ptr->value);
	ptr=ptr->next;
	printf("%d\n", ptr->value);
	return 0;
}
