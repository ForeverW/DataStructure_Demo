//LinkList demo
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define INIT_SIZE = 10;
#define INCREMENT_SIZE = 5;

typedef int Elemtype;
typedef int Status;

typedef struct
{
    Elemtype * base;
    Elemtype * top;
    int size;
}SqStack;

Status InitStack(SqStack *S)
{
    S->base = (Elemtype*)malloc(INIT_SIZE*sizeof(Elemtype));
    if(!S->base)
    {
        exit(OVERFLOW);
    }
    S->top = S->base;
    S->size = INIT_SIZE;
    return OK;
}

Status Push(SqStack *S, Elemtype e)
{
    if(S->top >= S->size)
    {
       S->base = (Elemtype*)realloc(S->base, (S->size + INCREMENT_SIZE)*sizeof(Elemtype));
       if(!S->base)
       {
           exit(OVERFLOW);
       }
    }
    S->top = S->base + S->size;
    S->size += INCREMENT_SIZE;

    *S->top = e;
    S->top += sizeof(Elemtype);
    return OK;
}

void visit(Elemtype e)
{
    printf("%d ", e);
}

void TraverseList(SqStack S, void(*visit)(Elemtype))
{

    while(S.top > S.base)
    {
        visit(*S.base);
        S.base += sizeof(Elemtype);
    }
    return OK;
}
