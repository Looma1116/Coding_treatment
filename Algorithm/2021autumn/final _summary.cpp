#include <stdio.h>
#include <stdlib.h>

//---해쉬테이블---
//분리연쇄법
typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    int key;
    node *header = NULL;
} list;

void getNode(node **p, int value);
int hash(int value, int M);
void insertNode(node *header, int value);
void searchNode(list *A, int value, int M);
void deleteNode(list *A, int value, int M);
void printList(list *A, int M);
void mapping(list *A, int value, int M);
int main();

//선형조사법
int hash(int value, int M);
void insert(int A[], int value, int M);
void search(int A[], int value, int M);
int main();

//이중해싱
int hash(int value, int M);
int hash2(int value, int q);
void insert(int A[], int value, int M, int q);
void search(int A[], int value, int M, int q);
int main();

//---그래프---
// DFS
typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
} edge;
typedef struct node
{
    node *next;
    edge *header;
    int visited;
    int name;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *p);
void addEdge(node *ver1, node *ver2);
node *findNode(int name);
void DFS(node *start);
node *G;

// BFS
typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
} edge;

typedef struct node
{
    node *next;
    edge *header;
    int visited;
    int name;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *list, node *add);
void addEdge(node *v1, node *v2);
node *findNode(node *list, int name);
bool isEmpty(node *list);
void BFS(node *start);
void enQ(node *Q, node *add);
int deQ(node *Q);

node *G, *Q;

//---방향그래프---
//위상정렬 (진입차수)
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

//위상정렬 (DFS)
typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;

} edge;

typedef struct node
{
    node *next;
    node *prev;
    edge *header;
    char value;
    int visit;
    int topo;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *p);
void addEdge(node *v1, node *v2);
node *findNode(char name);
void DFStopologi(node *s);
node *G;
char *TOP;
int n, m;

//---최소신장트리---
// prim

typedef struct node _node;
typedef struct edge
{
    _node *from;
    _node *to;
    edge *next;
    int weight;
} edge;

typedef struct node
{
    int name;
    int distance;
    edge *header;
    node *next;
    node *prev;
} node;

void getNode(node **p);
void getEdge(edge **e);
void addNode(node *add);
void addEdge(node *v1, node *v2, int w);
node *removeMin();
node *findNode(int name);
bool isEmpty();
void replaceKey(node *p);
void Prim();

node *G;
int total;
// kruscal
int n, m, v1, v2, w, min = 9999, s1, s2;
int G[101][101], Sack[101];
