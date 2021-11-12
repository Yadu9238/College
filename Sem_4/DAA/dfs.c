#include<stdio.h>
int a[20][20],reach[20]={0},n,v;

void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
		if(a[v][i] && !reach[i])
		{
			printf("\n %d -> %d ",v,i);
			dfs(i);
		}
}

void main()
{
	int i,j,c=0;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix\n");
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	
	printf("Enter starting node\n");
	scanf("%d",&v);
	printf("Nodes traversed:");
	dfs(v);
	for(i=1;i<=n;i++)
		if(reach[i])
			c++;
	if(c==n)
		printf("\nGraph is connected\n");
	else
		printf("\nGraph is not connected\n");
}
