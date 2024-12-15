#include <stdio.h>
#include "Linked_Queue.c"

void DisplayQueueEntry(Queue_Entry item) 
{
    printf("%d ", item);
}

int main() 
{
    Queue q;
    CreateQueue(&q);

    AppendQueue(10, &q);
    AppendQueue(20, &q);
    AppendQueue(30, &q);

    TraverseQueue(&q, DisplayQueueEntry);
    printf("\n");

    Queue_Entry frontItem;
    Queue_Top(&frontItem, &q);
    printf("Front item: %d\n", frontItem);

    ClearQueue(&q);

    return 0;
}