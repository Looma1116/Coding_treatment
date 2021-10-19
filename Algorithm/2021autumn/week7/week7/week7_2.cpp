#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE
{
    int key;
    int height;
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
    (*w)->height = 0;
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

bool updateHeight(node* w) {
    int h;
    if (w->lChild->height < w->rChild->height) {
        h = w->rChild->height + 1;
    }
    else {
        h = w->lChild->height + 1;
    }
    if (h != w->height) {
        w->height = h;
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced(node* w) {
    return abs(w->lChild->height - w->rChild->height) < 2;
}

node* restructure(node** root, node* x, node* y, node* z) {
    node* a, * b, * c, * T0, * T1, * T2, * T3;
    if (z->key < y->key && y->key < x->key) {
        a = z;
        b = y;
        c = x;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = c->lChild;
        T3 = c->rChild;
    }
    else if(x->key < y->key && y->key < z->key) {
        a = x;
        b = y;
        c = z;
        T0 = a->lChild;
        T1 = a->rChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }
    else if (z->key < x->key && x->key < y->key) {
        a = z;
        b = x;
        c = y;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }
    else {
        a = y;
        b = x;
        c = z;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }
    if (isRoot(z)) {
        *root = b;
        b->parent = NULL;
    }
    else if(z->parent->lChild == z) {
        z->parent->lChild = b;
        b->parent = z->parent;
    }
    else {
        z->parent->rChild = b;
        b->parent = z->parent;
    }
    a->lChild = T0;
    a->rChild = T1;
    T0->parent = a;
    T1->parent = a;
    updateHeight(a);
    c->lChild = T2;
    c->rChild = T3;
    T2->parent = c;
    T3->parent = c;
    updateHeight(c);
    b->lChild = a;
    b->rChild = c;
    a->parent = b;
    c->parent = b;
    updateHeight(b);

    return b;
}

void searchAndFixAfterRemoval(node** root, node* z) {
    node* y, * x;
    if (z==NULL) {
        return;
    }
    while (updateHeight(z) && isBalanced(z)) {
        if (isRoot(z)) {
            return;
        }
        z = z->parent;
    }
    if (isBalanced(z)) {
        return;
    }
    if (z->lChild->height > z->rChild->height) {
        y = z->lChild;
    }
    else {
        y = z->rChild;
    }
    if (y->lChild->height > y->rChild->height) {
        x = y->lChild;
    }
    else if(y->lChild->height < y->rChild->height) {
        x = y->rChild;
    }
    else {
        if (z->lChild == y) {
            x = y->lChild;
        }
        else {
            x = y->rChild;
        }
    }
    node* b = restructure(root, x, y, z);
    if (isRoot(b)) {
        return;
    }
    searchAndFixAfterRemoval(root, b->parent);
}

void searchAndFixAfterInsertion(node** root, node* w) {
    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;
    if (isRoot(w)) {
        return;
    }
    node* z = w->parent;
    while (updateHeight(z) && isBalanced(z)) {
        if (isRoot(z)) {
            return;
        }
        z = z->parent;
    }
    if (isBalanced(z)) {
        return;
    }
    node* y, * x;
    if (z->lChild->height > z->rChild->height) {
        y = z->lChild;
    }
    else {
        y = z->rChild;
    }
    if (y->lChild->height > y->rChild->height) {
        x = y->lChild;
    }
    else {
        x = y->rChild;
    }
    restructure(root, x, y, z);
    return;
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

void insertItem(node** root, int key)
{
    node* Ex;
    Ex = treeSearch(*root, key);

    if (isInternal(Ex)) {
        return;
    }
    else {
        expandExternal(Ex);
        Ex->key = key;
        searchAndFixAfterInsertion(root, Ex);
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
    node* Ex, *zs,*y,*z;
    Ex = treeSearch(*root, key);

    if (isExternal(Ex)) {
        printf("X\n");
        return;
    }
    z = Ex->lChild;
    if (!isExternal(z)) {
        z = Ex->rChild;
    }
    if (isExternal(z)) { //case1
        printf("%d\n", Ex->key);
        zs = reduceExternal(root, z);

    }
    else //case2
    {
        printf("%d\n", Ex->key);
        y = inOrderSucc(Ex);
        z = y->lChild;
        Ex->key = y->key;
        zs = reduceExternal(root, z);

    }
    searchAndFixAfterRemoval(root, zs->parent);
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
            insertItem(&root, n);
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