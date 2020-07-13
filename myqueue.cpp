#include<stdio.h>
#include<stdlib.h>
#define CQSIZE 5
int rear=-1,front=-1;
char item;
char cq[CQSIZE];
int cqinsert();
int cqdisplay();
int cqdelete();
main()
{
	int ch;
	while(1)
	{
		printf("******\n");
		printf("circular queue of character implementation\n");
		printf("*******\n");
		printf("\n1.CQ INSERT\n");
		printf("2.CQ DELETE\n");
		printf("3.CQ DISPLAY\n");
		printf("4. QUIT\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: cqinsert();
			break;
			case 2 : cqdelete();
			break;
			case 3:cqdisplay();
			break;
			case 4: exit(0);
			break;
			default : printf("wrong choice\n");
			
		}
	}
}
int cqinsert()
{
	if (rear==CQSIZE-1)
	{
		printf("\n circular queue overflow\n");
		return 0;
		
	}
	else
	{
		printf("enter the item to be inserted\n");
		fflush(stdin);
		item=getchar();
		if (front==-1)
		front=rear=0;
		else
		rear++;
		cq[rear]=item;
		
	}
	return 0;
	
}
int cqdelete()
{
	if (front==-1)
	printf("\n circular queue underflow\n");
	else
	{ printf("the item deleted is %c\n",cq[front]);
	if (front==rear)
	front=rear=-1;
	else
	front++;
}
return 0;

	}
	int cqdisplay()
	{
		int i;
		if(front==-1)
		printf("\ncircular queue is empty\n");
		else
		{
			printf("The circular queue is:-\n");
			for(i=front;i<=rear;i++)
			printf("%c\t",cq[i]);
			
		}
				printf("\n");
				return 0;
	}
