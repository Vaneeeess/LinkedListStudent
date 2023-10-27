#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int choice;
	int data;
	int item;
	int pos;
	
	list *head = NULL;
	
	do
	{
		printf("\n1 - Create List\n");
		printf("\n2 - Display\n");
		printf("\n3 - Count\n");
		printf("\n4 - Search\n");
		printf("\n5 - Add to empty list or Add at beginning\n");
		printf("\n6 - Add at End\n");
		printf("\n7 - Add after list\n");
		printf("\n8 - Add before list\n");
		printf("\n9 - Add at Pos\n");
		printf("\n10 - Delete\n");
		printf("\n11 - Reverse\n");
		printf("\n12 - Exit the program\n");
		
		
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: {
				head = makelist();
				break;
			}
			case 2: {
				display(head);
				break;
			}
			case 3: {
				count(head);
				break;
			}
			case 4: {
				printf("Enter the element to be searched: ");
				scanf("%d", &data);
				search(head, data);
				break;
			}
			case 5: {
				char name[50];
				int marks;
				int id;
				printf("Enter your name: ");
				scanf(" %[^\n]", name);
				printf("Enter your marks: ");
				scanf("%d", &marks);
				printf("Enter your ID: ");
				scanf("%d", &ID);
				head = addatfirst(head, marks, name, id);
				break;
			}
			case 6: {
				char name[50];
				int marks;
				int id;
				printf("Enter your name: ");
				scanf(" %[^\n]", name);
				printf("Enter your marks: ");
				scanf("%d", &marks);
				printf("Enter your ID: ");
				scanf("%d", &ID);
				head = addatend(head, marks, name, id);
				break;
			}
			case 7: {
			    char name[50];
				int marks;
				int id;
				printf("Enter your name: ");
				scanf(" %[^\n]", name);
				printf("Enter your marks: ");
				scanf("%d", &marks);
				printf("Enter your ID: ");
				scanf("%d", &ID);
				printf("At what position? must exist in the list: ");
				scanf("%d", &pos);
				head = addatAfter(head, marks, name, id, pos);
				break;
			}
			case 8: {
				char name[50];
				int marks;
				int id;
				printf("Enter your name: ");
				scanf(" %[^\n]", name);
				printf("Enter your marks: ");
				scanf("%d", &marks);
				printf("Enter your ID: ");
				scanf("%d", &ID);
				printf("At what position? must exist in the list: ");
				scanf("%d", &pos);
				head = addatbefore(head, marks, id, name, pos);
				break;
			}
			case 9: {
				char name[50];
				int marks;
				int id;
				printf("Enter your name: ");
				scanf(" %[^\n]", name);
				printf("Enter your marks: ");
				scanf("%d", &marks);
				printf("Enter your ID: ");
				scanf("%d", &ID);
				printf("Enter position you want to insert: ");
				scanf("%d", &pos);
				head = addatPos(head, pos, marks, id, name);
				break;
			}
			case 10: {
				printf("Enter the data you want to delte: ");
				scanf("%d", &data);
				head = deletestud(head, data);
				break;
			}
			case 11: {
				head = reverse(head);
				break;
			}
			case 12: {
				printf("Exiting the Program....\n");
				break;
			}
			default :
				printf("Invalid Input!\n");
		}
	}while(choice != 12);
	return 0;
}
