
#ifndef LINKED_LISTS
#define LINKED_LISTS

#include <stdio.h>
#include <stdlib.h>


#define ListEntry int
#define Max_list 100

typedef struct List_node
{
    ListEntry entry;
    struct List_node *next;
}List_node;

typedef struct LinkedList
{
    List_node *head;
    int size;
}LinkedList;


// for LinkedList not circular
void CreateList(LinkedList *pl, int A[], int n);
void InsertList(int p , ListEntry e ,LinkedList *pl);
void  DeleteList(int p , ListEntry *pe ,LinkedList *pl);
void display(LinkedList *pl);


// for  Circular LinkedList 
void CreateCircular(LinkedList *pl, int A[], int n);
void InsertCircularList(int pos, ListEntry e, LinkedList *pl);
void DeleteCircularList(int pos, ListEntry *pe, LinkedList *pl);
void displayCircularList(List_node *p, List_node *head);


// for all ..
void Create(LinkedList *pl);
int ListEmpty(LinkedList *pl);
int ListFull(LinkedList *pl);
int ListSize(LinkedList *pl);
void DestroyList(LinkedList *pl);
void RetriveList(int p ,ListEntry *pe,LinkedList *pl);
void ReplaceList(int p ,ListEntry e, LinkedList *pl);   //Edit item
void TraverseList(LinkedList *pl ,void (*Visit)(ListEntry));
int max(LinkedList *pl);
int remax(List_node *head);
List_node *Search(LinkedList *pl, int key);
List_node *reSearch(List_node *head, int key);


void reverse(LinkedList *pl);
void reverse2(LinkedList *pl, List_node *current);
void concat(LinkedList *pl, LinkedList *second);
void concatSorted(LinkedList *pl, LinkedList *second);



#endif

