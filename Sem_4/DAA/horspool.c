#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 128

int t[max];

void shifttable(char p[])
{
	int i,j,m;
	m=strlen(p);
	for(i=0;i<max;i++)
		t[i]=m;
	for(j=0;j<m-1;j++)
		t[p[j]]=m-1-j;
}

int horspool(char src[],char p[])
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
			return (i-m+1);
		else
			i+=t[src[i]];
	}
	return -1;
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
	pos=horspool(src,p);
	if(pos>=0)
		printf("Pattern found at index %d\n",pos);
	else
		printf("Pattern not found ");
}

