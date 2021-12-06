#include <stdio.h>
#include <stdlib.h>

/**
그래프는 node* Gheader를 시작으로 하는 연결리스트
알고리즘 수행에 필요한 Queue는 해당 노드의 이름을 복사하는 형태로.
왜냐하면 Queue도 연결리스트로 구현할 때 노드를 가져다 넣으면 얕은 복사가 돼서 next가 꼬일 수 있어서.
대신 deQueue를 해서 받은 name으로 node* findNode(node* Gheader, char name) 함수를 통해 그래프 리스트에서 노드를 찾음.
**/

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
} edge;

typedef struct node
{
    char value;
    node *next;
    edge *header;
    int indegree;
} node;

char *TopOrder;
int n, t;

void getEdge(edge **);
void getNode(node **);
bool isEmpty(node *);
void addNode(node *, node *);
void addEdge(node *, node *);
node *findNode(node *, char);
void enqueue(node *Qheader, node *add);
char dequeue(node *Qheader);
void topological(node *Gheader, node *Qheader);

int main()
{
    int m;
    char name, name2;
    node *G, *Q, *tmp;
    getNode(&G);
    getNode(&Q);
    G->indegree = -1;
    scanf("%d", &n);
    getchar();
    TopOrder = (char *)malloc(sizeof(char) * (n + 1));
    t = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &name);
        getchar();
        getNode(&tmp);
        tmp->value = name;
        addNode(G, tmp);
    }
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        scanf("%c %c", &name, &name2);
        getchar();
        addEdge(findNode(G, name), findNode(G, name2));
    }
    topological(G, Q);
    if (TopOrder[0] == 1)
    {
        for (int i = 1; i < t; i++)
        {
            printf(" %c", TopOrder[i]);
        }
    }
    else
    {
        printf("0");
    }
    return 0;
}

void getEdge(edge **e)
{
    (*e) = (edge *)malloc(sizeof(edge));
    (*e)->from = NULL;
    (*e)->to = NULL;
    (*e)->next = NULL;
}
void getNode(node **p)
{
    edge *e;
    getEdge(&e);
    (*p) = (node *)malloc(sizeof(node));
    (*p)->next = NULL;
    (*p)->header = e;
    (*p)->indegree = 0;
}

bool isEmpty(node *Qheader)
{
    return (Qheader->next == NULL);
}
void addNode(node *Gheader, node *add)
{
    node *tmp;
    tmp = Gheader;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = add;
}
void addEdge(node *from, node *to)
{
    edge *e, *tmp;
    getEdge(&e);
    e->from = from;
    e->to = to;

    tmp = from->header;
    e->next = tmp->next;
    tmp->next = e;
    to->indegree++;
}

void enqueue(node *Qheader, node *add)
{
    node *tmp, *addCopy;
    getNode(&addCopy);
    addCopy->value = add->value;
    tmp = Qheader;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = addCopy;
}

char dequeue(node *Qheader)
{
    node *tmp;
    char name;
    tmp = Qheader->next;
    Qheader->next = Qheader->next->next;
    name = tmp->value;
    free(tmp);
    return name;
}

node *findNode(node *Gheader, char name)
{
    node *tmp;
    tmp = Gheader;
    while (tmp != NULL)
    {
        if (tmp->value == name)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void topological(node *Gheader, node *Qheader)
{
    char uname;
    node *tmp;
    edge *etmp;
    tmp = Gheader;
    //처음 진입차수 0인 노트 찾기
    while (tmp != NULL)
    {
        if (tmp->indegree == 0)
        {
            tmp->indegree--;       //해당 노드의 진입차수는 이제 -1이 된다.
            enqueue(Qheader, tmp); // Q리스트에 해당 노드의 이름 복사해서 넣기. (깊은 복사)
        }
        tmp = tmp->next;
    }
    // Queue에 처음 노드들 넣은 상태에서 이제 시작.
    while (!isEmpty(Qheader))
    {
        //진입 차수 0인 노드 하나씩 빼기
        uname = dequeue(Qheader);       // char 리턴
        tmp = findNode(Gheader, uname); // char로 G 리스트에서 해당 노드 찾기
        if (tmp == NULL)                //리스트에 없으면 리턴
        {
            printf("dequeue NULL\n");
            return;
        }
        TopOrder[t] = uname; //위상정렬 char 배열에 해당 노드 이름 넣기
        t++;
        etmp = tmp->header->next; //그 노드의 자식들
        while (etmp != NULL)
        {
            etmp->to->indegree--; //진입차수를 1식 줄인다.
            etmp = etmp->next;
        }

        tmp = Gheader; //이제 다시 그래프에서 진입차수가 0인 녀석들을 잡아볼까?
        while (tmp != NULL)
        {
            if (tmp->indegree == 0)
            {
                tmp->indegree--;
                enqueue(Qheader, tmp); // Queue는 not empty라서 while문은 살아있다.
            }
            tmp = tmp->next;
        }
    }

    if (t <= n) //위상 순위가 안매겨진 노드가 있다는건 싸이클이 있다는 것.
    {
        TopOrder[0] = 0;
    }
    else
    {
        TopOrder[0] = 1;
    }
}