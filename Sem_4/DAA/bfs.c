#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;

void bfs(int v)
{
	for(i=1;i<=n;i++)
	 if(a[v][i] && !visited[i])	
		{
			q[++r]=i;
			
		}
	
	if(f<=r)
		{
			visited[q[f]]=1;bfs(q[f++]);}
}

void main()
{
	int v,c=0;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix\n");
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
	
	printf("Enter starting vertex\n");
	scanf("%d",&v);
	visited[v]=1;
	bfs(v);
	
	printf("Reachable nodes(in traversal order):");
	printf("%d",v);
	for(i=0;i<n-1;i++)
		printf(" %d",q[i]);
	
	for(i=1;i<=n;i++)
		{if(visited[i])
			c++;
		
		}
	if(c==n)
		printf("\nGraph is connected\n");
	else
		printf("\nBfs is not possible\n");
}
