#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

void dfsTopological(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int start, int vertices) {
    visited[start] = 1;

    for (int i = 0; i < vertices; ++i) {
        if (graph[start][i] == 1 && visited[i] == 0) {
            dfsTopological(graph, visited, i, vertices);
        }
    }

    push(start);
}

void topologicalSort(int graph[MAX_SIZE][MAX_SIZE], int vertices) {
    int visited[MAX_SIZE] = {0};

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            dfsTopological(graph, visited, i, vertices);
        }
    }

    printf("Topological Sort: ");
    while (!isStackEmpty()) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_SIZE][MAX_SIZE] = {0};

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < edges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed edge
    }

    topologicalSort(graph, vertices);

    return 0;
}
