#include <stdio.h>
#include <stdlib.h>

typedef struct node _node;
typedef struct edge
{
    _node from;
    _node to;
    edge *next;

} edge;

typedef struct node
{
    node *next;
    node *prev;
    edge *header;
    char value;
    int indegree;
};
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
}
