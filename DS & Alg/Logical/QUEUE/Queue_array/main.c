#include <stdio.h>
#include "Queue.c"


void display(QueueEntry item)
{
    printf("item is: %d\n", item);
}


int main()
{
    Queue q;
    QueueEntry e;

    AppendQueue(10, &q);
    AppendQueue(20, &q);
    AppendQueue(30, &q);

    TraverseQueue(&q, display);
}