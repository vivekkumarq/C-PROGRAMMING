#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;
struct node
{
	int sem,phno;
	char name[20],usn[20],branch[20];
	struct node*next;
}
*first=NULL,*last=NULL,*temp=NULL,*temp1=NULL;
void create()
{
	int sem,phno;
	char name[20],usn[20],branch[20];
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n enter usn,name,branch,sem,ph no of student");
	scanf("%s%s%s%d%d",usn,name,branch,&sem,&phno);
	strcpy(temp->usn,usn);
	strcpy(temp->name,name);
	strcpy(temp->branch,branch);
	temp->sem=sem;
	temp->phno=phno;
	temp->next=NULL;
	count++;
}
void insert_atfirst()
{
	if (first==NULL)
	 {
	 	create();
	 	first=temp;
	 	last=first;
	 }
	 else
	 {
	 	create();
	 	temp->next=first;
	 	first=temp;
	 	
	 }
}
void insert_atlast()
{
	if(first==NULL)
	{
		create();
		first=temp;
		last=first;
		
	}
	else
	{
		create();
		last->next=temp;
		last=temp;
		
	}
}
void display()
{
	temp1=first;
	if(temp==NULL)
	{
		printf("list empty to display\n");
		return;
		
	}
	printf("\n linked list elements from begining:\n");
	while(temp!=NULL)
	{
		printf("\t%s\t%s\t%s\t%d\t%d\n",temp1->usn,temp1->name,temp1->branch,temp1->sem,temp1->phno);
		temp1=temp1->next;
	}
	printf("no. of students =%d",count);
	
}
int deleteend()
{
	struct node *temp;
	temp=first;
	if(temp->next=NULL)
	{
		free(temp);
		first=NULL;
		
	}
	else
	{
		while(temp->next!=last)
		temp=temp->next;
		printf("the deleted element is :");
		printf("%s%s%s%d%d\n",last->usn,last->name,last->branch,last->sem,last->phno);
		free(last);
		temp->next=NULL;
		last=temp;
	
	}
	count--;
	return 0;
	
}
int deletefront()
{
	struct node *temp;
	temp=first;
	if (temp->next==NULL)
	{
		free(temp);
		first=NULL;
		return 0;
		
	}
	else
	{
		first=temp->next;
		printf("the element deleted is :");
		printf("%s%s%s%d%d",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
		free(temp);
		
}
count--;
return 0;
}
main()
{ int ch,n,i;
first=NULL;
temp=temp1=NULL;
printf("*****SLL implementation *******");
printf("\n1.create a SLL of n students");
printf("\n2.display from begining along with count ");
printf("\n3.insert at end used for demonstrating stack");
printf("\n4.delete at end used for demonstrating stack");
printf("\n5.insert at beg");
printf("\n6.delete at beg");
printf("\n7.exit");
while(1)
{
	printf("\n enter choice:\n");
	scanf("%d",&ch);
	switch(ch)
{
	case 1:
		printf("\n enter no. of students:");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		insert_atfirst();
		break;
	case 2:
			display();
			break;
			case 3:
				insert_atlast();
				break;
				case 4:
					deleteend();
					break;
					case 5:
						insert_atfirst();
							break;
							case 6:
								deletefront();
								break;
								case 7:
								exit(0);
								default: printf("wrong choice\n");
								
}
}
}
