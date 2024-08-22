#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.c"  

// Example visit function for TraverseList
void printEntry(ListEntry e) 
{
    printf("%d ", e);  // Assuming ListEntry is an integer
}

int main() 
{
    LinkedList list;
    ListEntry value;

    CreateList(&list);
    
    
    return 0;
}
