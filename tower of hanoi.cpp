#include<stdio.h>
#include<stdlib.h>
void towers(int,char,char,char);

main()
{
	int num;
	printf("enter the number of disk\n");
	scanf("%d",&num);
	printf("the sequence of moves involved in the tower of hanoi are\n");
	towers(num,'s','t','d');

}
void towers(int num,char s,char t,char d)
{
if (num==1)
{
	printf("\n move disk 1 from peg %c to peg %c",s,d);
	return;
}
	towers(num-1,s,d,t);
	printf("\n move disk %d from peg %c to peg %c",num,s,d);
	towers(num-1,t,s,d);
}

