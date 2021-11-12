#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 128

int t[max];
int flag=1;
void shifttable(char p[])
{
	int i,j,m;
	m=strlen(p);
	for(i=0;i<max;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}

void horspool(char src[],char p[])
{
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	printf("\nText size:%d\n",n);
	printf("\nPattern size:%d\n",m);
	
	i=m-1;
	while(i<n)
	{
		k=0;
		while(k<m && (p[m-1-k]==src[i-k]))
			k++;
		if(k==m)
		{	printf("pattern found at%d\n",(i-m+1));flag=0;i++;}
		else
			i+=t[src[i]];
	}
	if(flag==1)
		printf("Pattern not found\n");
	
}

void main()
{
	char src[max],p[max];
	int pos;
	printf("Enter text\n");
	gets(src);
	printf("Enter pattern to check \n");
	gets(p);
	shifttable(p);
	
	
				horspool(src,p);
	}

