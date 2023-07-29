#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node;
struct node_t
{
	int data;
	node *tail;
};



void addNode(node **head,int data);
void printList(node **head);
void deleteNode(node ** head);

int main(void)
{
	node* head = NULL;
	int choice = -1, data;
	
	while(choice != 0)
	{
		printf("1-add node\n2-printlist\n3-Delete last node\n>>");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter data: ");
				scanf("%d",&data);
				addNode(&head,data);
				break;
			}
			case 2:
			{
				printList(&head);
				break;
			}
			case 3:
			{
				deleteNode(&head);
				break;
			}
			default: 
			{
				break;
			}
		}
	}
	return 0;
}


void addNode(node** head,int in_data){

	node *ptr = (node *)malloc(sizeof(node));
	ptr->data = in_data;
	ptr->tail = NULL;
	if(*head == NULL )
	{
		*head = ptr;
	}
	else
	{
		node *p2 = *head; 
		while((p2->tail) != NULL)
		{
			p2 = p2->tail;
		}
		p2 -> tail  = ptr;
	}
	printf("\nNode is added.\n");
}

void printList(node** head)
{	
	node *ptr = *head;
	int cnt = 0;
	if(ptr != 0)
	{
		printf("\n");
		while(ptr != 0)
		{
			printf("element%d : %d\n",cnt,ptr->data);
			ptr = ptr->tail;
			cnt++;
		}
		printf("\n");
	}
	else
	{
		printf("\nlist is empty.\n");
	}
}
void deleteNode(node** head)
{
	if(*head == NULL)
	{
		printf("\nList is empty.\n");
	}
	else if((*head) -> tail == NULL)
	{
		free(*head);
		head = NULL;
	}
	else
	{
		node * ptr  = *head;
		node * prev = *head;
		while(ptr->tail != NULL)
		{
			prev = ptr;
			ptr = ptr -> tail;/* handle last element */
		}
		prev->tail = NULL;
		free (ptr);
		prev = NULL;
		ptr  = NULL;
		
	}
	printf("\nLast Node is deleted.\n");
}