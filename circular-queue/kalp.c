#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int size,front,rear,*q;
} node;

//(rear+1)%size -> rear - 1
/*
0-7
rear = 6
(7%8) = 0 -> rear one step ahead
if front == 0
then rear is behind the front and rear pointer cannot move ahead because queue is full.
to check if full , front = (rear+1)%size == true
to check if empty, front = rear == true

*/

node *pu;

void initialize() {
	if(pu!=NULL)
		free(pu);
	pu = (node *)malloc(sizeof(node));
	printf("\nEnter the size of the queue :- ");
	scanf(" %d",&pu->size);
	pu->q = (int *)malloc(sizeof(int) * pu->size +1);
	pu->front = pu->rear = 0;
}

int isempty() {
	return (pu->front == pu->rear);
}

int isfull() {
	return ((pu->rear + 1) % pu->size == pu->front);
}

void enqueue(int x) {
	if(isfull())
		return;
	else {
		pu->q[pu->rear=(pu->rear +1) % pu->size] = x;
		//rear is first incremented by one step then value is added
		//front pointer doesn't contain any value
	}
}

int dequeue() {
	if(isempty())
		return '$';
	else {
		return pu->q[ pu->front = (pu->front + 1) % pu->size];
	}
}

void display() {
	if(isempty())
		return;
	else {
		for( int i = pu->front + 1; i != (pu->rear +1)%pu->size ; i = ( i +1) % pu->size)
			printf("\n %d",pu->q[i]);
	}
}

int main() {
	initialize();
	enqueue(4);
	display();
	enqueue(5);
	display();
	dequeue();
	display();
	return 0;
}
