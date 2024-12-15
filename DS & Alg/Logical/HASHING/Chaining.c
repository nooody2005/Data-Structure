#include "Chaining.h"


// int hash(int key)
// {
//  return key%10;
// }

void SortedInsert(List_node **H, int x)
{
    List_node *t, *q = NULL, *p = *H;

    t = (List_node *)malloc(sizeof(List_node));
    t->entry = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->entry < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void InsertC(List_node *H[],int key)
{
 int index=hash(key);
 SortedInsert(&H[index],key);
}

List_node *SearchC(List_node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->entry)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


