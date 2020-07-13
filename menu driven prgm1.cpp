#include<stdio.h>
#include<stdlib.h>
int i,n,ele,pos,a[10];
void create()
{
	printf("enter how many elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
}
void disp()
{
	printf("the array elements are\n");
	if (n==0)
	printf("array is empty\n");
	else
	for (i=0;i<n;i++)
	printf("a[%d]=%d\n",i,a[i]);
}
void insert()
{
	printf("enter the elements and position\n");
	scanf("%d%d",&ele,&pos);
	if(pos>=0 && pos<n )
	{
		for(i=n-1;i>=pos;i--)
		a[i+1]=a[i];
		a[pos]=ele;
		n++;
		
	}
	else
	{
		printf("invalid position\n");
		
	}
}
void delet()
{
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos>=0 && pos<n)
	{
		ele=a[pos];
		for (i=pos;i<n-1;i++)
		a[i]=a[i+1];
		n--;
	}
	else printf("invalid postion\n");
	
}
main()
{
	int ch;
	while(1)
	{
		printf("1create\n2display\n3insert\n4delete\n5exit\nenter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
				case 2: 
				disp();
				break;
				case 3:
					insert();
					break;
					case 4:
						delet();
						break;
				case 5:
				exit(1);
				printf("invalid choice\n");
	}
	}
}
