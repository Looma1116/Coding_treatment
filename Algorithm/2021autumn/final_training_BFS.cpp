#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
} edge;

typedef struct node
{
    int value;
    edge *header;
    node *next;
    int visited;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *list, node *add);
void addEdge(node *v1, node *v2);
node *findNode(node *list, int name);
bool isEmpty(node *list);
void BFS(node *s);
void enQ(node *Q, node *add);
int deQ(node *Q);

node *G, *Q;
int main()
{

    int n, m, s, v1, v2;
    scanf("%d %d %d", &n, &m, &s);
    getNode(&G);
    getNode(&Q);
    for (int i = 0; i < n; i++)
    {
        node *p;
        getNode(&p);
        p->value = i + 1;
        addNode(G, p);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &v1, &v2);
        addEdge(findNode(G, v1), findNode(G, v2));
        addEdge(findNode(G, v2), findNode(G, v1));
    }
    BFS(findNode(G, s));
    return 0;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->next = NULL;
    (*p)->header = e;
    (*p)->visited = 0;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->to = NULL;
    (*e)->next = NULL;
}
void addNode(node *list, node *add)
{
    node *tmp;
    tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = add;
}
void addEdge(node *v1, node *v2)
{
    edge *tmp, *e;
    tmp = v1->header;
    while (tmp->next != NULL && tmp->next->to->value < v2->value)
    {
        tmp = tmp->next;
    }
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    e->next = tmp->next;
    tmp->next = e;
}
node *findNode(node *list, int name)
{
    node *tmp;
    tmp = list;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->value == name)
        {
            return tmp;
        }
    }
    printf("no node");
    return NULL;
}
void BFS(node *s)
{
    node *ntmp;
    edge *etmp;
    int name;
    ntmp = s;
    enQ(Q, ntmp);
    while (!isEmpty(Q))
    {
        int name = deQ(Q);
        ntmp = findNode(G, name);
        etmp = ntmp->header;
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            if (etmp->to->visited != 1)
            {
                enQ(Q, etmp->to);
            }
        }
    }
}
bool isEmpty(node *list)
{
    return list->next == NULL;
}
void enQ(node *Q, node *add)
{
    node *tmp, *addCopy;
    tmp = Q;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    getNode(&addCopy);
    addCopy->value = add->value;
    tmp->next = addCopy;
    add->visited = 1;
}
int deQ(node *Q)
{
    int value;
    value = Q->next->value;
    Q->next = Q->next->next;
    printf("%d\n", value);
    return value;
}