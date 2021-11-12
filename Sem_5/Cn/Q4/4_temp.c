#include<stdio.h>
#define infinity 999

void dijkstra(int n, int source, int cost[10][10], int dist[10])
{
	 int i, j,w, flag[10],u,min; 

	 //initialisation
	 for ( i = 0;i<n;i++)
	 {
	 	flag[i] = 0;
	 	dist[i] = cost[source][i];

	 }
	 //flag[source] = 1;
	 //dist[source]= 0;
	 for (i = 1;i<n;i++)
	 {
	 	min = infinity;
	 	for(j =0;j<n;j++)
	 	{
	 		if(dist[j] <min && !flag[j])
	 			{
	 				min = dist[j];u = j;
	 				
	 			}
	 	}	
	 	flag[u]  = 1;
	 	for(j=0;j<n;j++)
	 	{	

	 		if(cost[u][j] != infinity && !flag[j])
	 		{
	 			if(dist[j]>cost[u][j] + dist[u])
	 				dist[j] = cost[u][j] + dist[u];
	 		}
	  	}
	  	
	 }
}


void main(){
	int n,cost[10][10],source,d[10],i,j;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = infinity;
		}
		
	}

	printf("Cost matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",cost[i][j]);

		}
		printf("\n");
	}
	printf("Enter source node\n");
	scanf("%d",&source);

	dijkstra(n,source,cost,d);
	for(i=0;i<n;i++)
		if(i!= source)
			printf("%d - > %d: %d\n",source,i,d[i]);
}