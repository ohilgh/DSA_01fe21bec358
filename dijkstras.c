#include <stdio.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX_SIZE 100

int minDistance(int dist[], bool visited[], int V) {
    int min = INFINITY, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int src, int V) {
    int dist[MAX_SIZE];     // Stores the shortest distance from source to each vertex
    bool visited[MAX_SIZE]; // Keeps track of visited vertices

    // Initialize all distances as INFINITY and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INFINITY;
        visited[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        // Update dist[v] only if it is not visited, there is an edge from u to v,
        // and the total weight of path from src to v through u is smaller than current value of dist[v]
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    printSolution(dist, V);
}

// Driver program to test the above implementation
int main() {
    int V, src;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}
