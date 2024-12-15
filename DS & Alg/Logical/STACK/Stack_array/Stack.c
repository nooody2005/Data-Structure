
#include "Stack.h"
#include <stdio.h>

void CreateStack(Stack *ps)
{
    ps->top = 0;
}

void CreateStack2(const char *expression, Stack2 *ps) 
{
    int length = strlen(expression); // Length of the expression
    ps->entry = (char *)malloc((length + 1) * sizeof(char)); // Allocate memory
    ps->top = 0;
    ps->size = length;
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
StackEntry pop (Stack *ps)
{
    if (Stack_Empty(ps))
    {
        printf("Stack is empty\n");
        return;
    }
    else 
    return ps->entry[--ps->top];
}

void push2(Stack2 *ps, char item)
{
    if (ps->top == ps->size) {
        printf("Stack is full\n");
        return;
    }
    ps->entry[ps->top++] = item;
}

char pop2(Stack2 *ps)
{
    if (ps->top == 0) {
        printf("Stack is empty\n");
        return '\0'; // Default empty char
    }
    return ps->entry[--ps->top];
}

char Stack_Top2(Stack2 *ps)
{
    if (ps->top == 0) {
        printf("Stack is empty\n");
        return '\0'; // Default empty char
    }
    return ps->entry[ps->top - 1];
}


// void pop (StackEntry *pitem ,Stack *ps)
// {
//     if (Stack_Empty(ps))
//     {
//         printf("Stack is empty\n");
//         return;
//     }
//     else 
//     *pitem =ps->entry[--ps->top];
// }

// void Stack_Top(StackEntry *pitem ,Stack *ps)
// {
//     if (Stack_Empty(ps))
//     {
//         printf("Stack is empty\n");
//         return;
//     }
//     else 
//     *pitem =ps->entry[ps->top-1];
// }

StackEntry Stack_Top(Stack *ps)
{
    if (Stack_Empty(ps))
    {
        printf("Stack is empty\n");
        return;
    }
    else 
    return ps->entry[ps->top-1];
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

int peek(Stack *ps ,int pos)
{
    int x=-1;
    if (ps->top-pos+1<1)
    {
        printf("invalid position ");
    }
    else 
    {
        x=ps->entry[ps->top-pos+1];
    }
    return x;
}
