#include <stdio.h>
#include <stdlib.h>

typedef struct node _node; //구조체 선언
typedef struct edge        //구조체 선언
{
    _node *from;
    _node *to;
    int weight;
    edge *next;
} edge;

typedef struct node //구조체 선언
{
    node *next;
    int name;
    edge *header;
} node;

void getNode(node **p);                  //정점 할당
void getEdge(edge **e);                  //간선 할당
void addNode(node *add);                 //그래프에 정점 추가
void addEdge(node *v1, node *v2, int w); //정점에 인접간선 추가
node *findNode(int name);                //이름으로 그래프 정점 찾기
node *G;                                 //그래프 전역변수 선언
void freeAll(node *p);

int main()
{
    getNode(&G);
    int n, m, k, v1, v2, w;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        node *p;
        getNode(&p);
        p->name = i + 1;
        addNode(p);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        addEdge(findNode(v1), findNode(v2), w);
        addEdge(findNode(v2), findNode(v1), w);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &v1);
        if (findNode(v1) == NULL)
        {
            printf(" -1"); //정점 없으면 -1
        }
        else //인접 간선 돌면서 정점이랑 가중치 출력
        {
            edge *tmp;
            tmp = findNode(v1)->header;
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
                printf(" %d %d", tmp->to->name, tmp->weight);
            }
        }
        printf("\n");
    }
    freeAll(G->next);
    free(G->header);
    free(G);
    return 0;
}

void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->header = e;
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
void addEdge(node *v1, node *v2, int w)
{
    edge *e, *tmp;
    getEdge(&e);
    e->from = v1;
    e->to = v2;
    e->weight = w;
    tmp = v1->header;
    while (tmp->next != NULL && tmp->next->to->name < v2->name)
    {
        tmp = tmp->next;
    }
    e->next = tmp->next;
    tmp->next = e;
}
node *findNode(int name)
{
    node *tmp = G;
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
void freeAll(node *p)
{
    node *ntmp;
    edge *etmp;
    ntmp = p;
    while (ntmp->next->next != NULL)
    {
        freeAll(ntmp->next);
        ntmp = ntmp->next;
    }
    if (ntmp->next != NULL)
    {
        free(ntmp->next->header);
        free(ntmp->next);
    }
}