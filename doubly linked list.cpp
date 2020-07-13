#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
	struct node *prev;
	int ssn,phno;
	float sal;
	char name[20],dept[10],desg[20];
	struct node *next;
}*h,*temp,*temp1,*temp2;

void create()
{
	int ssn,phno;
	float sal;
	char name[20],dept[10],desg[20];
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\n enter ssn,name,department,designation,salary and phno. of employee\n");
	scanf("%d%s%s%s%f%d",&ssn,name,dept,desg,&sal,&phno);
	temp->ssn=ssn;
	strcpy(temp->name,name);
	strcpy(temp->dept,dept);
	strcpy(temp->desg,desg);
	temp->sal=sal;
	temp->phno=phno;
	count++;
}

void insertbeg()
{
	if(h==NULL)
	{
		create();
		h=temp;
		temp1=h;
	}
		else 
		{
			create();
			temp->next=h;
			h->prev=temp;
			h=temp;
			
		}
	}
	void insertend()
	{
		if(h==NULL)
		{
			create();
			h=temp;
			temp1=h;
			
		}
		else
		{
			create();
			temp1->next=temp;
			temp->prev=temp1;
			temp1=temp;
			
		}
	}
	void displaybeg()
	{
		temp2=h;
		if(temp1==NULL)
		{
			printf("list empty to display\n");
			return;
			
		}
		printf("\nlinked list elements from begining:-\n");
		while(temp2!=NULL)
		{
		printf("%d%s%s%s%f%d\n",temp2->ssn,temp2->name,temp2->dept,temp2->desg,temp2->sal,temp2->phno);
		temp2=temp2->next;
		
				}
				printf("no of employee=%d",count);
				
	}
	int deleteend()
	{
		struct node *temp;
		temp=h;
		if(temp->next==NULL)
		{
			free(temp);
			h=NULL;
			return 0;
			
		}
		else
		{
			temp2=temp1;
			temp1=temp1->prev;
			printf("%d%s%s%s%f%d\n",temp2->ssn,temp2->name,temp2->dept,temp2->desg,temp2->sal,temp2->phno);
			temp1->next=NULL;
			free(temp2);
			
		}
		count--;
		return 0;
	}
		int deletebeg()
		{
			struct node *temp;
			temp=h;
			if(temp->next=NULL)
			{
				free(temp);
				h=NULL;
				
			}
			else
			{
				h=h->next;
				printf("%d%s%s%s%f%d\n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
				free(temp);
				h->prev=NULL;
						}
						count--;
						return 0;
						
		}
		main()
{
	int ch,n,j,i;
	h=NULL;
	temp=temp1=NULL;
	printf("\n******DLL IMPLEMENTATION******\n");
	printf("\n 1.create a dll of n emp and insertion\n");
	printf("\n2 display from begining with count");
	printf("\n3 insert at end used to demonstrate Double");
	printf("\n4 delete at end used to demonstrate double");
	printf("\n5 insert at beg used to demonstrate");
	printf("\n6 delete at beg used to demonstrate double");
	printf("\n7 exit\n");
	while(1)
	{
		printf("enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the no. of employees:-\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				insertend();
				break;
				case 2:
					displaybeg();
					break;
					case 3:
						insertend();
						break;
						case 4: deleteend();
						break;
						case 5:
							insertbeg();
							break;
							case 6:
								deletebeg();
								break;
								case 7:
									exit(0);
									default: printf("wrong choice \n");
		}
	}
}

