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


void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n%d: ", v);
        while (temp)
        {
            printf("%d ,", temp->vertex);
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


stack createStack(unsigned size)
{
    stack s = malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->data = malloc(s->size * sizeof(int));
    return s;
}
//stack methods
void push(stack s, int val)
{
    if (s->top == s->size - 1)
        printf("Stack is full");
    else
    {
        s->data[++s->top] = val;
    }
}

int pop(stack s)
{
    if (s->top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return s->data[s->top--];
    }
}
int isStackEmpty(stack s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void dfs(graph g, int sV) {
    stack s = createStack(10);
    g->visited[sV] = 1;
    push(s, sV);
    while (!isStackEmpty(s)) {
        int cV = pop(s);
        printf("%d ", cV);
        node temp = g->adjLists[cV];
        while (temp) {
            int aV = temp->vertex;
            if (g->visited[aV] == 0) {
                g->visited[aV] = 1;
                push(s, aV);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    // adjacency list
    int n;
    printf("BFS\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    graph g = createGraph(n);
    while (1)
    {
        printf("Enter the source and destination vertices: ");
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;
        addEdge(g, src, dest);
    }
    printGraph(g);
    printf("Enter the starting vertex: ");
    int sV;
    scanf("%d", &sV);
    bfs(g, sV);
    free(g);
    printf("\nDFS\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    g = createGraph(n);
    while (1)
    {
        printf("Enter the source and destination vertices: ");
        int src, dest;
        scanf("%d %d", &src, &dest);
        if (src == -1 && dest == -1)
            break;
        addEdge(g, src, dest);
    }
    printGraph(g);
    printf("Enter the starting vertex: ");
    scanf("%d", &sV);
    dfs(g, sV);
    free(g);
    return 0;
}
