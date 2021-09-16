#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    int data;
    NODE* left;
    NODE* right;
}node;

void explorer(node* root, char* command){
    node* E= root;
    for (int i = 0; i <= strlen(command); i++){
        printf(" %d", E->data);
        if(command[i] == 'L'){
            E = E->left;
        }
        else if(command[i] == 'R'){
            E = E->right;
        }
    }
    printf("\n");
}

void getNode(node** p){
    *p = (node*)malloc(sizeof(node));
    (*p)->left = NULL;
    (*p)->right = NULL;
}

node* g;
node* findID(node* a, int id){
    if (a != NULL) {
        if(a->data == id){
			return (g = a);
		}
		findID(a->left, id);
		findID(a->right, id);	
    }
}

int main(){
    node *Root;
    int n, s, d,l,r;
    char command[101];
    getNode(&Root);
    scanf("%d", &n);
    if(n<=0){
        return 0;
    }

    for (int i = 0; i < n;i++){
        scanf("%d %d %d", &d, &l, &r);
        node *L, *R, *E;
        getNode(&L);
        getNode(&R);
        getNode(&E);
        L->data = l;
        R->data = r;
        if(i==0){
            Root->data = d;
            Root->left = L;
            Root->right = R;
        }
        else{
            findID(Root, d);
            g ->left = L;
            g->right = R;
        }

    }
    scanf("%d", &n);
    for (int i = 0; i < n ; i++) {
		scanf("%s", command);
        explorer(Root, command);
    }
    return 0;
}