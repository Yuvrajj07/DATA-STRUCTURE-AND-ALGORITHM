#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
void print(struct node *head) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (p != NULL) {
        printf("The %d node of the linked list is %d\n", ++i, p->data);
        p = p->next;
    }
}
struct node *insert_at_beg(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;

    if (head != NULL) {
        head->prev = ptr;
    }
    return ptr;
}
//  INSERT AFTER A GIVEN DATA 
struct node *insert_after_node(struct node *head, int data, int key){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        // Key not found in the list
        free(ptr);
        return head;
    }
    struct node *forw = p->next;
    ptr->prev = p;
    ptr->next = forw;
    if (forw != NULL) {
        forw->prev = ptr;
    }
    p->next = ptr;
    return head; 
}
struct node *insert_at_end(struct node *head, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head;
	ptr->next=NULL;
	ptr->data=data;
    if (head == NULL) {
        // If the list is empty make the new node the head
        ptr->prev = NULL;
        return ptr;
    }
    while (p->next!=NULL){
    p=p->next;
	}
	p->next=ptr;
	ptr->prev=p;
    return head;
}
// detetion of nodes  
struct node *delete_at_beginning(struct node *head) {
    if (head == NULL) {
        // List is empty, nothing to delete
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    return head;
}

struct node *delete_at_end(struct node *head){
	if(head==NULL){
		return NULL;
	}
	struct node *p=head;
	while (p->next->next!=NULL){
		p=p->next;
	}
	p->next=NULL;
	return head;
}
int main() {
    int n;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    struct node *head=NULL,*prev=NULL,*p=NULL;
    for (int i=0;i<n;i++) {
        if (i==0) {
            head=(struct node*)malloc(sizeof(struct node));
            p = head;
        } else {
            p->next=(struct node*)malloc(sizeof(struct node));
            p->next->prev=p;  // Fix here
            p=p->next;
        }
        scanf("%d", &p->data);
        p->next = NULL;  // Set next to NULL for the last node
    }
    // Uncomment the following lines to print the linked list
    printf("Printing the linked list -->  \n");
    print(head);
   ///*
    printf("\n");
    printf("\n");
    printf("Inserting element at the beginning --> \n");			// inert at begening
    printf("\n");
	printf("ENTER  THE ELEMENT YOU WANT TO INSERT : ");			
    int key;
    scanf("%d",&key);											// key element input
    head=insert_at_beg(head, key);								// updating the head  pointer
    print(head);
													// printing the list
    // printf("%d",head->next->prev->data);
    printf("\n");	
    printf("inserting  at end  \n");									
    printf("\n");
    printf("enter element you wnt to insert  at end -->  ");
    int lst;
    scanf("%d",&lst);											// key element input
    head=insert_at_end(head,lst);								// updating head pointer 
    print (head);		
    printf("\n");
    printf("\n");
	printf("insert after a given data --> \n");
	int data,keyelement;
	printf("enter the key element : ");
	scanf("%d",&keyelement);
	printf("enter the data you want to enter : ");
	scanf("%d",&data);
	printf("\n");
	printf("printing the linked list after adding %d  in the list : --> \n ",data);
	head=insert_after_node(head,data,keyelement);
	printf("\n");
	print(head);
	printf("\n");
	printf("do you want to delete the node : \n");
	printf("deleting the first node of the list :\n");
	
	//*/
	printf("delete elements from beginning \n");
	head=delete_at_beginning(head);
	print(head);
	printf("delete elements from the end \n");
	head=delete_at_end(head);
	print(head);
	return 0;
}

