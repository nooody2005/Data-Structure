#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#define Stack_Entry int 


typedef struct Stack_Node
{
    Stack_Entry entry;
    struct Stack_Node *next;

}Stack_Node;


typedef struct Stack
{
    struct Stack_Node *top;
    int size;                 
    
}Stack;


void Create_Stack(Stack *ps);
void push (Stack_Entry item ,Stack *ps);
void pop (Stack_Entry *item ,Stack *ps);
void Stack_Top(Stack_Entry *item ,Stack *ps);
int Stack_Empty(Stack *ps);
int Stack_Full(Stack *ps);
void Clear_Stack(Stack *ps);
void Reverse_Stack(Stack *ps ,void (*pf)(Stack_Entry));
int Stack_Size(Stack *ps);



#endif