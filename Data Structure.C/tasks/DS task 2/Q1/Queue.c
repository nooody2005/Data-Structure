#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#if LIMITED_MEMORY == 1
// Linked List Based Implementation

void CreateQueue(Queue* q) 
{
    q->front = q->rear = NULL;
}

int isEmptyQueue(Queue* q) 
{
    return q->front == NULL;
}

void enqueue(Queue* q, int value) 
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) 
    {
        printf("Queue overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
    } 
    else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) 
{
    if (isEmptyQueue(q)) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->front->data;
    QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) 
    {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int front(Queue* q) 
{
    if (isEmptyQueue(q)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

#else
// Array Based Implementation

void CreateQueue(Queue* q) 
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmptyQueue(Queue* q) 
{
    return q->size == 0;
}

int isFullQueue(Queue* q) 
{
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, int value) 
{
    if (isFullQueue(q)) 
    {
        printf("Queue overflow\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) 
{
    if (isEmptyQueue(q)) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return value;
}

int front(Queue* q) 
{
    if (isEmptyQueue(q)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

#endif
