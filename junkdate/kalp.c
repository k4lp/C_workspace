/*
 * main.c
 *
 *  Created on: 21-Nov-2020
 *      Author: kalp & dhruv
 *      roll no :- 83 & 76
 *      sub :- DS
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<file.h>

typedef struct _node {
	int id;
	char name[50];
	int jday,jmonth,jyear;
	int plan;//in months
	struct _node *next;
	struct _node *prev;
} node;

int validate(int,int,int);

node *head , *tail;

int ifexist(int num){
	node *ptr = head;
	while( ptr!= 0) {
		if(num == ptr->id) {
			printf("\nID already exist. IDs must be distinct.");
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void create() {
	if(head == NULL) {
		node *temp = (node *)malloc(sizeof(node));
		again1 :
		printf("\nEnter the Customer ID :- ");
		scanf(" %d", &temp->id);
		printf("\nEnter the Name :- ");
		scanf(" %[^\n]",temp->name);
		printf("\nEnter the joining date in DD/MM/YYYY format :- ");
		scanf(" %d/%d/%d",&temp->jday,&temp->jmonth,&temp->jyear);
		if(validate(temp->jday,temp->jmonth,temp->jyear))
		{
			printf("\nInvalid date entry. Try again.");
			goto again1;
		}
		printf("\nEnter the validity in months :- ");
		scanf(" %d",&temp->plan);
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
	}
	else {
		node *temp = (node *)malloc(sizeof(node));
		again :
		printf("\nEnter the Customer ID :- ");
		scanf(" %d", &temp->id);
		if(ifexist(temp->id)) {
			goto again;
		}
		printf("\nEnter the Name :- ");
		scanf(" %[^\n]",temp->name);
		printf("\nEnter the joining date in DD/MM/YYYY format :- ");
		scanf(" %d/%d/%d",&temp->jday,&temp->jmonth,&temp->jyear);
		if(validate(temp->jday,temp->jmonth,temp->jyear))
		{
			printf("\nInvalid date entry. Try again.");
			goto again;
		}
		printf("\nEnter the validity in months :- ");
		scanf(" %d",&temp->plan);
		node *ptr = head;
		while(ptr->next != 0)
		{
			ptr=ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
		temp->next = NULL;
		tail = temp;
	}
}

void display() {
	if(head == NULL) {
		printf("\nList is empty. Create one first.");
		return;
	}
	else {
		printf("\n\n#######################################################################\n\n");
		node *ptr = head;
		while(ptr !=NULL) {
			printf("\nID = %d\nName = %s\nJoining date = %d/%d/%d\nPlan validity = %d month(s)\n",ptr->id,ptr->name,ptr->jday,ptr->jmonth,ptr->jyear,ptr->plan);
			ptr=ptr->next;
		}
	}
	printf("\n\n#######################################################################\n\n");
}

void dumpfile() {
	if(head == 0) {
		printf("\nList is empty.");
		return;
	}
	else {
		FILE *fp = fopen("dump.txt","w");
		if(fp == NULL) {
			printf("\nFile couldn't be opened.");
			return;
		}
		else {
			node *ptr = head;
			fprintf(fp,"\n\n#######################################################################\n\n");
			while(ptr!= 0) {
				fprintf(fp , "\nID = %d\nName = %s\nJoining date :- %d/%d/%d\nValidity = %d\n\n" , ptr->id,ptr->name,ptr->jday,ptr->jmonth,ptr->jyear,ptr->plan);
				ptr = ptr->next;
			}
			fclose(fp);
		}
	}
}

void delete() {
	node * ptr = head;
	printf("\nEnter the number to be deleted :- ");
	int num = 0 , flag = 0 ;
	scanf(" %d",  &num);
	// to check if the first element matches to reduce the time complexity
	if(ptr->id == num) {
		node *ptr1 = ptr->next;
		free(ptr);
		ptr1->prev = NULL;
		head = ptr1;
		return ;
	}
	//traversing the linkedlist to the block where our number is located
	while(ptr->next != 0) {
		if(ptr->id == num) {
			flag = 1;
			//number is found
			break;
		}
		ptr=ptr->next;
	}
	//for the last linkedlist that can't be done inside while-loop
	if(ptr->next == 0 && num == ptr->id) {
		node *ptr1 = ptr->prev;
		free(ptr);
		ptr1->next = NULL;
		return ;
	}
	if(flag == 0) {
		// number doesn't exist inside linkedlist
		printf("\nNumber doesn't exist.");
		return ;
	}
	node *prevptr = ptr->prev;
	node *nextptr = ptr->next;
	free(ptr);
	prevptr->next = nextptr;
	nextptr->prev = prevptr;
}

void sortlist() {
	if(head == NULL) {
		printf("\nList is empty.");
		return ;
	}
	node *ptr1 , *ptr2;
	for(ptr1 = head ; ptr1!=0;ptr1 = ptr1->next) {
		for(ptr2 = ptr1->next ; ptr2!= 0 ; ptr2 = ptr2->next) {
			if(ptr1->id >  ptr2->id) {
				ptr1->id = ptr1->id + ptr2->id;
				ptr2->id = ptr1->id - ptr2->id;
				ptr1->id = ptr1->id - ptr2->id;

				char temp[50];

				strcpy(temp , ptr1->name);
				strcpy(ptr1->name , ptr2->name);
				strcpy(ptr2->name , temp);

				ptr1->jday = ptr1->jday + ptr2->jday;
				ptr2->jday = ptr1->jday - ptr2->jday;
				ptr1->jday = ptr1->jday - ptr2->jday;

				ptr1->jmonth = ptr1->jmonth + ptr2->jmonth;
				ptr2->jmonth = ptr1->jmonth - ptr2->jmonth;
				ptr1->jmonth = ptr1->jmonth - ptr2->jmonth;

				ptr1->jyear = ptr1->jyear + ptr2->jyear;
				ptr2->jyear = ptr1->jyear - ptr2->jyear;
				ptr1->jyear = ptr1->jyear - ptr2->jyear;

				ptr1->plan = ptr1->plan + ptr2->plan;
				ptr2->plan = ptr1->plan - ptr2->plan;
				ptr1->plan = ptr1->plan - ptr2->plan;
			}
		}
	}
}

void search(){
	printf("\nEnter the ID number :- ");
	int num = 0;
	scanf(" %d", &num);
	node *ptr = head;
	while(ptr!= 0) {
		if(num == ptr->id) {
			printf("\nID = %d\nName = %s\nJoining date = %d/%d/%d\nPlan validity = %d month(s)\n",ptr->id,ptr->name,ptr->jday,ptr->jmonth,ptr->jyear,ptr->plan);
			return ;
		}
		ptr=ptr->next;
	}
	printf("\nEntered ID not found.");
	return;
}

int validate(int day , int month , int year) {
	if(year < 1000 || year > 9999) {
		return 1;
	}
	if(month < 1 || month > 12) {
		return 1;
	}
	if(month == 1 || month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 || month == 12 ) {
		if(day < 1 || day > 31)
			return 1;
		else
			return 0;
	}
	else if ( month == 4 || month == 6 || month == 9 ||month == 11) {
		if( day < 1 || day > 30)
			return 1;
		else {
			return 0;
		}
	}
	else if(month == 2) { //leap year check
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
		{
			if(day < 1 || day > 29) {
				return 1;
			}
			else
				return 0;
		}
		else {
			if(day < 1 || day > 28)
			{
				return 1;
			}
			else return 0;
		}
	}
	else return 0;
}

void update() {
	printf("\nEnter the ID number to be updated :- ");
	int num = 0;
	scanf(" %d",&num);
	node *ptr = head;
	while(ptr!=0) {
		if(num == ptr->id) {
			printf("\nEnter the Name :- ");
			scanf(" %[^\n]",ptr->name);
			printf("\nEnter the joining date in DD/MM/YYYY format :- ");
			scanf(" %d/%d/%d",&ptr->jday,&ptr->jmonth,&ptr->jyear);
			printf("\nEnter plan validity in months :- ");
			scanf(" %d" , &ptr->plan);
			return;
		}
		ptr=ptr->next;
	}
	printf("\nID not found.");
	return ;
}

int main() {
	int choice = 0;
	do {
		printf("\n1. Insert New Members..");
		printf("\n2. Delete Existing Members.");
		printf("\n3. Update Existing Members.");
		printf("\n4. Search Existing Members.");
		printf("\n5. Sort Members based on their ID.");
		printf("\n6. Display Members List.");
		printf("\n7. Exit.");
		printf("\n8. Dump data into file.");
		printf("\n\nEnter the choice :- ");
		scanf(" %d",&choice);
		switch(choice) {
		case 1:
			create();
			break;
		case 2:
			delete();
			break;
		case 3:
			update();
			break;
		case 4:
			search();
			break;
		case 5:
			sortlist();
			break;
		case 6:
			display();
			break;
		case 7:
			break;
		case 8:
			dumpfile();
			break;
		default :
			printf("\nEnter valid option.");
			break;
		}
	}while(choice != 7);
	return 0;
}
