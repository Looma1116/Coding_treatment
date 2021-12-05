#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    node *next;
    int key;
} node;

int hash(int, int);
void getNode(node **);
void addNode(node *, node *);
void searchNode(node *, int);
void deleteNode(node *, int);
void printNode(node *);
int main()
{
    int M, key, *table;
    node **list;
    char c;
    scanf("%d", &M);
    getchar();
    list = (node **)malloc(sizeof(node *) * M);
    for (int i = 0; i < M; i++)
    {
        getNode(&list[i]);
    }

    scanf("%c", &c);
    while (c != 'e')
    {
        if (c == 'i')
        {
            scanf("%d", &key);
            node *p;
            getNode(&p);
            p->key = key;
            addNode(list[hash(key, M)], p);
        }
        if (c == 's')
        {
            scanf("%d", &key);
            searchNode(list[hash(key, M)], key);
        }
        if (c == 'd')
        {
            scanf("%d", &key);
            deleteNode(list[hash(key, M)], key);
        }
        if (c == 'p')
        {
            for (int i = 0; i < M; i++)
            {
                printNode(list[i]);
            }
        }
        getchar();
        scanf("%c", &c);
    }
    return 0;
}
int hash(int x, int M)
{
    return (x % M);
}

void getNode(node **p)
{
    (*p) = (node *)malloc(sizeof(node));
    (*p)->next = NULL;
}

void addNode(node *head, node *add)
{
    if (head->next == NULL)
    {
        head->next = add;
        return;
    }
    add->next = head->next;
    head->next = add;
    return;
}

void searchNode(node *head, int key)
{
    node *tmp = head;
    int i = 0;
    while (tmp != NULL)
    {
        if (tmp->key == key)
        {
            printf("%d\n", i);
            return;
        }
        tmp = tmp->next;
        i++;
    }
    printf("0\n");
    return;
}

void deleteNode(node *head, int key)
{
    node *tmp = head->next;
    int i = 1;
    while (tmp != NULL)
    {
        if (tmp->next->key == key)
        {
            printf("%d\n", i);
            tmp->next = tmp->next->next;
            return;
        }
        i++;
        tmp = tmp->next;
    }
    printf("0\n");
    return;
}

void printNode(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf(" %d", tmp->key);
        tmp = tmp->next;
    }
}