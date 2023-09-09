#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
	int F,R;
	int size;
	int cap;
	int *ar;
}queue;

queue *create_que(int cap)					//O(1)
{
	queue *q=(queue*)malloc(sizeof(queue));
	if(!q) return NULL;
	q->cap=cap;
	q->F=q->R=-1;
	q->size=0;
	q->ar=(int*)malloc(q->cap*sizeof(int));
	if(!q->ar) return NULL;
	return q;
}

int que_size(queue *q)			//O(1)
{
	return q->size;
}

int front(queue *q)				//O(1)
{
	if(q->F==-1) {
		printf("queue is empty:");
		return INT_MIN;
	}
	return q->ar[q->F];
}

int rear(queue *q)					//O(1)
{
	if(q->R==-1){
		printf("queue is empty:");
		return INT_MIN;
	}
	return q->ar[q->R];
}

void enQueue(queue *q,int x)			//O(1)
{
	if(q->R==q->cap-1){
		printf("overflow");
		return;
	}
	if(q->F==-1 && q->R==-1){
		q->F++;
		q->R++;
		q->ar[q->R]=x;
	}
	else{
		q->R++;
		q->ar[q->R]=x;
	}	
	q->size++;
}

int deQueue(queue *q)				//O(1)
{
	if(q->F==-1){
		printf("underflow");
		exit(1);
	}
	else
	{
		int tmp=q->ar[q->F];
		if(q->F==q->R){
			q->F=-1;
			q->R=-1;
		}
		else q->F++;
		q->size--;
		return tmp;
	}
}

bool isEmpty(queue *q)			//O(1)
{
	return (q->size==0);
}

bool isFull(queue *q)			//O(1)
{
	return (q->size==q->cap);
}


int main()
{
	queue *q1=create_que(100);
	enQueue(q1,10);
	enQueue(q1,5);
	enQueue(q1,6);
	enQueue(q1,8);
	//enQueue();
	//printf("%s\n",isEmpty(q1)?"yes":"no");
	//printf("%s\n",isFull(q1)?"yes":"no");
	deQueue(q1);
	deQueue(q1);
	deQueue(q1);
	//deQueue(q1);
	printf("%d\n",front(q1));
	printf("%d\n",rear(q1));
	printf("%d\n",que_size(q1));
	
	return 0;
}
