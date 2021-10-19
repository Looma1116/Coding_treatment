#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    int key;
    struct NODE* parent;
    struct NODE* lChild;
    struct NODE* rChild;
} node;

void getNODE(node** w)
{
    *w = (node*)malloc(sizeof(node));
    (*w)->lChild = NULL;
    (*w)->rChild = NULL;
    (*w)->parent = NULL;
}

bool isRoot(node* w)
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

bool isExternal(node* w)
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

bool isInternal(node* w)
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

node* treeSearch(node* root, int key) {
    if (isExternal(root)) {
        return root;
    }
    if (root->key == key) {
        return root;
    }
    else if (key < root->key) {
        return treeSearch(root->lChild, key);
    }
    else {
        return treeSearch(root->rChild, key);
    }
}

void expandExternal(node* z) {
    node* l;
    node* r;
    getNODE(&l);
    getNODE(&r);
    l->parent = z;
    r->parent = z;
    z->lChild = l;
    z->rChild = r;
    return;
}
node* sibling(node* w)
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

node* inOrderSucc(node* w)
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

void insertItem(node* root, int key)
{
    node* Ex;
    Ex = treeSearch(root, key);

    if (isInternal(Ex)) {
        return;
    }
    else {
        expandExternal(Ex);
        Ex->key = key;
        return;
    }
}

node* reduceExternal(node** root, node* z)
{
    node* w, * zs;
    w = z->parent;
    zs = sibling(z);
    if (isRoot(w))
    {
        *root = zs;
        zs->parent = NULL;
    }
    else
    {
        node* g = w->parent;
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
    free(z);
    free(w);
    return zs;
}



void removeElement(node** root, int key)
{
    node* Ex;
    Ex = treeSearch(*root, key);

    if (isExternal(Ex)) {
        printf("X\n");
        return;
    }
    node* z = Ex->lChild;
    if (!isExternal(z)) {
        z = Ex->rChild;
    }
    if (isExternal(z)) { //case1
        printf("%d\n", Ex->key);
        reduceExternal(root, z);
        
    }
    else //case2
    {
        printf("%d\n", Ex->key);
        node* y = inOrderSucc(Ex);
        node* z = y->lChild;
        Ex->key = y->key;
        reduceExternal(root, z);
        
    }

}

void findElement(node* root, int key)
{
    node* Ex;
    Ex = treeSearch(root, key);
    if (isExternal(Ex))
    {
        printf("X\n");
        return;
    }
    else
    {
        printf("%d\n", Ex->key);
        return;
    }
}

void preOrder(node* root)
{
    if (isExternal(root)) {
        return;
    }
    else {
        printf(" %d", root->key);
    }
    if (!isExternal(root->lChild)) {
        preOrder(root->lChild);
    }
    if (!isExternal(root->rChild)) {
        preOrder(root->rChild);
    }
    return;
}
int main()
{
    node* root = NULL;
    getNODE(&root);
    int n;
    char c;

    while (1)
    {
        scanf("%c", &c);
        if (c == 'i')
        {
            scanf("%d", &n);
            getchar();
            insertItem(root, n);
        }
        else if (c == 'd')
        {
            scanf("%d", &n);
            getchar();
            removeElement(&root, n);
        }
        else if (c == 's')
        {
            scanf("%d", &n);
            getchar();
            findElement(root, n);
        }
        else if (c == 'p')
        {
            preOrder(root);
            printf("\n");
        }
        else if (c == 'q')
        {
            break;
        }
    }
    return 0;
}