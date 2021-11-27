#include <stdio.h>
#include <stdlib.h>
 
int total=0, num;
int Q[101]={-1};

typedef struct node node_;

typedef struct edge{
    node_* from;
    node_* to;
    int weight;
    edge* next;
}edge;

typedef struct node{
    edge* header = NULL;
    int value;
}node;

int removeMin(){
    int i = 1;
    while(Q[i] == -1 || Q[i] == -2){
        i++;
    }
    int min = Q[i];
    int index = i;
    for(i=1;i<=num;i++){
        if(Q[i]<min && Q[i] != -1 &&Q[i] !=-2){
            min = Q[i];
            index = i;
        }
    }

    total += min;
    Q[index] = -2;
    printf(" %d", index);
    return index; 
}

int isEmpty(){
    int i=0, empty=1;
    for(i=1;i<=num;i++){
        if(Q[i] != -2){
            empty = 0;
        }
    }
    return empty;
}
void getEdge(edge** e, int weight, node* from, node* to){
    (*e) = (edge*)malloc(sizeof(edge));
    (*e)->weight = weight;
    (*e)->from = from;
    (*e)->to = to;
    (*e)->next = NULL;
}

void addEdge(node* p, edge* e){
    edge* tmp;
    tmp = p->header;
    if(p->header == NULL){
        p->header = e;
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = e;
}

void prim(node** G){
    edge* tmp;
    node* s;
    int u,z;

    s = G[1];
    Q[1]=0;
    while(isEmpty() == 0){
        u = removeMin();
        tmp = G[u]->header;
        while(tmp != NULL){
            z = tmp->to->value;
            if(Q[z]!=-2 && (Q[z]== -1 || tmp->weight < Q[z])){
                Q[z] = tmp->weight;
            }
            tmp = tmp->next;
        }
    }
}

int main(){
    node** G;
    edge* e;
    int n, m, v1, v2, w;

    scanf("%d %d", &n,&m);
    num = n;
    G = (node**)malloc(sizeof(node*)*n);
    for(int i = 1; i<= n;i++){
        G[i] = (node*)malloc(sizeof(node));
        G[i]->value = i;
        G[i]->header = NULL;
        Q[i] = -1;
    }
    for(int i = 0 ; i < m; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        edge* e;
        getEdge(&e, w, G[v1], G[v2]);
        addEdge(G[v1],e);
        getEdge(&e, w, G[v2], G[v1]);
        addEdge(G[v2],e);
    }
    prim(G);
    printf("\n%d",total);



    return 0;
}
