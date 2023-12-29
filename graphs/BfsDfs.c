#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack implementation using array
int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

// Queue implementation using array
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
}
int dequeu()
{
int val;
if(front == -1 || front>rear)
{
printf("\n UNDERFLOW");
return -1;
}
else
{
val = queue[front];
front++;
if(front > rear)
front = rear = -1;
return val;
}
}

int isQueueEmpty() {
    return front == -1;
}

void dfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int start, int vertices) {
    printf("DFS: ");
    push(start);
    visited[start] = 1;

    while (!isStackEmpty()) {
        int current = pop();
        printf("%d ", current);

        for (int i = 0; i < vertices; ++i) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

void bfs(int graph[MAX_SIZE][MAX_SIZE], int visited[MAX_SIZE], int start, int vertices) {
    printf("BFS: ");
    enqueue(start);
    visited[start] = 1;

    while (!isQueueEmpty()) {
        int current = dequeu();
        printf("%d ", current);

        for (int i = 0; i < vertices; ++i) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    int graph[MAX_SIZE][MAX_SIZE] = {0};
    int visited[MAX_SIZE] = {0};

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < edges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dfs(graph, visited, startVertex, vertices);

    // Reset visited array
    for (int i = 0; i < MAX_SIZE; ++i) {
        visited[i] = 0;
    }

    bfs(graph, visited, startVertex, vertices);

    return 0;
}
