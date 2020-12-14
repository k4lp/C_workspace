#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int size,front,rear,*q;

} node;

node *pu;

void initialize() {
	pu = (node*)malloc(sizeof(node));
	printf("\nEnter the size of the queue :- ");
	scanf(" %d",&pu->size);
	pu->q = (int *)malloc(sizeof(int)*pu->size);
	pu->front = pu->rear = -1;
}

int isfull() {
	return (pu->rear == pu->size-1);
}

int isempty() {
	if(pu->rear == pu->front) {
		if( pu->rear != -1)
			pu->rear = pu->front = -1;
		return 1;
	}
	else return 0;
}

int dequeue() {
	if(isempty()) {
		printf("\nQueue is empty.");
		return -1;
	}
	else
		return pu->q[++pu->front];
}

void display() {
	if(isempty())
		return;
	else {
		for(int i = pu->front + 1 ; i <= pu->rear ; i ++)
			printf("\n%d",pu->q[i]);
	}
}

void enqueue(int x) {
	if(isfull()) {
		printf("\nQueue is full.");
		return;
	}
	else {
		pu->q[++pu->rear]= x;
	}
}

int main() {
	initialize();
	enqueue(12);
	display();
	enqueue(127);
	display();
	dequeue();
	display();
	dequeue();
	dequeue();
	return 0;
}
