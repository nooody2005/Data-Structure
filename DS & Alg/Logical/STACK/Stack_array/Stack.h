
#ifndef STACK_H  
#define STACK_H




typedef struct Stack
{
    #define StackEntry int
    #define MAX_STACK 5

    StackEntry entry [MAX_STACK];
    int top;

}Stack;

typedef struct Stack2   //special stack for Applications  .. Create2  fun..
{
    #define StackEntry char
    char *entry;
    int top;
    int size;
}Stack2;


void CreateStack(Stack *ps);

//===== special for Applications =====
void CreateStack2(const char *exp,Stack2 *ps);  
void push2(Stack2 *ps, char item);
char pop2(Stack2 *ps);
char Stack_Top2(Stack2 *ps);
//===========================================

int Stack_Size(Stack *ps);
int Stack_Empty(Stack *ps);
int Stack_Full(Stack *ps);
void push (StackEntry item ,Stack *ps);
StackEntry pop (Stack *ps);
// void pop (StackEntry *pitem ,Stack *ps);
// void Stack_Top(StackEntry *pitem ,Stack *ps);
StackEntry Stack_Top(Stack *ps);
void Clear_Stack(Stack *ps);
void Traverse_Stack(Stack *ps, void (*pf)(StackEntry)); //pointer to function
int peek(Stack *ps ,int pos);



#endif 

