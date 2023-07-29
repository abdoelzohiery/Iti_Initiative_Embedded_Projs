#include <stdio.h>
#include <stdlib.h>
#include "../std_types.h"




typedef struct node_t node;
struct node_t
{
	int data;
	node *tail;
};

int size =0; 

void Delete_specific_Node(node **head,int in_data);
void Add_specific_Node(node **head,int in_data,int pos);
void AddNode(node **head,int data);
void DeleteNode(node **head);
int is_empty(node **head);
void PrintList(node **head);


int main(void)
{
	node *head = NULL;
	int option =0;
	int data,pos;
	while(1)
	{
	printf("\nChoose Option\n1-add node\t2-delete node\n3-add in specific pos\t4-delete node in specific pos\n5-print the list\t6-Return Size\n7-End the program\n>>");
	scanf("%d",&option);
	if(1 == option)
	  {
		printf("Data : ");
		scanf("%d",&data);
	  	AddNode(&head,data);
	  }
	else if(2 == option)
	{
		DeleteNode(&head);
	}
	else if(3 == option)
	{
	    printf("\nData :  || to be inserted in pos: ");
		scanf("%d %d",&data,&pos);
		Add_specific_Node(&head,data,pos);
	}
	else if(4 == option)
	{
		printf("\nData to be deleted: ");
		scanf("%d",&data);
		Delete_specific_Node(&head,data);
	}
	else if(5 == option)
	{
		PrintList(&head);
	}
	else if(6 == option)
	{
		printf("\nSize of List = %d\n",size);
	}
	else{
		printf("\nThank u.");
		break;
	}
	}
	return 0;
}

void AddNode(node **ptr_head,int in_data)
{
	/*
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
	*/
	
	node *ptr = (node *)malloc(sizeof(node));
	ptr->data = in_data;
	ptr->tail = NULL;
	if(*ptr_head == NULL )
	{
		size = 1;
		*ptr_head = ptr;
	}
	else
	{
		node *p2 = *ptr_head; 
		while(((p2)->tail) != NULL)
		{
			p2 = p2->tail;
		}
		p2->tail  = ptr;
		size += 1; 
	}
	printf("\nNode is added.\n");
}

void DeleteNode(node **ptr_head)
{
	if((*ptr_head) == NULL)
	{
		printf("\nList is empty.\n");
	}
	else if((*ptr_head)->tail == NULL) /*for one element*/
	{
		free(*ptr_head);
		*ptr_head = NULL;
		printf("\nLast Node is deleted.\n");
		size = 0; 
	}
	else
	{
		node * ptr  = *ptr_head; /* ptr = head = &(first element of list)*/
		node * prev = *ptr_head;
		/* handle last element and before last element*/
		while((ptr->tail) != NULL)
		{
			prev = ptr;
			ptr = ptr -> tail;
		}
		prev->tail = NULL;
		free (ptr);
		prev = NULL;
		ptr  = NULL;
		size -= 1; 
		printf("\nLast Node is deleted.\n");
	}
	
	// node *p2 = head; 
		
		
		// /* now p2 handle last element */
		// /* at least */
		// else if(p2 -> tail != NULL)
		// {
			// while((p2->tail)->tail != NULL)
			// {
				// p2 = p2->tail;
			// }
			// free( p2 -> tail );
			// p2 -> tail = NULL;
			// size -= 1;
		// }
		// else
		// {
			// head = NULL;
			// size = 0;
		// }
		// return head;
}


void Delete_specific_Node(node **head,int in_data)
{
	node *prev = *head,*ptr = *head; 
	if((*head) != NULL)
		{
			if( ((ptr -> tail) == NULL) && ((ptr -> data) == in_data))
			{
				free(ptr);
				*head = NULL;
				size = 0;
			}
			else if (((*head) -> data) == in_data)
			{
				*head = (*head) -> tail;
				free(ptr);
				ptr = NULL;
				prev = NULL;
				size -= 1;
			}
			else
			{
				while((ptr->data) != in_data)
					{
						prev = ptr;
						ptr = (ptr -> tail);
					}
					prev -> tail = (ptr -> tail);
					free(ptr);
					ptr  =NULL;
					prev =NULL;
					size -= 1;
			}
		}
	else
		{
			printf("\nArray is empty.\n");
		}
	/*
	node *p2 = head; 
		
		/* now p2 handle last element */
		
		/*if(p2 != NULL)
		{
			while(( (p2->tail)-> tail) != NULL)
			{
				p2 = p2->tail;
			}
			free(p2->tail);
			p2 -> tail = NULL;
		}
		else
		{
			head = NULL;
		}
		return head;*/
}


int is_empty(node **head)
{
	if(*head == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void PrintList(node **head)
{	
	node *ptr = *head;
	int cnt = 0;
	if(ptr != 0)
	{
		printf("List Elements: \n");
		while(ptr != 0)
		{
			printf("element [%d] : %d \n",cnt,ptr->data);
			ptr = ptr->tail;
			cnt++;
		}
		printf("\n");
	}
	else
	{
		printf("list is empty.\n");
	}
}

void  Add_specific_Node(node **head,int in_data,int pos)
{
	int cnt=0;
	if(pos > (size+1))
		{
			printf("\nWrong Position.\nOut of order.\n");
		}
	else if( pos == (size+1))
		{
			AddNode(head,in_data);
		}
	else
		{
			node *ptr = (node *)malloc(sizeof(node));
			ptr->data = in_data;
			ptr->tail = NULL;
			
			node *pnode1 = *head;
			node *pnode2 = (*head)->tail;
			if((pos == 0) || (pos == 1))
				{
					ptr -> tail = *head;
					*head = ptr;
				}
			else
				{
				for (cnt = 2; cnt < pos ;cnt++)
					{
						pnode1 = pnode1 -> tail;
						pnode2 = pnode2 -> tail;
					}
					ptr -> tail = pnode2;
					pnode1 -> tail = ptr;
				}
				size +=1;
		}
}

// int size (node *head)
// {
	// int cnt = 0;
	// node *ptr = head;
	
	// while(ptr != NULL)
		// {
			// ptr = ptr->tail;
			// cnt++;
		// }
		// return cnt;
// }