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
    int visited;
    node *next;
    edge *header;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *p);
void addEdge(node *ver1, node *ver2);
node *findNode(int name);
void DFS(node *s);
node *G;

int main()
{
    getNode(&G);
    int n, m, s, v1, v2;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        node *p;
        getNode(&p);
        p->value = i + 1;
        addNode(p);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &v1, &v2);
        addEdge(findNode(v1), findNode(v2));
        addEdge(findNode(v2), findNode(v1));
    }
    DFS(findNode(s));
    return 0;
}

void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->visited = 0;
    (*p)->header = e;
    (*p)->next = NULL;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->next = NULL;
    (*e)->from = NULL;
    (*e)->to = NULL;
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
}
void addEdge(node *ver1, node *ver2)
{
    edge *tmp, *e;
    tmp = ver1->header;
    while (tmp->next != NULL && tmp->next->to->value < ver2->value)
    {
        tmp = tmp->next;
    }
    getEdge(&e);
    e->from = ver1;
    e->to = ver2;
    e->next = tmp->next;
    tmp->next = e;
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
    printf("There's no node have that name\n");
    return NULL;
}
void DFS(node *s)
{
    s->visited = 1;
    printf("%d\n", s->value);
    edge *tmp;
    tmp = s->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->to->visited != 1)
        {
            DFS(tmp->to);
        }
    }
    return;
}