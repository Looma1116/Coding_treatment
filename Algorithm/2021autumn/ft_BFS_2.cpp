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
    char name;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *add);
void addEdge(node *v1, node *v2);
node *findNode(char name);
void enQ(node *add);
char deQ();
bool isEmpty();
void BFS(node *s);
node *G, *Q;
int main()
{
    getNode(&G);
    getNode(&Q);
    int n, m;
    char v1, v2, s;
    scanf("%d", &n);
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
        addEdge(findNode(v2), findNode(v1));
    }
    scanf("%c", &s);
    getchar();
    BFS(findNode(s));
    return 0;
}

void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->header = e;
    (*p)->next = NULL;
    (*p)->visited = 0;
}
void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->to = NULL;
    (*e)->next = NULL;
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
    while (tmp->next != NULL && tmp->next->to->name < v2->name)
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
    return NULL;
}
void enQ(node *add)
{
    node *addCopy, *tmp;
    getNode(&addCopy);
    addCopy->name = add->name;
    tmp = Q;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    addCopy->next = tmp->next;
    tmp->next = addCopy;
    add->visited = 1;
}
char deQ()
{
    char name;
    node *trash;
    name = Q->next->name;
    trash = Q->next;
    Q->next = Q->next->next;
    free(trash);
    printf(" %c", name);
    return name;
}
bool isEmpty()
{
    return Q->next == NULL;
}
void BFS(node *s)
{
    char name;
    node *ntmp;
    edge *etmp;
    enQ(s);
    while (!isEmpty())
    {
        name = deQ();
        ntmp = findNode(name);
        etmp = ntmp->header;
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            if (etmp->to->visited == 0)
            {
                enQ(etmp->to);
            }
        }
    }
}