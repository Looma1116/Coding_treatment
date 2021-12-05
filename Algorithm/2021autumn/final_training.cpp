#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    int weight;
} edge;

typedef struct node
{
    char value;
    node *next;
    node *prev;
    edge *header;
    bool visited;
    int in;
} node;

void getEdge(edge **);
void getNode(node **);
bool isEmpty(node *);
void addNode(node *);
void addEdge(node *, node *, int weight);

int main()
{
    return 0;
}

void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->to = NULL;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->next = NULL;
    (*p)->prev = NULL;
    (*p)->header = e;
}

bool isEmpty(node *Q)
{
    return (Q->next == NULL);
}
void addNode(node *Q)
{
    node *tmp;
    tmp = Q;
    while (tmp != NULL)
    {
    }
}
void addEdge(node *, node *, int weight);
