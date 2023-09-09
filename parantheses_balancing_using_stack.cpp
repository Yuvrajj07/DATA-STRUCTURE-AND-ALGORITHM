#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	char *ar;
	int top;
	int size;
}stack;

void push(stack *st,char ch)
{
	if(st->top==st->size-1){
		//printf("overflow");
		return ;
	}
	st->ar[++st->top]=ch;
}

char pop(stack *st)
{
	if(st->top==-1){
		//printf("underflow");
		return '\0';
	}
	return st->ar[st->top--];	
}

bool isEmpty(stack *st)
{
	if(st->top==-1) return true;
	return false;
}

bool isFull(stack *st)
{
	if(st->top==st->size-1) return true;
	return false;
}

char peek(stack *st)
{
	if(st->top==-1){
		//printf("empty stack");
		return '\0';
	}
	return st->ar[st->top];
}

int size_stk(stack *st)
{
	return st->top+1;
}

stack *create(int cap)
{
	stack *st=(stack*)malloc(sizeof(stack));
	if(!st) return NULL;
	st->top=-1;
	st->size=cap;
	st->ar=(char*)malloc(st->size*sizeof(char));
	if(!st->ar) return NULL;
	return st;
}

bool balance_chk(stack *st, char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			push(st,str[i]);
		else
		{
			if(!isEmpty(st))
			{
				char ch=peek(st);
				if((str[i]=='}' && ch=='{') ||
				(str[i]==')' && ch=='(') ||
				(str[i]==']' && ch=='['))
				{
					pop(st);
				}
				else return false;
			}
			else return false;
		}
	}//for
	if(isEmpty(st)) return true;
	else return false;
}

int main()
{
	stack *st=create(100);
	
	char str[100];
	scanf("%[^\n]",str);
	
	if(balance_chk(st,str)) printf("yes");
	else printf("no");
	
//	push(st,'s');
//	push(st,'h');
//	push(st,'r');
//	printf("%d\n",size_stk(st));
//	printf("%c\n",peek(st));
//	printf("\n%s",isFull(st)?"yes":"no");
//	printf("%c",pop(st));
//	printf("%c",pop(st));
//	printf("%c",pop(st));
//	
//	printf("%c",pop(st));
//	
//	printf("\n%s",isEmpty(st)?"yes":"no");
	
	
	return 0;
}
