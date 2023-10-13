# include <stdio.h>
# include <stdlib.h>
// creating a structure for linked list 
struct node {
	int data ;
	struct node *next;
};
//  function for printing the linked list 
void ptr_lnk(struct node *ptr){
	int i =0;
	while (ptr!=NULL){
		printf (" the value of %dst link_list  data is  : %d  ",++i,ptr->data);
		printf ("\n");
		printf("the value in %dst node's next is : %d",i,ptr->next);
		printf ("\n");
		ptr = ptr->next;
		
	}
}
int main (){
	
	struct node *head ;
	struct node *second ;
	struct node *third ;
	struct node *forth ;
	// assining memory for the 
	head= (struct node*) malloc (sizeof(struct node));
	second= (struct node*) malloc (sizeof(struct node));
	third= (struct node*) malloc (sizeof(struct node));
	forth = (struct node*) malloc (sizeof(struct node));
	head->data=7;
	head->next=second;
	second->data=8;
	second->next=third;
	third->data=9;
	third->next=forth;
	forth->data=44;
	forth->next=NULL;
	ptr_lnk(head);
}

