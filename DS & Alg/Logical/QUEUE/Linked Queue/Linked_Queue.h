#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_ 

#define Queue_Entry int


typedef struct Queue_Node
{
    Queue_Entry entry;
    struct Queue_Node *Next;
}Queue_Node;

typedef struct Queue
{
    Queue_Node *rear;
    Queue_Node *front;
    int size;

}Queue;

void Create_Queue(Queue* pq);
void Append_Queue(Queue_Entry item,Queue* pq);
void Serve_Queue(Queue_Entry *item,Queue* pq);
void Queue_Top(Queue_Entry *item,Queue *pq);
int Queue_Empty(Queue *pq);
int Queue_Full(Queue *pq);
int Queue_size(Queue *pq);
void Clear_Queue(Queue *pq);
void Traverse_Queue(Queue *pq, void (*pf)(Queue_Entry));


#endif