#ifndef List_H
#define Lish_H


typedef struct node {
	
	int ID;
	char name[50];
	int marks;
	struct node *next;
} list;

list *createNode(int marks, char *name, int ID);
list *makelist();
void display(list *head);
int count(list *head);
void search(list *head, int ID);
list *addatfirst(list *head, int marks, char *name, int ID);
list *addatend(list *head, int marks, char *name, int ID);
list *addatAfter(list *head, int marks, char *name, int ID, int IDs);
list *addatbefore(list *head, int marks, int ID, char *name, int IDs);
list *addatPos(list *head, int pos, int marks, int ID, char *name);
list *deletestud(list *head, int data);
list *reverse(list *head);

#endif
