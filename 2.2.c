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

//get length
int getLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//get i'th element
Status getElem(LinkList L, int i, Elemtype *e)
{
    int max_length = 0,j = 0;
    LinkList p = L->next;
    if(!L)
    {
        return ERROR;
    }

    max_length =getLength(L);
    if(i<1 || i>max_length)
    {
        return OVERFLOW;
    }

    for(j = 1 ; j < i; j++)
    {
        p = p->next;
    }

    *e = p->data;
    return OK;

}

Status InsertElem(LinkList *L, int i ,Elemtype e)
{
    int max_length = 0,j = 1;
    LinkList p = (*L)->next;
    LinkList q,new;
    q = *L;
    new = (LinkList)malloc(sizeof(LNode));
    new->data = e;
    new->next = NULL;

    if(!*L)
    {
        return ERROR;
    }

    max_length =getLength(*L);
    if(i<0 || i>max_length+1)
    {
        return OVERFLOW;
    }

    for(j = 1; j < i; j++)
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
    Elemtype e = 0;
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

    printf("getLength Function\n");
    printf("The List Length is: %d \n",getLength(L));

    printf("getElem Function\n");
    getElem(L,3,&e);
    printf("The 3rd number is: %d \n",e);

    printf("InsertFunction: 1st position\n");
    InsertElem(&L,1,100);
    TraverseList(L,visit);

    printf("\nInsertFunction: 5th position\n");
    InsertElem(&L,5,100);
    TraverseList(L,visit);

    printf("\nInsertFunction:last position\n");
    InsertElem(&L,getLength(L)+1,100);
    TraverseList(L,visit);

    return 1;
}
