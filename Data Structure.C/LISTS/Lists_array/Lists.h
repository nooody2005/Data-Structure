#ifndef LISTS
#define LISTS

#include <stdio.h>


#define ListEntry int
#define Max_list int

typedef struct List 
{
    ListEntry entry [Max_list];
    int size;

}List;



void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(int p , ListEntry e ,List *pl);
void  DeleteList(int p , ListEntry *pe ,List *pl);
void RetriveList(int p ,ListEntry *pe,List *pl);
void ReplaceList(int p ,ListEntry e, List *pl);   //Edit item
void TraverseList(List *pl ,void (*Visit)(ListEntry));


#endif