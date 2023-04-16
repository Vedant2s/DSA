#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph data structure
struct Graph {
    int numVertices;
    int** adjMatrix;
};

// Function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            graph->adjMatrix[i][j] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

// Function to perform DFS traversal of the graph
void DFS(struct Graph* graph, int startVertex, bool visited[]) {
    visited[startVertex] = true;
    printf("%d ", startVertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex, bool visited[]) {
    // Create a queue for BFS traversal
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front != rear) {
        startVertex = queue[++front];
        printf("%d ", startVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[startVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

// Main function
int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    //addEdge(graph, 4, 4);

    // Perform DFS and BFS traversal of the graph
    bool visited[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    printf("DFS Traversal: ");
    DFS(graph, 0, visited);
    printf("\n");

    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    printf("BFS Traversal: ");
    BFS(graph, 0, visited);
    printf("\n");

    return 0;
}
