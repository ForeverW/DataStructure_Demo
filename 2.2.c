//LinkList demo
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Elmetype;
typedef int Status;

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
}LNode,LinkList;

//Init LNode
void InitList(LinkList *L)
{
    *L = (LinkList) malloc(sizeof(LNode));
    if(!L)
    {
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
}

void DestroyList(LinkList *L)
{
    while(*L)
    {
        LinkList temp;
        temp = *L->next;
        free(*L);
        *L = temp;
}

//Insert from head
Status InsertHead(LinkList *L, Elemtype e)
{
    LinkList new, p;
    p = (*L)->next;
    new = (LinkList) malloc(sizeof(LNode));
    if(!new)
    {
        return OVERFLOW;
    }
    new->data = e;
    new->next = p;
    p ->next = NULL;
    p = new;
    return OK;
}

void visit(Elemtype e)
{
    printf("%d", e);
}

void TraverseList(LinkList L, void(*visit)(Elemtype))
{
    LinkList p = L->next;
    while(p)
    {
        visit(p->data);
    }
}

int main()
{
    LinkList L;
    InitList(&L);
    Elemtype e;
    int i;
    if(L)
    {
        printf("init success\n");
    }

    for(i = 0; i<10; i++)
    {
        InsertHead(&L,i);
    }

    TraverseList(L,visit);
    return 1;
}
