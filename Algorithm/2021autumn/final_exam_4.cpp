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
    node *prev;
    int name;
    edge *header;
    int distance;
    int visited;
} node;

void getNode(node **p);                  //정점 할당
void getEdge(edge **e);                  //간선 할당
void addNode(node *add);                 //그래프에 정점 추가
void addEdge(node *v1, node *v2, int w); //정점에 인접간선 추가
node *findNode(int name);                //이름으로 그래프 정점 찾기
void Prim();
bool isEmpty();
node *removeMin();
void replaceKey(node *p);
node *G; //그래프(우선순위 큐) 전역변수 선언
int total;
int main()
{
    total = 0;
    getNode(&G);
    int n, m, k, v1, v2, w;
    scanf("%d %d", &n, &m);
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
        addEdge(findNode(v1), findNode(v2), w); //무방향가중간선
        addEdge(findNode(v2), findNode(v1), w);
    }
    Prim();
    printf("%d", total);

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
    (*p)->prev = NULL;
    (*p)->distance = 9999999;
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
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    add->prev = tmp;
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
    while (tmp->next != NULL && tmp->next->to->name < v2->name) //인접리스트 목적지 이름 오름차순으로
    {
        tmp = tmp->next;
    }
    e->next = tmp->next;
    tmp->next = e;
}
node *findNode(int name) //그래프에서 노드 찾기
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
bool isEmpty()
{
    return G->next == NULL;
}
node *removeMin() //그래프가 우선순위큐이기 때문에 헤더 바로 다음거 리턴
{
    node *tmp;
    tmp = G->next;
    G->next = tmp->next;
    if (tmp->next != NULL)
    {
        tmp->next->prev = G;
    }
    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->visited = 1;
    total += tmp->distance;
    return tmp;
}
void replaceKey(node *p)
{
    node *tmp;
    while (p->prev != G && p->prev->distance > p->distance) //만약 해당 노드거리가 이전 노드의 거리보다 작으면
    {
        tmp = p->prev;
        tmp->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = tmp;
        }
        p->next = tmp;
        tmp->prev->next = p;
        p->prev = tmp->prev;
        tmp->prev = p;
        //앞으로 이동
    }
    while (p->next != NULL && p->next->distance < p->distance) //반대로 크면
    {
        tmp = p->next;
        p->prev->next = tmp;
        tmp->prev = p->prev;
        if (tmp->next != NULL)
        {
            tmp->next->prev = p;
        }
        p->next = tmp->next;
        tmp->next = p;
        p->prev = tmp;
        // 뒤로 이동
    }
}
void Prim()
{
    node *ntmp;
    edge *etmp;

    G->next->distance = 0;
    while (!isEmpty())
    {
        ntmp = removeMin();  //큐에서 제일 작은거 꺼내서
        etmp = ntmp->header; //해당 인접 정점 방문해서
        while (etmp->next != NULL)
        {
            etmp = etmp->next;
            if (etmp->to->visited == 0 && etmp->to->distance > etmp->weight)
            { // distance랑 가중치 비교하여 업데이트
                etmp->to->distance = etmp->weight;
                replaceKey(etmp->to); //그래프를 우선순위로
            }
        }
        free(ntmp);
    }
}