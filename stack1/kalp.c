#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct _node {
	int data[SIZE];
	int top;
} node;

node *pu;

void initialize(void) {
	pu = (node *)malloc(sizeof(node));
	pu->top = -1;
}
int isempty(node *temp) {
	if(temp->top == -1)
		return 1;
	else
		return 0;
}

int isfull( node * temp) {
	if(temp->top == SIZE - 1)
		return 1;
	else
		return 0;
}

void push(node *temp) {
	if(isfull(temp)) {
		printf("\nStack Overflow.");
		return;
	}
	else  {
		int num = 0;
		printf("\nEnter the data :- ");
		scanf(" %d",&num);
		temp->data[++temp->top] = num;
	}
}

void pop(node *temp) {
	if(isempty(temp)) {
		printf("\nStack Underflow.");
		return;
	}
	else {
		printf("\n %d is removed." , temp->data[temp->top--] );
		return;
	}
}

void peek(node *temp) {
	if(isempty(temp)) {
		printf("\nStack Underflow.");
		return;
	}
	else {
		printf("\nData :- %d",temp->data[temp->top]);
		return;
	}
}

void display(node *temp) {
	if(isempty(temp)) {
		printf("\nStack Underflow.");
		return;
	}
	else {
		int i = 0;
		for(;i<=temp->top ; i ++) {
			printf("\n%d",temp->data[i]);
		}
		return;
	}
}

int main() {
	int choice = 0;
	initialize();
	do {
		printf("\n1. push\n2. pop\n3. peek\n4. display.\n5. exit");
		printf("\nEnter the choice :- ");
		scanf(" %d",&choice);
		switch(choice) {
		case 1:
			push(pu);
			break;
		case 2:
			pop(pu);
			break;
		case 3:
			peek(pu);
			break;
		case 4:
			display(pu);
			break;
		case 5:
			break;
		default :
			printf("\nEnter valid choice.");
			break;
		}
	}while(choice != 5);
	return 0;
}
