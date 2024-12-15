#ifndef QUEUE_
#define QUEUE_

#define QueueEntry int 
#define Maxsize 5

typedef struct Queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[Maxsize];

}Queue;

//we can make Queue using 2 stacks  :) just note (:

void CreateQueue(Queue *pq);
void EnQueue(QueueEntry item ,Queue *pq);
void DeQueue(QueueEntry *item ,Queue *pq);
int DeQueue2(Queue *pq);        //return item dequeued
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
int Queue_Size(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq ,void (*pf)(QueueEntry));


#endif