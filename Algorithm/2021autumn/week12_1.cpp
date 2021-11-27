#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Q[101], in[101], topOrder[102], n;
int head = -1, tail = -1;

typedef struct edge
{
    int origin;
    int destination;
} edge;

typedef struct node
{
    node *next;
    int element;
} node;

typedef struct vertex
{
    char name;
    int inDegree;
    node *outEdges;
    node *inEdges;
} vertex;

typedef struct graph
{
    edge edges[101];
    vertex vertices[101];
} graph;

void getNode(node **p)
{
    (*p) = (node *)malloc(sizeof(node));
    (*p)->next = NULL;
}

graph G;

void buildGraph();
void insertVertex(char vName, int i);
void insertDirectedEdge(char uName, char vName, int i);
int index(char vName);
void addFirst(node *H, int i);
int dequeue();
int isEmpty();
void enqueue(int value);

void buildGraph()
{
    int i, m;
    char vName, uName, wName;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        getNode(&(G.vertices[i].inEdges));
        getNode(&(G.vertices[i].outEdges));
        scanf("%c ", &vName);
        insertVertex(vName, i);
    }
    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++)
    {
        scanf("%c %c", &uName, &wName);
        getchar();
        insertDirectedEdge(uName, wName, i);
    }
    return;
}

void insertVertex(char vName, int i)
{
    G.vertices[i].name = vName;
    getNode(&(G.vertices[i].outEdges));
    getNode(&(G.vertices[i].inEdges));
    G.vertices[i].inDegree = 0;
    return;
}

void insertDirectedEdge(char uName, char wName, int i)
{
    int u, w;
    u = index(uName);
    w = index(wName);
    G.edges[i].origin = u;
    G.edges[i].destination = w;
    addFirst(G.vertices[u].outEdges, i);
    addFirst(G.vertices[w].inEdges, i);
    G.vertices[w].inDegree++;
    return;
}

int index(char vName)
{
    for (int i = 0; i < n; i++)
    {
        if (G.vertices[i].name == vName)
        {
            return i;
        }
    }
}

void addFirst(node *H, int i)
{
    node *p;
    getNode(&p);
    p->element = i;
    p->next = H->next;
    H->next = p;
    return;
}

void topologicalSort()
{
    int u, w, e;
    for (int i = 0; i < n; i++)
    {
        in[i] = G.vertices[i].inDegree;
        if (in[i] == 0)
        {
            u = i;
            enqueue(u);
        }
    }
    int t = 1;
    while (!isEmpty())
    {
        u = dequeue();
        topOrder[t] = u;
        t++;

        node *tmp;
        tmp = G.vertices[u].outEdges->next;
        while (tmp != NULL)
        {
            e = tmp->element;
            w = G.edges[e].destination;
            in[w]--;
            if (in[w] == 0)
            {
                enqueue(w);
            }
            tmp = tmp->next;
        }
    }
    if (t <= n)
    {
        topOrder[0] = 0;
    }
    else
    {
        topOrder[0] = 1;
    }
    return;
}
int dequeue()
{
    int i;
    if (head == tail)
    {
        return -1;
    }
    i = Q[head];
    ++head;
    head %= 101;
    return i;
}

void enqueue(int value)
{
    if ((tail + 1) % 101 == head)
    {
        printf("full Queue\n");
        return;
    }
    Q[tail] = value;
    ++tail;
    tail %= 101;
    return;
}

int isEmpty()
{
    if (head == tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    buildGraph();
    topologicalSort();
    if (topOrder[0] == 0)
    {
        printf("0\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%c ", G.vertices[topOrder[i]].name);
        }
    }
    return 0;
}