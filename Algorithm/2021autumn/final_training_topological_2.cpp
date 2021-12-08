#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
} efge;
typedef struct node
{
    node *next;
    int indegree;
    char name;
    edge *header;
} node;

node *G, *Q;
int n, m, t;
char *TOP;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *add);
void addEdge(node *v1, node *v2);
node *findNode(char name);
void enQ(node *add);
char deQ();
bool isEmpty();
void TOPO();

int main()
{
    char v1, v2;
    getNode(&G);
    getNode(&Q);
    scanf("%d", &n);
    getchar();
    TOP = (char *)malloc(sizeof(char) * (n + 1));
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
    t = 1;
    TOPO();
    if (TOP[0] == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%c\n", TOP[i]);
        }
    }
    else
    {
        printf("0");
    }
    return 0;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->header = e;
    (*p)->indegree = 0;
    (*p)->next = NULL;
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
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = add;
}
void addEdge(node *v1, node *v2)
{
    edge *e, *tmp;
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    v2->indegree++;
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
        if (tmp->name == name)
        {
            return tmp;
        }
    }
    printf("cannot find");
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
    tmp->next = addCopy;
}
char deQ()
{
    char name;
    if (isEmpty())
    {
        printf("empty");
        return '0';
    }
    name = Q->next->name;
    Q->next = Q->next->next;
    return name;
}
bool isEmpty()
{
    return (Q->next == NULL);
}

void TOPO()
{
    node *ntmp;
    edge *etmp;
    char removed;
    ntmp = G;
    while (ntmp->next != NULL)
    {
        ntmp = ntmp->next;
        if (ntmp->indegree == 0)
        {
            enQ(ntmp);
            ntmp->indegree--;
        }
    }
    while (!isEmpty())
    {
        removed = deQ();
        TOP[t] = removed;
        t++;
        ntmp = findNode(removed);
        etmp = ntmp->header;
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            etmp->to->indegree--;
            if (etmp->to->indegree == 0)
            {
                enQ(etmp->to);
            }
        }
    }
    if (t <= n)
    {
        TOP[0] = 0;
    }
    else
    {
        TOP[0] = 1;
    }
}