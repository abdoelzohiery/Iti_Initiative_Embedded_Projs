/*Queue array based*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE]={0};
int front = -1;
int rear = -1;

void enqueue(int data);
int  dequeue(void);/*return the oldest element after removing it*/
int  peek(void);/*return the oldest element*/
int  is_empty(void);
int  is_full(void);
void printQueue(void);

int main(void)
{
	int choice=-1,data;
	while(choice != 0)
	{
		printf("\n1-Enqueue node\n2-printlist\n3-DeQueue node\n4-Display front ELement\n>>");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("\nEnter data: ");
				scanf("%d",&data);
				enqueue(data);
				break;
			}
			case 2:
			{
				printQueue();
				break;
			}
			case 3:
			{
				data = dequeue();
				printf("\nFirst entry element Removed : %d\n",data);
				break;
			}
			case 4:
			{
				data = peek();
				printf("\nFirst entry element displayed : %d\n",data);
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

void enqueue(int data)
{
	if(1 == is_full())
		{
			printf("\nOverflow.\n");
		}
	else
		{
			if(1 == is_empty())
			{
				front = 0;
				rear = 0;
			}
			else;
			queue[rear++] = data;
		}
}

int  dequeue(void)/*return the oldest element after removing it*/
{
	int temp = 0;
	if(1 == is_empty())
	{
		printf("\nUndrflow condition\n");
	}
	else
	{
		
		temp = queue[front];
		queue[front]=0;
		if(front <= (SIZE-1))
			front++;
		else
		{
			front = -1;
		}
	}
	return temp;
}

int  peek(void)/*return the oldest element*/
{
	if(0 == is_empty())
	{
		return queue[front];
	}
	else
	{
		printf("\nUndrflow\n");
		return 0;
	}
}

int  is_empty(void)
{
	if( (rear == -1) && (front == -1) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int  is_full(void)
{
	if((SIZE - 1) == rear )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printQueue(void)
{
	int i=0;
	if(is_empty()== 1)
	{
		printf("\nQueue is empty.\n");
	}
	else 
	{
		printf("\n");
		for (i =front;i<rear;i++)
		{
			printf("Element[%d] = %d\n",i,queue[i]);
		}
		printf("\n");
	}
}