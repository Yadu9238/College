#include<stdio.h>
#include<math.h>
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void warshall(int a[20][20],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	 for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
		a[i][j]=max(a[i][j],a[i][k]&&a[k][j]);
}

void main()
{
	int n,j,i,e,u,v;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter number of edges\n");
	scanf("%d",&e);
	int a[20][20]={0};
	for(i=1;i<=e;i++)
	{
		printf("Enter the end vertices of edge %d",i);
		scanf("%d%d",&u,&v);
		a[u][v]=1;
	}
	
	printf("The input matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	warshall(a,n);
	printf("After warshall's\n");
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}

}							
