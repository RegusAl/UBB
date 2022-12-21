
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int num;
	struct node *next;
	} node, *nodeptr;

nodeptr insertlist(nodeptr head, int n){
	nodeptr new, p, pp;
	new=malloc(sizeof(node));
	new->num=n;
	if(head==NULL){  // first number
		new->next=NULL;
		return new;  // first node in list
	}
	else{ // list has at least 1 number
		if(n<=head->num){ //insert in front
			new->next=head;
			return new;  // first node in list
		}
		else{
			pp=head;
			p=head->next;
			while(p!=NULL&&n>p->num){
				pp=p;
				p=p->next;
			}
			// insert after pp
			pp->next=new;
			new->next=p;
			return head; // head remained the same
		}
	}
}
void print_list(nodeptr head){
	while(head!=NULL){
		printf("%d ",head->num);
		head=head->next;
	}
	printf("\n");
}
	
int main(){
	int n;
	nodeptr head;
	
	head=NULL;
	if(scanf("%d", &n)!=1) n=0;
	while(n!=0){
		head=insertlist(head,n);
                if(scanf("%d", &n)!=1) n=0;
	}
	if(head==NULL)
		printf("\n No value was read \n");
	else{
		printf("\n The sorted list is");
		print_list(head);
	}
	return 0;
}	
