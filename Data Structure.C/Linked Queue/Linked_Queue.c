#include <stdio.h>
#include <stdlib.h>
#include "Linked_Queue.h"

void Create_Queue(Queue* pq)
{
    pq->rear =NULL;
    pq->front =NULL;
    pq->size =0;
}

void Append_Queue(Queue_Entry item,Queue* pq)
{
    Queue_Node* pnode = (Queue_Node*)malloc(sizeof(Queue_Node));   //finding free memory
    
    pnode->Next =NULL;
    pnode->entry=item;
    
    if (!pq->rear)          //Queue is empty and first Node is being Appended
    {                       //condition is true when (pq->rear is NULL)
        pq->front = pnode;
    }
    else
    {
        pq->rear->Next = pnode;     //Run time error for empty queue
    }

    pq->rear=pnode;
    pq->size++;

}


void Serve_Queue(Queue_Entry *item,Queue* pq)
{
    Queue_Node* pnode = pq ->front;
    *item= pnode->entry; 
    pq->front = pnode->Next;        //error for empty queue 
    free(pnode);

    if (!pq->front)                 //Queue contains one element and it is served
    {
        pq->rear=NULL;              //condition is true when (pq->front is NULL)
    }

    pq->size--;

}

void Queue_Top(Queue_Entry *item,Queue *pq)
{
    *item= pq->front->entry;
}

int Queue_Empty(Queue *pq)
{
    return !pq->front;          //return true when (pq->front is NULL)
}

int Queue_Full(Queue *pq)       //dynamic memory --- infinite memory
{                               //user uses it to check if can push more
    return 0;                    //it return 0 while memory isn't full 
}

int Queue_size(Queue *pq)
{
    return pq->size;
}

void Clear_Queue(Queue *pq)
{
    while(pq->front)
    {
        pq->rear = pq->front->Next;   //rear will point to the Node which will be cleared by front
        free(pq->front);
        pq->front = pq->rear;
    }

    pq->size = 0;
}

/*void Clear_Queue(Queue *pq)
{
    Queue_Node *pnode = pq->front;
    Queue_Node *qn;

    while (pnode)
    {
        qn = pnode->Next;  // Save the next node
        free(pnode);       // Free the current node
        pnode = qn;        // Move to the next node
    }

    pq->size = 0;
    pq->front = NULL;
    pq->rear = NULL;
}*/

void Traverse_Queue(Queue *pq, void (*pf)(Queue_Entry))
{
    Queue_Node *pnode = pq->front; 

    while (pnode)
    {
        (*pf)(pnode->entry); 
        pnode = pnode->Next; 
    }
}

