
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
	
int main(){
	int n;
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
	return 0;
}	
