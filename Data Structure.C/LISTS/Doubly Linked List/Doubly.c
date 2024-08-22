#include "DoublyList.h"

void Create_Doubly(Doubly_List *pl) 
{
    pl->head = NULL;
    pl->size = 0;
}

int ListEmpty_Doubly(Doubly_List *pl) 
{
    return (pl->size == 0);
}

void Insert_Doubly(Doubly_List *pl, int pos, DoublyEntry e) 
{
    if (pos < 0 || pos > pl->size) 
    {
        // Position is out of bounds
        return;
    }

    Doubly_Node *p = (Doubly_Node*) malloc(sizeof(Doubly_Node));
    if (p == NULL) {
        // Memory allocation failure
        return;
    }
    p->entry = e;

    if (pos == 0) 
    {  // Insert at the beginning
        p->next = pl->head;
        p->pre = NULL;
        if (pl->head != NULL) 
        {
            pl->head->pre = p;
        }
        pl->head = p;
    } 
    else 
    {
        Doubly_Node *q = pl->head;
        int i = 0;
        while (i < pos - 1) 
        {
            q = q->next;
            i++;
        }
        p->next = q->next;
        p->pre = q;
        if (q->next != NULL) 
        {
            q->next->pre = p;
        }
        q->next = p;
    }
    pl->size++;
}

// Delete an entry at a specified position
void Delete_Doubly(Doubly_List *pl, int pos, DoublyEntry *e) 
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // Position is out of bounds or list is empty
        return;
    }

    Doubly_Node *q;
    if (pos == 0) 
    {  // Remove the first node
        q = pl->head;
        *e = q->entry;
        pl->head = q->next;
        if (pl->head != NULL) 
        {
            pl->head->pre = NULL;
        }
    } 
    else 
    {
        Doubly_Node *prev = pl->head;
        int i = 0;
        while (i < pos - 1) 
        {
            prev = prev->next;
            i++;
        }
        q = prev->next;
        *e = q->entry;
        prev->next = q->next;
        if (q->next != NULL) 
        {
            q->next->pre = prev;
        }
    }
    free(q);
    pl->size--;
}

// Retrieve an entry at a specified position
void Retrieve_Doubly(Doubly_List *pl, int pos, DoublyEntry *e) 
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // Position is out of bounds or list is empty
        return;
    }

    Doubly_Node *q = pl->head;
    int i = 0;
    while (i < pos) 
    {
        q = q->next;
        i++;
    }
    *e = q->entry;
}

// Replace an entry at a specified position
void Replace_Doubly(Doubly_List *pl, int pos, DoublyEntry e) 
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        // Position is out of bounds or list is empty
        return;
    }

    Doubly_Node *q = pl->head;
    int i = 0;
    while (i < pos) 
    {
        q = q->next;
        i++;
    }
    q->entry = e;
}

// Traverse the list and apply a function to each entry
void Traverse_Doubly(Doubly_List *pl, void (*Visit)(DoublyEntry)) 
{
    Doubly_Node *p = pl->head;
    while (p != NULL) 
    {
        (*Visit)(p->entry);
        p = p->next;
    }
}


/*void Create_Doubly(Doubly *pl)
{
    (*Doubly)=NULL;
}

void Insert_Doubly(Doubly *pl ,int pos ,DoublyEntry e )   //*pl  is the first
{
    Doubly_Node *p = (Doubly_Node*) malloc(sizeof(Doubly_Node));
    
     if (p == NULL) 
     {
        // memory allocation failure
        return;
    }

    if ((*pl)==NULL || pos==0)     //insert in first node 
    {
        p->entry =e;               //put item
        p->next =(*pl);            //point to pointer which point to node was first
        p->pre =NULL;              
        (*pl) = p;                 //pointer became point to node is added
    }
    else
    {
        node *q =(*pl);
        int i =0;
        while (i<pos-1)
        {
            q=q->next; 
            i++;
        }

         if (q == NULL) {
            // Position is out of bounds
            free(p);
            return;
        }

        p->entry=e;             //put item
        p->next =q->next;       //pointer in node is added became pointing to next node
        q->next=p;              //point to node is added
        q->next->next->pre=p;   //(pre of node) which (next of (node is added) point to it) became point to node is added (previous node (p))
        p->pre=q;               //pre of node is added became point to q (previous node)

    }
}*/