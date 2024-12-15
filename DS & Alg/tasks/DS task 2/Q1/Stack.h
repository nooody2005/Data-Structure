#ifndef STACK_H
#define STACK_H

#include "global.h"

#if LIMITED_MEMORY == 1
// Linked List Based Stack
typedef struct StackNode 
{
    int data;
    struct StackNode* next;
} StackNode;

typedef struct 
{
    StackNode* top;
} Stack;

#else

// Array Based Stack
#define MAX_STACK_SIZE 100

typedef struct 
{
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

#endif


void CreateStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);

#endif
