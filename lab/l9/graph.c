#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

struct stack
{
    int top;
    unsigned size;
    int *data;
};

typedef struct node *node;
typedef struct Graph *graph;
typedef struct queue *queue;
typedef struct stack *stack;

node createNode(int v)
{
    node newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph createGraph(int vertices)
{
    graph g = malloc(sizeof(struct Graph));
    g->numVertices = vertices;
    g->adjLists = malloc(vertices * sizeof(node));
    g->visited = malloc(vertices * sizeof(int));
    // for (int i = 0; i < vertices; i++)
    // {
    //     // g->adjLists[i] = NULL;
    //     // g->visited[i] = 0;
    // }
    return g;
}

void addEdge(graph g, int src, int dest)
{
    node newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

// queue for bfs
queue createQueue()
{
    queue q = malloc(sizeof(struct queue));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = malloc(q->size * sizeof(int));
    return q;
}

void enqueue(queue q, int val)
{
    if (q->r - q->f == q->size)
        printf("Queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d", val);
    }
}

int dequeue(queue q)
{
    if (q->f == q->r)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int isEmpty(queue q)
{
    if (q->f == q->r)
        return 1;
    else
        return 0;
}

void printQueue(queue q)
{
    if (isEmpty(q))
        printf("Queue is empty");
    for (int i = q->f; i <= q->r; i++)
        printf("%d ", q->arr[i]);
}

// Print the graph
void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(graph g, int sV)
{
    queue q = createQueue();
    g->visited[sV] = 1;
    enqueue(q, sV);
    while (!isEmpty(q))
    {
        // printQueue(q);
        int cV = dequeue(q);
        printf("%d ", cV);
        node temp = g->adjLists[cV];
        while (temp)
        {
            int aV = temp->vertex;
            if (g->visited[aV] == 0)
            {
                g->visited[aV] = 1;
                enqueue(q, aV);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    // //adjacency list
    // int n;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &n);
    // graph g = createGraph(n);
    // while (1)
    // {
    //     printf("Enter the source and destination vertices: ");
    //     int src, dest;
    //     scanf("%d %d", &src, &dest);
    //     if (src == -1 && dest == -1)
    //         break;
    //     addEdge(g, src, dest);

    // }
    // printGraph(g);
    // // bfs
    // // queue q = createQueue();

    // int startVertex;
    // printf("Enter the starting vertex: ");
    // scanf("%d", &startVertex);
    // bfs(g, startVertex);
    // // g->visited[startVertex] = 1;
    // // enqueue(q, startVertex);
    // // while (!isEmpty(q))
    // // {
    // //     printQueue(q);
    // //     int currentVertex = dequeue(q);
    // //     printf("%d ", currentVertex);
    // //     node temp = g->adjLists[currentVertex];
    // //     while (temp)
    // //     {
    // //         int adjVertex = temp->vertex;
    // //         if (g->visited[adjVertex] == 0)
    // //         {
    // //             g->visited[adjVertex] = 1;
    // //             enqueue(q, adjVertex);
    // //         }
    // //         temp = temp->next;
    // //     }
    // // }

    // test code
    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    // addEdge(graph, 3, 4);
    printGraph(graph);
    bfs(graph, 0);

    return 0;
}