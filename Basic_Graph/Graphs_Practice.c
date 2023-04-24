#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int main()
{
	int n,max_edge;
	int i,j;
	int origin, destin;
	int graph_type;
	printf("Enter 1 for undirected graph and 2 for directed graph : ");
	scanf("%d",&graph_type);
	printf("Enter the no of edges: ");
	scanf("%d",&n);
	if(graph_type == 1)
	{
		max_edge = n*(n-1)/2;
	}
	else
	    max_edge = n*(n-1);
	for(i = 1; i<= max_edge; i++)
	{
		printf("Enter the edges (-1 -1 to Quit) : ");
		scanf("%d %d", &origin, &destin);
		if(origin == -1 && destin == -1)
		{
			break;
		}
		if(origin < 0 || destin< 0 || origin >= n || destin >=  n)
		{
			printf("Please enter the valid Edges");
			i--;
		}
		else
		{
			adj[origin][destin] = 1;
			if(graph_type == 1)
			{
				adj[destin][origin];
			}
		}
	}
	printf("Enter the adjacency matrix is : ");
	for(i = 0; i<=n-1;i++)
	{
		for(j = 0; j=<n-1;j++)
		{
			printf("%4d",adj[i][j]);
		}
		printf("\n");
	}
}
