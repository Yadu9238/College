#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?x:y

int main()
{
	int count =0,i,j,input[20]={0},cap;
	int nsec,ch,orate
	printf("Enter bucket size\n");
	scanf("%d",&cap);
	printf("Enter required output rate:\n");
	scanf("%d",&orate);

	do{
		printf("Enter number of packets coming at %d th second",(i+1) );
		scanf("%d",&input[i]);
		i++;
		printf("Press 1 to enter next packet \t 0 to exit");
		scanf("%d",&ch);
	}while(ch);

	nsec = i;
	for( i=0;count || i <nsec;i++)
	{
		printf("%d", i+1);
		printf("\t %d \t", input[i] );
		printf("\t %d \t",MIN(input[i]+count,orate));
		if((x= input[i] + count - orate)>0)
		{
			if()
		}
	}
}