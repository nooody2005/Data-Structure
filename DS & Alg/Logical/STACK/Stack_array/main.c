#include <stdio.h>
#include <stdlib.h>
#include "Stack.c"

void display(StackEntry item) 
{
    printf("item is : %d\n", item);
}

int main() 
{
    Stack s;
    CreateStack(&s);
    int e;
    push(10, &s);
    push(20, &s);
    push(30, &s);

    Traverse_Stack(&s, display);
    
    
    return 0;
}
