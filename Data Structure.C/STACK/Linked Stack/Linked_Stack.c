#include <stdio.h>
#include <stdlib.h>
#include "Linked_Stack.h"

void Create_Stack(Stack *ps)
{
    ps->top = NULL;
    ps ->size = 0;
}

void push (Stack_Entry item ,Stack *ps)
{
    Stack_Node *pnode = (Stack_Node*) malloc (sizeof (Stack_Node)); //finding free memory
    pnode->entry = item;
    pnode->next = ps->top;
    ps->top = pnode;

    ps -> size++;
}

void pop (Stack_Entry *item ,Stack *ps)
{
    Stack_Node *pnode ;         //Stack_Node *pnode =ps->top ; 
    *item = ps->top->entry;     //*item = pnode->entry;
    pnode =ps->top;             //xxxx
    ps->top = ps->top->next;    //ps->top = pnode->next;
    free(pnode);

    ps -> size--;
}

void Stack_Top(Stack_Entry *item ,Stack *ps)
{
    *item = ps->top->entry; 
}

int Stack_Empty(Stack *ps)
{
    return ps->top == NULL;
}

int Stack_Full(Stack *ps)   //dynamic memory --- infinite memory 
{                           //user uses it to check if can push more 
    return 0;               //it return 0 while memory isn't full 
}

void Clear_Stack(Stack *ps)
{
    Stack_Node *pnode = ps->top;
    Stack_Node *qn= ps->top;    //you can write function without qn 

    while(pnode)
    {
        pnode = pnode -> next;
        free(qn);               //you can replace qn=ps->top
        qn = pnode;
    }

    ps->top = NULL;

    ps->size =0;
}


void Reverse_Stack(Stack *ps ,void (*pf)(Stack_Entry))
{
    Stack_Node *pnode = ps->top;

    while (pnode)
    {
        (*pf) (pnode ->entry);
        pnode = pnode -> next;
    }
}

/*int Stack_Size(Stack *ps)         //this function in case-> size not declared in stack and functions
{
    Stack_Node *pnode = ps->top;
    int count=0;                    //int count

    while (pnode)                      //for (count=0; pn ; pn = pn -> next)
    {                               // count++;
        count++;
        pnode = pnode -> next;
    }
    
    return count;

}*/

int Stack_Size(Stack *ps)
{
    return ps->size;
}

