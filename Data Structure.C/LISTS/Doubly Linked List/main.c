#include <stdio.h>
#include <stdlib.h>
#include "Doubly.c"  

// Function to print an entry
void PrintEntry(DoublyEntry entry) 
{
    printf("%d ", entry);
}

int main() 
{
    Doubly_List list;
    Create_Doubly(&list);

}