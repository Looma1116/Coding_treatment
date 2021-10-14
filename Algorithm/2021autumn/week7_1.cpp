#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int key;
    NODE *parent;
    NODE *lChild;
    NODE *rChild;
} node;

void getNODE(node **w)
{
    *w = (node *)malloc(sizeof(node));
    (*w)->lChild = NULL;
    (*w)->rChild = NULL;
    (*w)->parent = NULL;
}

bool isRoot(node *w)
{
    if (w->parent == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isExternal(node *w)
{
    if (w->lChild == NULL && w->rChild == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isInternal(node *w)
{
    if (w->lChild != NULL || w->rChild != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

node *sibling(node *w)
{
    if (isRoot(w))
    {
        printf("root has no sibling\n");
        return NULL;
    }
    if ((w->parent)->lChild == w)
    {
        return ((w->parent)->rChild);
    }
    else
    {
        return ((w->parent)->lChild);
    }
}

node *inOrderSucc(node *w)
{
    w = w->rChild;
    if (isExternal(w))
    {
        printf("no inorder successor");
        return NULL;
    }
    while (isInternal(w->lChild))
    {
        w = w->lChild;
    }
    return w;
}

node *reduceExternal(node *z)
{
    node *w, *zs;
    w = z->parent;
    zs = sibling(z);
    if (isRoot(w))
    {
        w = zs;
        zs->parent = NULL;
    }
    else
    {
        node *g = w->parent;
        zs->parent = g;
        if (g->lChild == w)
        {
            g->lChild = zs;
        }
        else
        {
            g->rChild = zs;
        }
    }
}

void insertItem(node *root, int key)
{
    node *Ex;
    Ex = root;
    if (root == NULL)
    {
        getNODE(&root);
        root->key = key;
    }
    else
    {
        while (isInternal(Ex))
        {
            if (Ex->key > key)
            {
                Ex = Ex->lChild;
            }
            else
            {
                Ex = Ex->rChild;
            }
        }
        if (Ex->key > key)
        {
            node *child;
            getNODE(&child);
            child->key = key;
            Ex->lChild = child;
            child->parent = Ex;
        }
    }
}

int main()
{
    node *root = NULL;
    int n, i;
    char c;

    while (c != 'c')
    {
        scanf("%c", &c);
        if (c == 'i')
        {
        }
        else if (c == 'd')
        {
        }
        else if (c == 's')
        {
        }
        else if (c == 'p')
        {
        }
        else if (c == 'q')
        {
        }
    }
}