#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int check(int num)
{
	char inp[50];
	int i,temp,sum =0,n,value;
	printf("Enter input string\n");
	scanf(" %[^\n]s",inp);

	if(strlen(inp)%2 == 0)
		n = strlen(inp)/2;
	else
		n = strlen(inp)/2 +1;

	for(i=0;i<n;i++)
	{
		temp = inp[2*i];
		temp = temp*256+inp[2*i +1];
		sum = sum+ temp;
	}
	if(num==1)
	{
		printf("Enter checksum value\n");
		scanf("%x",&value);
		sum = sum+value;
	}
	if(sum%65536 !=0)
	{
		n = sum%65536;
		sum = sum/65536 +n;
	}
	sum = 65535 -sum;
	return sum;

}

void main()
{
	char input[100],n;
	printf("1.Encrypt\n2.Decrypt\n3.Exit\n");
	scanf("%d",&n);
	switch(n){
		case 1:check(0);
				break;
		case 2:check(1);
				break;
		case 3:exit(0);
	}
	return 0;
}
