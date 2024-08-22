#ifndef DOUBLY
#define DOUBLY

#include <stdio.h>


#define DoublyEntry int
#define Max_Doubly int

typedef struct Doubly_Node
{
    DoublyEntry entry;
    struct Doubly_Node *next;
    struct Doubly_Node *pre;
}Doubly_Node;

//typedef Doubly_Node *Doubly;    //we can use pointer point to pointer type of struct


typedef struct Doubly_List
{
    Doubly_Node *head;
    int size;
}Doubly_List;


void Create_Doubly(Doubly_List *pl);
int ListEmpty_Doubly(Doubly_List *pl);
void Insert_Doubly(Doubly_List *pl, int pos, DoublyEntry e);
void Delete_Doubly(Doubly_List *pl, int pos, DoublyEntry *e);
void Retrieve_Doubly(Doubly_List *pl, int pos, DoublyEntry *e);
void Replace_Doubly(Doubly_List *pl, int pos, DoublyEntry e);
void Traverse_Doubly(Doubly_List *pl, void (*Visit)(DoublyEntry));


#endif 
