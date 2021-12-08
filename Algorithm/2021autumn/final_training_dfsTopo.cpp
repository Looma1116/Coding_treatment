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
    node *next;
    node *prev;
    edge *header;
    char value;
    int visit;
    int topo;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *p);
void addEdge(node *v1, node *v2);
node *findNode(char name);
void DFStopologi(node *s);
node *G;
char *TOP;
int n, m;
int main()
{
    getNode(&G);
    char v1, v2;
    int num;
    scanf("%d", &n);
    num = n;
    TOP = (char *)malloc(sizeof(char) * n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        node *p;
        getNode(&p);
        scanf("%c", &v1);
        getchar();
        p->value = v1;
        addNode(p);
    }
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        scanf("%c %c", &v1, &v2);
        addEdge(findNode(v1), findNode(v2));
        getchar();
    }

    node *tmp;
    tmp = G;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->visit == 0)
        {
            DFStopologi(tmp);
        }
    }
    for (int i = 0; i < num; i++)
    {
        printf("%c\n", TOP[i]);
    }
}

// function define
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->header = e;
    (*p)->visit = 0;
    (*p)->next = NULL;
    (*p)->topo = 0;
    (*p)->prev = NULL;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->next = NULL;
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
void addEdge(node *v1, node *v2)
{
    edge *e, *tmp;
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    tmp = v1->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = e;
}
node *findNode(char name)
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
    printf("cannot find \n");
}
void DFStopologi(node *s)
{
    s->visit = 1;
    edge *tmp;
    tmp = s->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->to->visit != 1)
        {
            DFStopologi(tmp->to);
        }
        else if (tmp->to->topo == 0)
        {
            printf("Cycle");
        }
    }
    s->topo = 1;
    TOP[n - 1] = s->value;
    n--;
    return;
}