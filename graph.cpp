#include<stdio.h>
#include<stdlib.h>
void create(int a[10][10],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			
		}
	}
}
void bfs(int a[10][10],int n,int u)
{
	int f,r,q[10],v;
	int s[10]={0};
	printf("nodes visited is %d",u);
	f=0;
	r=-1;
	q[++r]=u;
	s[u]=1;
	printf("%d",u);
	while(f<=r)
	{
		u=q[f++];
		for (v=0;v<n;v++)
		{
			if(a[u][v]==1)
			{
				if(s[v]==0)
			{
			
			
			printf("%d",v);
			s[v]=1;
			q[++r]=v;
		}
		}
	}
}
printf("\n");
}
main()
{
	int n,a[10][10],src,i,j;
	printf("enter the number of cities\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	create(a,n);
	for(src=0;src<n;src++)
	bfs(a,n,src);
	}

