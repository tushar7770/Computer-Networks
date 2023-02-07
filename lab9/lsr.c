//cs20b1098 tushar panjeta
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

//number of vertices
int V;

//function to find vertex with minimum distance
int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
			min = dist[v], min_index = v;
        }
    }
	return min_index;
}

void printSolution(int dist[])
{
	printf("Vertex \t\t min distance from Source\n");
	for (int i = 0; i < V; i++)
    {
		printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

//function for Dijkstra's
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist);
}

int main()
{
    printf("Enter the no of verteies :");
    scanf("%d",&V);
    int graph[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            graph[i][j]=0;
        }
    }
    int edges,node1,node2,distance;
    printf("Enter the number of edges:");
    scanf("%d",&edges);

    printf("Enter in this format:\n");
    printf("RouterX\tRouterY\tDistance:\n");
    for(int i=0;i<edges;i++){
        scanf("%d %d %d",&node1,&node2,&distance);
        graph[node1][node2]=distance;
        graph[node2][node1]=distance;
    }

	dijkstra(graph, 0);

	return 0;
}