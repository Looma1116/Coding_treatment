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

int main()
{
    char command;
    int n, m, s, ver1, ver2;
    vertex *a, *b, *c, *d, *e, *f, *tmp, *tmp2;

    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &ver1, &ver2);
    }
    scanf("%c", &command);
    if (command == 'a')
    {
        scanf("%d", &num);
        if (num > 6)
        {
            printf("-1\n");
            continue;
        }
        tmp = a;
        for (int i = 1; i < num; i++)
        {
            tmp = tmp->next;
        }
        ad *edge = tmp->header->next;
        if (edge == NULL)
        {
            printf("-1\n");
            continue;
        }
        while (edge != NULL)
        {
            printf(" %d %d", edge->to->value, edge->weight);
            edge = edge->next;
        }
        printf("\n");
    }

    return 0;
}