#include<stdio.h>
#include<stdlib.h>
#define m 5
int a[10],l;
void init_hashtable()
{
	int i;
	for(i=0;i<m;i++)
	a[i]=0;
	
}
void display()
{
	int i;
	printf("****hash table\n****");
	printf("locat:\n");
	for(i=0;i<m;i++)
	{
		printf("%d\t",i);
	}
		printf("\n");
		printf("value:");
		for(i=0;i<m;i++)
		{
			printf("%d\t",a[i]);
			
		}
	}
	int compute_hashvalue(int k)
{
	return k%m;
	
}
main()
{
	int i,k,ch,c=0;
	init_hashtable();
	display();
	printf("\n1.insert key\n2.resolve collision_linear probing\n3.exit\n");
	while(1)
	{
		printf("\nenter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the key k which is a four digit integer :\n");
				scanf("%d",&k);
				l=compute_hashvalue(k);
				printf("\n the item is %d\n the position is %d\n",k,l);
				if(a[l]!=0)
				{
					printf("collision occured !!!!!!\n");
					break;
					
				}
				else
				{
					a[l]=k;
					display();
					
				}
				break;
				case 2:
					c=0;
					while (a[l]!=0 && c<m)
					{
						l=(l+1)%m;
						c++;
						
					}
					if(c==m)
				{
					printf("hash table full\n");
					
				}
				else
				{
					a[l]=k;
					display();
					
				}
				break;
				case 3: exit(0);
				break;
				default:printf("wrong choice\n");
				break;
				
		}
	}
}

