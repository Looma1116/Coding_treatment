#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct vertex vertex_;

typedef struct ad
{
    int weight;
    vertex_ *to;
    ad *next;
} ad;

typedef struct vertex
{
    int visit;
    ad *header;
    int value;
    vertex *next;
} vertex;

void getAd(ad **edge)
{
    *edge = (ad *)malloc(sizeof(ad));
    (*edge)->next = NULL;
}

void getVertex(vertex **a, int value)
{
    *a = (vertex *)malloc(sizeof(vertex));
    (*a)->value = value;
    (*a)->visit = 0;
    (*a)->next = NULL;

    ad *edge;
    getAd(&edge);
    edge->weight = 0;
    (*a)->header = edge;
}
void addEdge(vertex *a, vertex *b, int weight)
{
    ad *edge, *tmp;
    getAd(&tmp);
    tmp = a->header;

    while (tmp->next != NULL && tmp->next->to->value <= b->value)
    {
        tmp = tmp->next;
        if (tmp->to->value == b->value)
        {
            tmp->weight = weight;
            return;
        }
    }
    getAd(&edge);
    edge->weight = weight;
    edge->to = b;
    edge->next = tmp->next;
    tmp->next = edge;
    return;
}

void deleteEdge(vertex *a, vertex *b)
{
    ad *edge, *tmp;
    getAd(&tmp);
    tmp = a->header;
    if (tmp->next == NULL)
    {
        printf("-1\n");
        return;
    }
    while (tmp->next->to != b)
    {
        tmp = tmp->next;
        if (tmp == NULL)
        {
            printf("-1\n");
            return;
        }
    }
    tmp->next = tmp->next->next;
    if (a == b)
    {
        return;
    }
    tmp = b->header;
    while (tmp->next->to != a)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;

    return;
}

void addVertex(vertex **a)
{
    vertex *tmp, *baby;
    tmp = (*a);
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    getVertex(&baby, tmp->value + 1);
    tmp->next = baby;
}
void DFS(vertex *a)
{
    a->visit = 1;
    printf("%d\n", a->value);
    vertex *tmp = a;
    ad *finder;
    finder = tmp->header->next;
    while (tmp != NULL)
    {
        while (finder->to->visit == 1)
        {
            if (finder->next == NULL)
            {
                return;
            }
            finder = finder->next;
        }
        tmp = finder->to;
        DFS(tmp);
    }
    return;
}

int main()
{
    char command;
    int n, m, s, ver1, ver2;
    vertex *a, *x, *y;
    getVertex(&a, 1);

    scanf("%d %d", &n, &m, &s);
    for (int i = 1; i < n; i++)
    {
        addVertex(&a);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &ver1, &ver2);
        x = a;
        y = a;
        x = a;
        for (int i = 1; i < ver1; i++)
        {
            x = x->next;
        }
        for (int i = 1; i < ver2; i++)
        {
            y = y->next;
        }
        addEdge(x, y, 1);
        addEdge(y, x, 1);
    }
    x = a;
    for (int i = 1; i < s; i++)
    {
        x = x->next;
    }
    DFS(x);
    return 0;
}