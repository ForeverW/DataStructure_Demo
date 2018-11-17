//LinkList demo
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

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
        temp = (*L)->next;
        free(*L);
        *L = temp;
    }
}

//Create Reverse List : CreateList_Rev
Status CreateList_Rev(LinkList *L, Elemtype e)
{
    LinkList new;

    new = (LinkList) malloc(sizeof(LNode));
    new->next = NULL;
    if(!new)
    {
        return OVERFLOW;
    }
    new->data = e;
    new->next = (*L)->next;
    (*L)->next = new;
    return OK;
}

Status CreateList_Norm(LinkList *L, Elemtype e)
{
    LinkList new,p,q;

    p = (*L)->next;
    q = p;

    new = (LinkList)malloc(sizeof(LNode));
    if(!new)
    {
        return OVERFLOW;
    }
    new->data = e;

    while(p)
    {
        q = p;
        p = p->next;
    }
    q->next = new;
    new->next = p;
    return OK;
}

void visit(Elemtype e)
{
    printf("%d ", e);
}

void TraverseList(LinkList L, void(*visit)(Elemtype))
{
    LinkList p = L->next;

    if(!p)
    {
        printf("!p\n");
    }
    while(p)
    {
        visit(p->data);
        p = p->next;
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

    //Reverse Create List
    printf("Reverse Mode\n");
    for(i = 0; i<10; i++)
    {
        CreateList_Rev(&L,i);
    }
    printf("insert finish\n");

    TraverseList(L,visit);

    printf("\nNormal Mode\n");
    for(i = 0; i<10; i++)
    {
        CreateList_Norm(&L,i);
    }
    printf("insert finish\n");

    TraverseList(L,visit);


    return 1;
}
