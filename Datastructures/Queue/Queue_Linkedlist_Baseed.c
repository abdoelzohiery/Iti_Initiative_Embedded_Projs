/*Queue*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queuenode QueueNode;
typedef struct queue Queue;

struct queue
	{
		QueueNode *front ;
		QueueNode *rear ;
		int Size ; 
	};

struct queuenode
	{
		int data;
		QueueNode *next;
	};

void Queue_init(Queue *pq);
void enqueue(Queue *pq,int in_data);
int  dequeue(Queue *pq);/*return the oldest element after removing it*/
int  peek(Queue *pq);/*return the oldest element*/
int  is_empty(Queue *pq);
int  is_full(Queue *pq);
void printQueue(Queue *pq);

int main(void)
{
	Queue q;
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
				enqueue(&q,data);
				break;
			}
			case 2:
			{
				printQueue(&q);
				break;
			}
			case 3:
			{
				data = dequeue(&q);
				printf("\nFirst entry element Removed : %d\n",data);
				break;
			}
			case 4:
			{
				data = peek(&q);
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


int  peek(Queue *pq)
{
	return ((pq->rear)->data);
}



void Queue_init(Queue *pq)
{
	pq -> front = NULL;
	pq -> rear = NULL;
	pq -> Size =0;
}

void enqueue(Queue *pq,int in_data)
{
	QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
	pn -> data = in_data;
	pn -> next = NULL;
	if(is_empty(pq))
	{
		pq -> front = 	pn ;
		pq -> rear  =   pn ;
		pq -> Size  =	1;
	}
	else
	{
		pn -> next  = pq -> front;
		pq -> front = pn;
		pq -> Size += 1;
	}
}

int  dequeue(Queue *pq)
{
	int temp = -1;
	if((is_empty(pq)) == 0)
	{
		
		if (((pq -> front)-> next) == NULL)/* handle one element only*/
		{
			temp = (pq->front)->data;
			free(pq->front);
			pq->front = NULL;
			pq->rear  = NULL;
			pq->Size = 0;
			
		}
		else /*at least two elements*/
		{
			QueueNode *pn = pq->front;
			while(((pn -> next)-> next) != NULL) /*if False then pn handle the before last node*/
			{
				pn = pn -> next;
			}
			temp = (pq -> rear)-> data;
			free(pq->rear);
			pn -> next  = NULL;
			pq -> rear  = pn;
			pq -> Size += 1;
		}
	}
	else
	{
		printf("\nQueue is empty.\n");	
	}
	return temp;
}

int  is_empty(Queue *pq)
{
	if((NULL == (pq -> front)) && (NULL == (pq -> rear)))
		return 1;
	else
		return 0;
}
int  is_full(Queue *pq)
{
	return 0;
}

void printQueue(Queue *pq)
{
	QueueNode *pn = pq->front;
	int cnt = 0;
	if(is_empty(pq) == 0)
	
	{
		printf("\n");
		while(pn != NULL)
		{
			printf("element[%d] = %d\n",cnt++,pn->data);
			pn = pn -> next;
		}
	}
	else
	{
		printf("\nQueue is empty.\n");
	}
}