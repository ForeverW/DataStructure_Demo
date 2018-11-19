//Quen Practice
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

//data structure to save data
typedef struct QNode
{
    Elemtype data;
    struct QNode *next;
}QNode, *QueuePtr;

//Queue struct
typedef struct
{
    QueuePtr front;
    QueuePtr rear;    // Queue rear
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
    {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;

    return OK;
}

Status IsEmpty(LinkQueue Q)
{
    if(Q.front->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int GetLength(LinkQueue Q)
{
    QueuePtr p = Q.front;
    int i = 0;
    while(Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status EnQueue(LinkQueue *Q, Elemtype e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
    {
        exit(OVERFLOW);
    }
    p->data = e;
    Q->rear->next = p;
    Q->rear = p;
    p->next = NULL;

    return OK;
}

Status DeQueue(LinkQueue *Q, Elemtype *e)
{
    QueuePtr p;
    if(Q->front == Q->rear)
    {
        return ERROR;
    }
    p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

int main()
{
    int i = 0;
    Elemtype e = 100;
    LinkQueue Q;
    InitQueue(&Q);

    for(i = 0; i<10; i++)
    {
        EnQueue(&Q, i);
    }

    printf("GetLength is %d \n",GetLength(Q));
    printf("DeQueue Operation\n");

    for(i = 0;i<6; i++)
    {
        DeQueue(&Q, &e);
        printf("The Delete number is: %d \n", e);
    }
    return OK;

}
