#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
list *createNode(int marks, char *name, int ID)
{
	list *newNode = (list*)malloc(sizeof(list));
	
	newNode->ID = ID;
	strcpy(newNode->name, name);
	newNode->marks = marks;
	newNode->next = NULL;
	
	return newNode;
}

list *makelist()
{
	
	int ID, marks;
	char name[50];
	char choice;
	
	list *first = NULL, *temp = NULL;
	do
	{
		printf("Enter your ID number: ");
		scanf("%d", &ID);
		printf("Enter your marks: ");
		scanf("%d", &marks);
		printf("Enter your name: ");
		scanf(" %[^\n]", name);
		
		list *newNode = createNode(marks, name, ID);
		
		if(first == NULL)
		{
			first = newNode;
			temp = first;
		}
		else 
		{
			temp->next = newNode;
			temp = newNode;
		}
		
		printf("\nDo you want to add another student? (y/n): ");
		scanf("%c", &choice); fflush(stdin);
	}while(choice == 'y' || choice == 'Y');
	
	printf("The adding has been successfull!\n");
	
	return first;
}

void display(list *head)
{
	
	list *curr = head;
	
	if(curr == NULL)
	{
		printf("List is empty!\n");
		return;
	}
	
	printf("List is: \n");
	while(curr != NULL)
	{
		printf("The name: %s", curr->name);
		printf("The ID: %d", curr->ID);
		printf("The marks: %d", curr->marks);
		
		curr = curr->next;
	}
	printf("\n");
}

int count(list *head)
{
	list *curr = head;
	
	while(curr != NULL)
	{
		curr = curr->next;
		count++;
	}
	
	return count;
}

void search(list *head, int ID)
{
	
	list *curr = head;
	found = 1;
	while(curr != NULL)
	{
		if(curr->ID == ID)
		{
			printf("%d found! at position %d\n", ID, found);
			return;
		}
		curr = curr->next;
		found++;
	}
	printf("%d not found!\n");
}

list *addatfirst(list *head, int marks, char *name, int ID)
{
	list *temp;
	
	list *first = createNode(marks, name, ID);
	
	if(head == NULL)
	{
		head = first;
	}
	else 
	{
		temp = head;
		first->next = temp;
		head = first;
	 } 
	 
	 return head;
}

list *addatend(list *head, int marks, char *name, int ID)
{
	
	list *temp;
	
	list *end = createNode(marks, name, ID);
	
	if(head == NULL)
	{
		head = end;
		return head;
	}
	else 
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
			temp->next = end;
			end->next = NULL;
		}
		return head;
	}
}

list *addatAfter(list *head, int marks, char *name, int ID, int IDs)
{
	
	list *temp;
	
	list *newNode = createNode(marks, name, ID);
	
	if(head == NULL)
	{
		head = newNode;
		return head;
	}
	else 
	{
		temp = head;
		do
		{
			if(temp->ID == IDs)
			{
				newNode->next = temp->next;
				temp->next = newNode;
				return head;
			}
			else 
			{
				temp = temp->next;
			}
		}while(temp != NULL);
	}
}

list *addatbefore(list *head, int marks, int ID, char *name, int IDs)
{
	
	list *temp;
	list *prev = NULL;
	list *newNode = createNode(marks, name, ID);
	
	if(head == NULL)
	{
		printf("The list is empty!\n");
		return head;
	}
	
	if(head->ID == IDs)
	{
		
		newNode->next = head;
		head = newNode;
		return head;
	}
	
	temp = head;
	
	while(temp != NULL)
	{
		if(temp->ID == IDs)
		{
			newNode->next = temp;
			if(prev != NULL)
			{
				prev->next = newNode;
			}
			return head;
		}
		prev = temp;
		temp = temp->next;
	}
	
	printf("%d not present in the list!", IDs);
	
	return head;
}

list *addatPos(list *head, int pos, int marks, int ID, char *name);
{
	
	list *temp;
	
	list *newNode = createNode(marks, name, ID);
	
	if(head == NULL)
	{
		head = newNode;
		return head;
	}
	if(pos == 1)
	{
		newNode->next = head;
		head = newNode;
		return head;
	}
	
	temp = head;
	int i;
	
	for(i = 1; i < pos - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}
	
	if(temp == NULL)
	{
		printf("Invalid Position!\n");
		return temp;
	}
	else 
	{
		temp->next = newNode->next;
		newNode->next = temp
	}
	
	return head;
}

list *deletestud(list *head, int data)
{
	
	list *temp;
	
	list *st;
	
	if(head == NULL)
	{
		printf("it's empty!\n");
		return head;
	}
	
	if(head->ID == data)
	{
		temp = head;
		head = head->next;
		free(temp);
		return start;
	}
	
	st = head;	
	while(st->next != NULL)
	{
		if(st->next->ID == data)
		{
			temp = st->next;
			st->next = temp->next;
			free(temp);
			return head;
		}
		st = st->next;
	}
	printf("%d not found!\n");
	
	return head;
}

list *reverse(list *head)
{
	
	list *temp = head;
	list *prev = NULL;
	list *next = NULL;
	
	while(temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = next;
		next = temp;
	}
	
	return prev;
}

