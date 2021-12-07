#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    int weight;
    edge *next;
} edge;

typedef struct node
{
    int value;
    int distance;
    int visit;
    edge *header;
    node *next;
    node *prev;
} node;

void addNode(node *p);
void addEdge(node *from, node *to, int w);
void getNode(node **p);
void getEdge(edge **e);
void replaceKey(node *p);
node *removeMin();
node *findNode(int name);
void prim();

int n, m, total;
node *G;

int main()
{
    getNode(&G);
    int ver1, ver2, w;
    total = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        node *p;
        getNode(&p);
        p->value = i + 1;
        addNode(p);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &ver1, &ver2, &w);
        addEdge(findNode(ver1), findNode(ver2), w);
        addEdge(findNode(ver2), findNode(ver1), w);
    }
    prim();
    printf("\n%d", total);
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->distance = 20000;
    (*p)->header = e;
    (*p)->prev = NULL;
    (*p)->next = NULL;
    (*p)->visit = 0;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->to = NULL;
    (*e)->next = NULL;
}
void addNode(node *p)
{
    node *tmp;
    tmp = G;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = p;
    p->prev = tmp;
}
void addEdge(node *from, node *to, int w)
{
    edge *tmp, *e;
    getEdge(&e);
    e->weight = w;
    e->from = from;
    e->to = to;
    tmp = from->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = e;
}
void replaceKey(node *p)
{
    node *tmp;
    while (p->prev != G && p->distance < p->prev->distance)
    {
        tmp = p->prev;
        tmp->next = p->next;
        p->prev = tmp->prev;
        tmp->prev->next = p;
        tmp->prev = p;
        if (p->next != NULL)
        {
            p->next->prev = tmp;
        }
        p->next = tmp;
    }
    while (p->next != NULL && p->distance > p->next->distance)
    {
        tmp = p->next;
        tmp->prev = p->prev;
        p->next = tmp->next;
        if (tmp->next != NULL)
        {
            tmp->next->prev = p;
        }
        tmp->next = p;
        p->prev->next = tmp;
        p->prev = tmp;
    }
}
node *removeMin()
{
    node *tmp;
    tmp = G->next;
    printf(" %d", tmp->value);
    G->next = tmp->next;
    if (G->next != NULL)
    {
        G->next->prev = G;
    }
    tmp->next = NULL;
    tmp->prev = NULL;
    total += tmp->distance;
    return tmp;
}
node *findNode(int name)

{
    node *tmp;
    tmp = G;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->value == name)
        {
            return tmp;
        }
    }
    return NULL;
}
void prim()
{
    node *ntmp;
    edge *etmp;
    int pathDistance;
    ntmp = findNode(1);
    ntmp->distance = 0;
    replaceKey(ntmp);
    removeMin();
    etmp = ntmp->header;
    while (etmp->next != NULL)
    {
        etmp = etmp->next;
        pathDistance = ntmp->distance + etmp->weight;
        if (etmp->to->distance > pathDistance)
        {
            etmp->to->distance = pathDistance;
            replaceKey(etmp->to);
        }
    }
    while (G->next != NULL)
    {
        ntmp = removeMin();
        ntmp->distance = 0;
        etmp = ntmp->header;
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            pathDistance = ntmp->distance + etmp->weight;
            if (etmp->to->distance > pathDistance)
            {
                etmp->to->distance = pathDistance;
                replaceKey(etmp->to);
            }
        }
    }
}