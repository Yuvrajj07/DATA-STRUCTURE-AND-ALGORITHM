#include <iostream>
# include <stdlib.h>
using namespace std;
typedef struct stack{
	int *arr;
	int size;
	int top;
}stack;
int size (stack *pt){
	return pt->top;
}
int peek (stack *st){
	if (st->top==-1){
		printf ("stack underflow");
	}
	return st->arr[st->top];
}
void push(stack *st,int x){
	if (st->top==st->size-1){
		printf ("stack overflow ");
	}
	st->top++;
	st->arr[st->top]=x;
}
int pop(stack *st){
	if (st->top==-1){
		printf ("stack underflow ");
	}
	int tmp= st->arr[st->top];
	st->top--;
	return tmp;
}
bool isEmpty(stack *st){
	if (st->top==-1){
		return true;
	}
	return false ;
}
stack *create_st(int cap){
stack *ptr = (stack*)malloc(sizeof(stack));
if (!ptr) return NULL;
ptr->top=-1;
ptr->size=cap;
ptr->arr=(int*)malloc(ptr->size*sizeof(int));
if (!ptr->arr) return NULL;
return ptr;
}	
	int main () {
	stack *st1= create_st(100);
	push(st1,5);
	printf ("%d",peek(st1));
	
	
}
