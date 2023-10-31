# include <stdio.h>
# include <stdlib.h>
struct node {
	int data;
	struct node *next ;
};
void print (node *head){
	struct node *p=head;
	while (p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}
struct node  *reversell(node *head){
	node *curr=head,*prev=NULL,*forward=NULL;
	while (curr!=NULL){
		forward = curr->next;
		curr->next=prev;
		prev= curr;
		curr = forward;
	}
	return prev;
}
int main () {
	int n;
	scanf("%d",&n);
	node *p,*head;
	for (int i =0;i<n;i++){
		if (i==0){
			head = (node*)malloc(sizeof(node));
			p = head;
		}
		else {
			p->next= (node*)malloc(sizeof(node));
			p=p->next;
		}
		scanf("%d",&p->data);
	}
	p->next=NULL;
	printf("THE LINKED LIST  IS : \n");
	print(head);
	printf("AFTER REVERSING THE LINKED LIST : \n");
	head=reversell(head);
	print(head);
}
