#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct NODE
{
    int key;
    struct NODE *parent;
    struct NODE *lChild;
    struct NODE *rChild;
} node;

void getNode(node **p)
{
    (*p) = (node *)malloc(sizeof(node));
    (*p)->lChild = NULL;
    (*p)->rChild = NULL;
}

bool isExternal(node *A)
{
    if (A->lChild == NULL && A->rChild == NULL)
    {
        return true;
    }
    else
        return false;
}

bool isInternal(node *A)
{
    if (A->lChild != NULL || A->rChild != NULL)
    {
        return true;
    }
    else
        false;
}

node *treeSearch(node **A, int key)
{
    if (isExternal(*A))
    {
        return (*A);
    }
    if ((*A)->key < key)
    {
        treeSearch(&(*A)->lChild, key);
    }
    if ((*A)->key == key)
    {
        return (*A);
    }
    if ((*A)->key > key)
    {
        treeSearch(&(*A)->rChild, key);
    }
}
void insertNode(node **A, int key)
{
    node *q, *ex;
    getNode(&q);
    q->key = key;
    if ((*A) == NULL)
    {
        (*A) = q;
        return;
    }
    ex = treeSearch(A, key);
    ex = q;
    return;
}

void postOrder(node **A)
{
    if (!isExternal(*A))
    {
        postOrder(&(*A)->lChild);
        postOrder(&(*A)->rChild);
        printf(" %d", (*A)->key);
    }
}
int main()
{

    char command;
    int key;
    while (1)
    {
        node *A;
        scanf("%c", &command);
        if (command == 'i')
        {
            scanf("%d", &key);
            insertNode(&A, key);
            getchar();
        }
        if (command == 'p')
        {
            postOrder(&A);
        }
    }
}