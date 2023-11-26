#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void print(struct node *head) {
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

int main() {
    int n;
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);

    struct node *head = NULL, *prev = NULL, *p = NULL;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            head = (struct node *)malloc(sizeof(struct node));
            p = head;
        } else {
            p->next = (struct node *)malloc(sizeof(struct node));
            p->next->prev = p;  // Fix here
            p = p->next;
        }
        scanf("%d", &p->data);
        p->next = NULL;  // Set next to NULL for the last node
    }
    // Uncomment the following lines to print the linked list
     printf("Printing the linked list: \n");
     print(head);
    printf("Inserting element at the beginning \n");
    head=insert_at_beg(head, 9);
    print(head);
   // printf("%d",head->next->prev->data);
   printf("insert at end  \n");
    head=insert_at_end(head,10);
    print (head);
	return 0;
}

