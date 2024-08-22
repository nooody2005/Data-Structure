#ifndef QUEUE_H
#define QUEUE_H

#include "global.h"

#if LIMITED_MEMORY == 1
// Linked List Based Queue
typedef struct QueueNode 
{
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct 
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

#else
// Array Based Queue
#define MAX_QUEUE_SIZE 100

typedef struct 
{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

#endif


void CreateQueue(Queue* q);
int isEmptyQueue(Queue* q);
int isFullQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);

#endif
