#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int size,front,rear,*q;
} node;

node *pu;

void initialize() {
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
		pu->rear = (pu->rear +1) % pu->size;
		pu->q[pu->rear] = x;
	}
}
