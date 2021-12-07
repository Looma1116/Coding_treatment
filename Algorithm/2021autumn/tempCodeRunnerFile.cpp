#include <stdio.h>
#include <stdlib.h>

typedef struct vertex vertex_;
typedef struct edge
{
    int weight;
    vertex_ *from;
    vertex_ *to;
    edge *next;
} edge;

typedef struct vertex
{
    int value;
    edge *header;
    int distance;
    vertex *prev;
    vertex *next;
} vertex;

void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->next = NULL;
}
void getVertex(vertex **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (vertex *)malloc(sizeof(vertex));
    (*p)->distance = 20000;

    (*p)->header = e;
    (*p)->next = NULL;
    (*p)->prev = NULL;
}

void addVertex(vertex **header, vertex *add)
{
    vertex *tmp;
    tmp = (*header);
    if ((*header)->next == NULL)
    {
        (*header)->next = add;
        add->prev = (*header);
        return;
    }
    while (tmp->next != NULL && tmp->next->distance <= add->distance)
    {
        if (tmp->next->distance == add->distance && tmp->next->value > add->value)
        {
            break;
        }
        tmp = tmp->next;
    }
    if (tmp->next != NULL)
    {
        tmp->next->prev = add;
    }
    add->next = tmp->next;
    tmp->next = add;
    add->prev = tmp;
    return;
}

void addResult(vertex **header, vertex *add)
{
    vertex *tmp;
    tmp = (*header);
    if ((*header)->next == NULL)
    {
        (*header)->next = add;
        add->prev = (*header);
        return;
    }
    while (tmp->next != NULL && tmp->next->value <= add->value)
    {
        tmp = tmp->next;
    }
    if (tmp->next != NULL)
    {
        tmp->next->prev = add;
    }
    add->next = tmp->next;
    tmp->next = add;
    add->prev = tmp;
    return;
}

int isEmpty(vertex *header)
{
    if (header->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

vertex *removeMin(vertex **header)
{
    vertex *tmp = (*header)->next;
    (*header)->next = (*header)->next->next;
    if ((*header)->next != NULL)
    {
        (*header)->next->prev = (*header);
    }
    return tmp;
}

void replaceKey(vertex **node)
{
    vertex *tmp;
    tmp = (*node)->next;
    if (tmp != NULL && (*node)->distance > tmp->distance)
    {
        (*node)->prev->next = tmp;
        tmp->prev = (*node)->prev;
        while (tmp->next->distance < (*node)->distance)
        {
            tmp = tmp->next;
        }
        tmp->next->prev = (*node);
        (*node)->next = tmp->next;
        tmp->next = (*node);
        (*node)->prev = tmp;
        return;
    }
    tmp = (*node)->prev;
    if (tmp != NULL && (*node)->distance < tmp->distance)
    {
        if ((*node)->next != NULL)
        {
            (*node)->next->prev = tmp;
        }
        tmp->next = (*node)->next;
        while (tmp->prev->distance > (*node)->distance)
        {
            tmp = tmp->prev;
        }
        tmp->prev->next = (*node);
        (*node)->prev = tmp->prev;
        tmp->prev = (*node);
        (*node)->next = tmp;
    }
}

vertex *findVertex(vertex **header, int num)
{
    vertex *tmp = (*header);
    while (tmp != NULL)
    {
        if (tmp->value == num)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void addEdge(vertex **header, int n1, int n2, int weight)
{
    vertex *ver1, *ver2;
    edge *e, *tmp;
    ver1 = findVertex(header, n1);
    ver2 = findVertex(header, n2);
    getEdge(&e);
    e->weight = weight;
    e->from = ver1;
    e->to = ver2;
    tmp = ver1->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = e;
    getEdge(&e);
    e->weight = weight;
    e->from = ver2;
    e->to = ver1;
    tmp = ver2->header;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = e;
}

void DSP(vertex *Qheader, vertex *s)
{
    edge *tmp;
    vertex *u, *z, *result, *put;

    getVertex(&result);
    result->distance = -1;

    s->distance = 0;
    replaceKey(&s);
    removeMin(&Qheader);
    tmp = s->header->next;
    while (tmp != NULL)
    {
        tmp->to->distance = tmp->weight;
        replaceKey(&(tmp->to));
        tmp = tmp->next;
    }
    while (isEmpty(Qheader) != 1)
    {
        u = removeMin(&Qheader);
        put = u;
        put->next = NULL;
        put->prev = NULL;
        addResult(&result, put);
        // printf("%d %d\n", u->value, u->distance);
        tmp = u->header->next;
        while (tmp != NULL)
        {
            z = tmp->to;
            if (findVertex(&Qheader, z->value) != NULL)
            {
                if (z->distance > u->distance + tmp->weight)
                {
                    z->distance = u->distance + tmp->weight;
                    replaceKey(&z);
                }
            }
            tmp = tmp->next;
        }
    }
    u = result->next;
    while (u != NULL)
    {
        if (u->distance < 20000)
        {
            printf("%d %d\n", u->value, u->distance);
        }
        u = u->next;
    }
    return;
}

int main()
{
    vertex *Qheader, *ver;
    int n, m, s, i, n1, n2, w;

    scanf("%d %d %d", &n, &m, &s);
    getVertex(&Qheader);
    Qheader->distance = -1;
    for (i = 1; i <= n; i++)
    {
        getVertex(&ver);
        ver->value = i;
        addVertex(&Qheader, ver);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &n1, &n2, &w);
        addEdge(&Qheader, n1, n2, w);
    }
    DSP(Qheader, findVertex(&Qheader, s));
    return 0;
}