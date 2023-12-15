#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>
#define MAX 100

int graph[MAX][MAX];
int queue[MAX];
int visited[MAX];
int front = 0;
int rear = -1;
int numOfVertices;

void enqueue(int element)
{
  if(rear == MAX - 1)
    return;
  queue[++rear] = element;
}

int dequeue()
{
  if(front <= rear)
	  return queue[front++];
}

void createGraph()
{
  int i, j;
  // clrscr();
  printf("\nEnter the number of vertices in graph: ");
  scanf("%d", &numOfVertices);

  for (i = 0; i < numOfVertices; i++)
  {
    // clrscr();
    printf("\bEnter the Adjacency for vertex %d", i + 1);
	  for (j = 0; j < numOfVertices; j++)
    {
      printf("\n%d -> %d? (1/0): ", i + 1, j + 1);
      scanf("%d", &graph[i][j]);
    }
  }
}

void displayAdjacencyMatrix()
{
  int i, j;
  // clrscr();
  printf("\nAdjacency Matrix of Graph is: ");

  printf("\n\n  ");
  for (i = 0; i < numOfVertices; i++)
    printf("%d ", i + 1);
  for (i = 0; i < numOfVertices; i++)
  {
    printf("\n%d ", i + 1);
    for (j = 0; j < numOfVertices; j++)
      printf("%d ", graph[i][j]);
  }
}

void bfs(int root)
{
  int i, j, k;

  if (--root >= numOfVertices || root < 0)
	  return;

  for (i = 0; i < numOfVertices; i++)
	  visited[i] = 0; 

  enqueue(root);
  visited[root] = 1;

  while(front <= rear)
  {
    k = dequeue();
    printf("%d ", k + 1);

    for (i = 0; i < numOfVertices; i++)
    {
      if(graph[k][i] == 1 && visited[i] == 0)
      {
        enqueue(i);
        visited[i] = 1;
      }
    }
  }
}

void dfs(int root)
{
 
int i;

  if (root >= numOfVertices || root < 0 || visited[root])
    return;


  printf("%d ", root+1);
  visited[root] = 1;

  for (i = 0; i < numOfVertices; i++)
  {
    if(graph[root][i] == 1 && visited[i] == 0)
      dfs(i);
  }
}

int main()
{
  int choice, root, i;
  createGraph();

  while(1)
  {
    displayAdjacencyMatrix();
    printf("\n---- MENU ----");
    printf("\n1. BFS\n2. DFS\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        printf("\nEnter the starting vertex: ");
        scanf("%d", &root);
        bfs(root);
        break;

      case 2:
        printf("\nEnter the starting vertex: ");
        scanf("%d", &root);
        for (i = 0; i < numOfVertices; i++)
          visited[i] = 0;
        dfs(root );
        break;

      case 3:
        exit(0);
    }
    // getch();
  }
  return 0;
}