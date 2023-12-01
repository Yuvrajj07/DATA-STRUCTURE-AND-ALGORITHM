#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void print(struct node *head) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head,p2,p2;
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
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *insert_after_node(struct node *head, int data, int key) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        // Handle memory allocation failure
        return head; // Or NULL, depending on your error handling logic
    }
    ptr->data = data;
    struct node *p = head;
    while (p != NULL && p->data != key) {
        p = p->next;
    }
    if (p == NULL) {
        // Key not found in the list, handle this scenario accordingly
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
    return head; // Return the updated head of the list
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

    // Update head to the next node (if it exists)
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp); // Free memory occupied by the deleted node
    return head; // Return the updated head of the list
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
