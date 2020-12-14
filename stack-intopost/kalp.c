#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

typedef struct _node {
	char data[SIZE];
	int top;
} node;

node *pu;

void initialize() {
	if(pu == NULL) {
		pu = (node *)malloc(sizeof(node));
		pu->top = -1;
	}
	else {
		free(pu);
		pu = (node *)malloc(sizeof(node));
		pu->top = -1;
	}
}

int isempty() {
	return (pu->top == -1);
}

int isfull() {
	return (pu->top == SIZE -1);
}

void push(char x) {
	if(isfull()) return ;
	else {
		pu->data[++pu->top] = x;
	}
}

char pop() {
	if(isempty())
		return 0;
	else {
		return pu->data[pu->top--];
	}
}

char peek() {
	return pu->data[pu->top];
}

int out(char x){
	if( x == '+' || x == '-')
		return 1;
	else if( x == '*' || x == '/')
		return 3;
	else if( x == '(')
		return 7;
	else if( x == ')')
		return 0;
	else
		return 9;
}

int in(char x) {
	if( x == '+' || x == '-')
		return 2;
	else if( x == '*' || x == '/')
		return 4;
	else if( x == '(')
		return 0;
	else
		return 9;
}

void adpost(char *post,const char *exp) {
	int i = 0 , j = 0;
	initialize();
	for( ; exp[i]!='\0';i++) {
		if(isalpha(exp[i]))
			post[j++] = exp[i];
		else if(isempty())
			push(exp[i]);
		else if(out(exp[i]) > in(peek()))
			push(exp[i]);
		else {
			while(!isempty() && ( out(exp[i]) != in(peek()) )) {
				post[j++] = pop();
			}
			if(exp[i] != ')')
				push(exp[i]);
			if(out(exp[i]) == in(peek()))
				pop();
		}
	}
	do {
		post[j++] = pop();
	} while(!isempty());
	post[j] = '\0';
}

int main() {
	char exp[] = "((a+b)/c)+d-(g-h)";
	char post1[100];
	adpost(post1,exp);
	printf("\n%s",post1);
}
