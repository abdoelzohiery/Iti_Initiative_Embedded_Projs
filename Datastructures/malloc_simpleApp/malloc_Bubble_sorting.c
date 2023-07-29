#include <stdio.h>
#include <stdlib.h>
#include "../std_types.h"

void bbsorting(u16 *parr,u16 n);
void Display_arrElements(u16 *parr,u16 n);
void array_init(u16 *parr,u16 n);

int main(void)
{
	u16 option,i;
	u16 n = 0;
	printf("Enter The Number of bytes to allocate :");
	scanf("%hu",&n);
	
	u16 *ptr = (u16 *)malloc(sizeof()*n);
	
	printf("\nChoose option:\n1-manual init\t2-autoinit\n>>");
	scanf("%hu",&option);
	if(option == 1)
	{	
		for(i=0;i < n;i++)
		{
			printf("Enter Number %hu : ",i);
			fflush(stdout);
			scanf("%hhu",&(ptr[i]));
		}
	}
	else if(option == 2)
	{
		array_init(ptr,n);
	}
	else;
	bbsorting(ptr,n);
	Display_arrElements(ptr,n);
	free(ptr);
	
	return 0;
}


void bbsorting(u16 *parr,u16 n)
{
	u16 i,j,flag=1;
	for(i=0;(i<n)&& flag;i++)
	{
		flag = 0;
		for(j=0;j<n-1-i;j++)
		{
			if(*(parr+j) > *(parr+j+1))
			{
				u16 temp = *(parr+j) ;
				*(parr+j) = *(parr+j+1);
				*(parr+j+1)= temp;
				flag=1;
			}
		}
	}
	
}

void Display_arrElements(u16 *parr,u16 n)
{
	u16 i;
	for(i=0;i<n;i++)
	{
		printf("element %hhu: %hhu\n",i,*(parr+i));
	}
}

void array_init(u16 *parr,u16 n)
{
	
	int i;
	for (i=0;i<n;i++)
	{
		parr[i]=rand()%50;
	}
}