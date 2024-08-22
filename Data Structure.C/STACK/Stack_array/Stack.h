#ifndef STACK_H  
#define STACK_H

#define StackEntry int
#define MAX_STACK 5



typedef struct Stack
{
    StackEntry entry [MAX_STACK];
    int top;
}Stack;



void CreateStack(Stack *ps);
int Stack_Size(Stack *ps);
int Stack_Empty(Stack *ps);
int Stack_Full(Stack *ps);
void push (StackEntry item ,Stack *ps);
void pop (StackEntry *pitem ,Stack *ps);
void Stack_Top(StackEntry *pitem ,Stack *ps);
void Clear_Stack(Stack *ps);
void Traverse_Stack(Stack *ps, void (*pf)(StackEntry)); //pointer to function



#endif 

