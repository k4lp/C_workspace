#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct _node {
	int data[SIZE];
	int top;
} node;

node *pu;

void initialize() {
	pu = (node *) malloc(sizeof(node));
	pu->top = -1;
}

int isempty() {
	return (pu->top == -1);
}

int isfull() {
	return (pu->top == SIZE -1);
}

int pop() {
	if(isempty())
		return '$';
	else
		return (pu->data[pu->top--]);
}

void push(int x) {
	if(isfull())
		return ;
	else {
		pu->data[++pu->top] = x;
	}

}

int peek() {
	if(isempty())
		return '$';
	else {
		return (pu->data[pu->top]);
	}
}

int isoperands(char x) {
	if(x == '+' || x == '-' || x == '*' || x == '/')
		return 1;
	else
		return 0;
}

int eval(const char *exp) {
	int i = 0, x2,x1,result;
	initialize();
	for( ; exp[i]!='\0'; i++) {
		if(!isoperands(exp[i]))
			push(exp[i] - '0');
		else {
			x2=pop(); x1 = pop();
			switch(exp[i]) {
			case '+' : result = x1 + x2; break;
			case '-' : result = x1-x2; break;
			case '*' : result = x1*x2; break;
			case '/' : result = x1/x2; break;
			}
			push(result);
		}
	}
	return peek();
}

int main() {
	char *exp = "234/-233*/+3-";
	printf("\n %s = %d",exp,eval(exp));
	return 0;
}
