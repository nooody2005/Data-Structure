#include "Lists.h"

void CreateList(List *pl)
{
    pl->size = 0;
}

int ListEmpty(List *pl)
{
    return !pl->size;
}

int ListFull(List *pl)
{
    return pl->size == Max_list;
}

int ListSize(List *pl)
{
    return pl->size;
}

void DestroyList(List *pl)
{
    pl->size=0;
}

void InsertList(int p , ListEntry e ,List *pl)
{
    if (p < 0 || p > pl->size || ListFull(pl)) 
    {
        // invalid position or list is full
        return;
    }
    
    int i;

    for (i=pl->size-1; i>=p ; i--)    //shift items to add a new item
    {
        pl->entry[i+1]=pl->entry[i];
    }

    pl->entry[p]=e;
    pl->size++;
}

void  DeleteList(int p , ListEntry *pe ,List *pl)
{
    if (p < 0 || p >= pl->size) 
    {
        // invalid position
        return;
    }

    int i;
    *pe = pl->entry[p];

    for (i=p+1; i<=pl->size-1 ; i--)
    pl->entry[i-1]=pl->entry[i];

    pl->size--;
}

void RetriveList(int p ,ListEntry *pe,List *pl)
{
    if (p < 0 || p >= pl->size) 
    {
        // invalid position
        return;
    }
    *pe=pl->entry[p];
}

void ReplaceList(int p ,ListEntry e, List *pl)   //Edit item
{
    if (p < 0 || p >= pl->size) 
    {
        // invalid position
        return;
    }

    pl->entry[p]=e;
}

void TraverseList(List *pl ,void (*Visit)(ListEntry))
{
    int i;

    for (i=0; i<pl->size;i++)
    (*Visit)(pl->entry[i]);
}