#include "Stack.h"
#include <stdio.h>

void CreateStack(Stack *ps)
{
    ps->top = 0;
}


int Stack_Size(Stack *ps)
{
    return ps->top;
}


int Stack_Empty(Stack *ps)
{
    return ps->top==0;
}

int Stack_Full(Stack *ps)
{
    return ps->top==MAX_STACK;
}

void push (StackEntry item ,Stack *ps)
{
    if (Stack_Full(ps))
    {
        printf("Stack is full\n");
        return;
    }
    else 
    ps->entry[ps->top++]=item;
    
}

void pop (StackEntry *pitem ,Stack *ps)
{
    if (Stack_Empty(ps))
    {
        printf("Stack is empty\n");
        return;
    }
    else 
    *pitem =ps->entry[--ps->top];
}

void Stack_Top(StackEntry *pitem ,Stack *ps)
{
    if (Stack_Empty(ps))
    {
        printf("Stack is empty\n");
        return;
    }
    else 
    *pitem =ps->entry[ps->top-1];
}

/*void Stack_Top(StackEntry *pitem ,Stack *ps)
{
    pop(&pitem ,ps);
    push(item ,ps);

}*/

void Clear_Stack(Stack *ps)
{
    ps->top=0;
}

void Traverse_Stack(Stack *ps, void (*pf)(StackEntry)) //pointer to function
{
    for (int i=ps->top ;i>0 ;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}

