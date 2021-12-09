#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    edge *next;
    _node *from;
    _node *to;
} edge;

typedef struct node
{
    node *next;
    edge *header;
    int visited;
    int topped;
    char name;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *add);
void addEdge(node *v1, node *v2);
node *findNode(char name);
void DFS(node *s);
node *G;    
char *TOP;
int n, t;
int main()
{
    getNode(&G);
    int m;
    char v1, v2, s;
    scanf("%d", &n);
    t = n;
    TOP = (char *)malloc(sizeof(char) * (n + 1));
    TOP[0] = 1;
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &v1);
        getchar();
        node *p;
        getNode(&p);
        p->name = v1;
        addNode(p);
    }

    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        scanf("%c %c", &v1, &v2);
        getchar();
        addEdge(findNode(v1), findNode(v2));
    }

    node *tmp;
    tmp = G;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->visited == 0)
        {
            DFS(tmp);
        }
    }
    if (TOP[0] == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf(" %c", TOP[i]);
        }
    }
    else
    {
        printf("Cycled Graph");
    }

    return 0;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node *));
    (*p)->next = NULL;
    (*p)->visited = 0;
    (*p)->header = e;
    (*p)->topped = 0;
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
    while (tmp->next != NULL && tmp->next->name < add->name)
    {
        tmp = tmp->next;
    }
    add->next = tmp->next;
    tmp->next = add;
    return;
}
void addEdge(node *v1, node *v2)
{
    edge *tmp, *e;
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    tmp = v1->header;
    while (tmp->next != NULL && tmp->next->to->name < e->to->name)
    {
        tmp = tmp->next;
    }
    e->next = tmp->next;
    tmp->next = e;
}
node *findNode(char name)
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
    printf("cannot find\n");
}

void DFS(node *s)
{
    node *ntmp;
    edge *etmp;
    ntmp = s;
    etmp = ntmp->header;
    ntmp->visited = 1;
    // printf("%c\n", ntmp->name);
    while (etmp->next != NULL)
    {
        etmp = etmp->next;
        if (etmp->to->visited == 0)
        {
            DFS(etmp->to);
        }
        else if (etmp->to->topped == 0)
        {
            TOP[0] = 0;
        }
    }
    ntmp->topped = 1;
    TOP[t] = ntmp->name;
    t--;
    return;
}