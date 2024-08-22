#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#if LIMITED_MEMORY == 1
// Linked List Based Implementation

void CreateStack(Stack* s) 
{
    s->top = NULL;
}

int isEmpty(Stack* s) 
{
    return s->top == NULL;
}

void push(Stack* s, int value) 
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) 
    {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    int value = s->top->data;
    StackNode* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

int peek(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

#else
// Array Based Implementation

void CreateStack(Stack* s) 
{
    s->top = -1;
}

int isEmpty(Stack* s) 
{
    return s->top == -1;
}

int isFull(Stack* s) 
{
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack* s, int value) 
{
    if (isFull(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

#endif
