#include "Queue.h"
#include <stdio.h>

void CreateQueue(Queue *pq)
{
    pq->front =0;
    pq->rear =-1;
    pq->size =0;
}

void AppenedQueue(QueueEntry item ,Queue *pq)
{

    if (QueueFull(pq))
    {
        printf("Queue is full, cannot append item.\n");
        return;
    }

    pq->rear =(pq->rear+1) % Maxsize;
    
    // if (pq->rear == Maxsize-1)  pq->rear=0;
    // else                        pq->rear++;

    pq->entry[pq->rear] = item;
    pq->size++;

}

void ServeQueue(QueueEntry *item ,Queue *pq)
{
     if (QueueEmpty(pq))
    {
        printf("Queue is empty, cannot serve item.\n");
        return;
    }
    
    *item = pq->entry[pq->front];
    pq->front =(pq->front + 1) % Maxsize;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return pq->size == 0;           // !pq->size 
}

int QueueFull(Queue *pq)
{
    return (pq->size == Maxsize);
}

int Queue_Size(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    pq->front =0;
    pq->rear =-1;
    pq->size =0;
}

void TraverseQueue(Queue *pq ,void (*pf)(QueueEntry))
{
    int pos =pq->front  ,s=0;
    
    while (s < pq->size)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % Maxsize;
        s++;
    }

}