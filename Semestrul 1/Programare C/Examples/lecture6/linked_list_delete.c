
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int num;
	struct node *next;
	} node, *nodeptr;

void print_list(nodeptr head){
	while(head!=NULL){
		printf("%d ",head->num);
		head=head->next;
	}
	printf("\n");
}

nodeptr delete(nodeptr head, int value)
{
	if (head == NULL)
		return NULL;

	if (head->num == value) {
		nodeptr tempNextP;
		tempNextP = head->next;
		free(head);
		return tempNextP;
	}
	head->next = delete(head->next, value);
	return head;
}
	
int main(){
	int n, val;
	nodeptr head, new;
	head=NULL;
	if(scanf("%d", &n)!=1) n=0;
	while(n!=0){
		new=malloc(sizeof(node));
		new->num=n;
		new->next=head;
		head=new;
		if(scanf("%d", &n)!=1) n=0;
	}
	print_list(head);

	printf("Insert value to remove: ");
	scanf("%d",&val);
	printf("\n");
	head=delete(head,val);
	print_list(head);
	return 0;
}	
