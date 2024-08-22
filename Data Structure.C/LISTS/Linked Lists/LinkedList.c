#include "Lists.h"

void CreateList(LinkedList *pl)
{
    pl->head= NULL;
    pl->size = 0;
}

int ListEmpty(LinkedList *pl)
{
    return (pl->size==0);
}

int ListFull(LinkedList *pl)
{
    return 0;
}

int ListSize(LinkedList *pl)
{
    return pl->size;
}

void DestroyList(LinkedList *pl)
{
    List_node *q ;
    while (pl->head)
    {
        q=pl->head->next;
        free(pl->head);
        pl->head=q;
    }
    pl->size=0 ; 
}

void InsertList(int pos , ListEntry e ,LinkedList *pl)   //without shifting elements
{
    List_node *q , *p;                                   //p point to new node   // q point to node which point to a new node
    
    p=(List_node *)malloc(sizeof(List_node));
    if (p == NULL) 
    {
        // memory allocation failure
        return;
    }
    p->entry=e;
    p->next =NULL; 


    if (pos==0)                                        // new node is added in the first of linked_list
    {
        p->next =pl->head;
        pl->head =p;
    }
    else                                               // new node is added in any place in mid
    {
        int count=0;
        List_node *q = pl->head;
        while(q)
        {
            if (count == pos-1)   break;               // already reach to position

            q =q->next;
            count++;
        }
                                                //you can use if condition in the first in malloc (true) then the last return 1 
        if (q == NULL || count != pos - 1)      //else   return 0
        {
            // Handle case where position is out of bounds
            free(p);
            return;
        }

        p->next=q->next;
        q->next = p;
    }
    pl->size++; 
    
}

void  DeleteList(int pos , ListEntry *pe ,LinkedList *pl)
{

    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // invalid position or empty list
        return;
    }
      List_node *q ,*temp;                            //temp to connect other nodes after deleting   // q point to node which point to a node want to delete

    if(pos==0)
    {
        temp=pl->head->next;
        *pe=pl->head->entry;
        free(pl->head);
        pl->head=temp;
    }
    else
    {
        q=pl->head;
        int count =0;
        while(q)
        {
            if (count==pos-1)
            {
                temp=q->next->next;
                break;
            }

            q=q->next;
            count++;
        }

        if (q == NULL || count != pos - 1)      
        {
            // case where position is out of bounds
            return;
        }

        *pe=q->next->entry;
        free(q->next);
        q->next=temp;
    }
    pl->size--;
}

void RetriveList(int pos ,ListEntry *pe,LinkedList *pl)
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // invalid position or empty list
        return;
    }

    List_node *q = pl->head;
    int count = 0;

    while (count < pos) 
    {
        q = q->next;
        count++;
    }

    *pe = q->entry;
}

void ReplaceList(int pos ,ListEntry e, LinkedList *pl)   //Edit item
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // invalid position or empty list
        return;
    }

    List_node *q = pl->head;
    int count = 0;

    while (count < pos) 
    {
        q = q->next;
        count++;
    }

    q->entry = e;
}

void TraverseList(LinkedList *pl ,void (*Visit)(ListEntry))
{
    List_node *p =pl->head;
    while (p)
    {
        (*Visit)(p->entry);
        p = p->next;
    }
}