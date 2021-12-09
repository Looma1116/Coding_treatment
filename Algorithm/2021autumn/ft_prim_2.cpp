#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
    int weight;
} edge;

typedef struct node
{
    int name;
    int distance;
    edge *header;
    node *next;
    node *prev;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *add);
void addEdge(node *v1, node *v2, int w);
node *removeMin();
node *findNode(int name);
bool isEmpty();
void replaceKey(node *p);
void Prim();

node *G;
int total;

int main()
{
    getNode(&G);
    total = 0;
    int n, m, w, v1, v2;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        node *p;
        getNode(&p);
        p->name = i;
        addNode(p);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        addEdge(findNode(v1), findNode(v2), w);
        addEdge(findNode(v2), findNode(v1), w);
    }
    Prim();
    printf("\n%d", total);

    return 0;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->distance = 99999;
    (*p)->header = e;
    (*p)->next = NULL;
    (*p)->prev = NULL;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->next = NULL;
    (*e)->to = NULL;
}
void addNode(node *add)
{
    node *tmp;
    tmp = G;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    add->next = tmp->next;
    add->prev = tmp;
    tmp->next = add;
}
void addEdge(node *v1, node *v2, int w)
{
    edge *tmp, *e;
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    e->weight = w;
    tmp = v1->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    e->next = tmp->next;
    tmp->next = e;
}
node *removeMin()
{
    node *tmp;
    tmp = G->next;
    G->next = tmp->next;
    tmp->next = NULL;
    tmp->prev = NULL;
    printf(" %d", tmp->name);
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
        if (tmp->name == name)
        {
            return tmp;
        }
    }
    return NULL;
}
bool isEmpty()
{
    return G->next == NULL;
}
void replaceKey(node *p)
{
    node *tmp;
    while (p->prev != G && p->distance < p->prev->distance)
    {
        tmp = p->prev;
        tmp->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = tmp;
        }
        p->next = tmp;
        p->prev = tmp->prev;
        tmp->prev->next = p;
        tmp->prev = p;
    }
    while (p->next != NULL && p->distance > p->next->distance)
    {
        tmp = p->next;
        tmp->prev = p->prev;
        p->prev->next = tmp;
        if (tmp->next != NULL)
        {
            tmp->next->prev = p;
        }
        p->next = tmp->next;
        tmp->next = p;
        p->prev = tmp;
    }
}
void Prim()
{
    node *ntmp;
    edge *etmp;
    G->next->distance = 0;
    while (!isEmpty())
    {
        ntmp = removeMin();
        etmp = ntmp->header;
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            if (findNode(etmp->to->name) != NULL && etmp->to->distance > etmp->weight)
            {
                etmp->to->distance = etmp->weight;
                replaceKey(etmp->to);
            }
        }
    }
}
