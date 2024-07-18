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


void CreateQueue(Queue *pq);
void AppenedQueue(QueueEntry item ,Queue *pq);
void ServeQueue(QueueEntry *item ,Queue *pq);
int QueueEmpty(Queue *pq);
int QueueFull(Queue *pq);
int Queue_Size(Queue *pq);
void ClearQueue(Queue *pq);
void TraverseQueue(Queue *pq ,void (*pf)(QueueEntry));


#endif