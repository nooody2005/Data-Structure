
#include "LinkedList.h"
#include <limits.h>


// To store an array in a linked list
void CreateCircular(LinkedList *pl, int A[], int n)
{
    if (n == 0) return;  

    pl->head = (List_node*)malloc(sizeof(List_node));
    if (pl->head == NULL) 
    {
        return; 
    }

    pl->head->entry = A[0]; 
    pl->head->next = pl->head; // Point to itself (circular)

    List_node *last = pl->head;
    pl->size = 1;  

    for (int i = 1; i < n; i++)  
    {
        List_node *t = (List_node*)malloc(sizeof(List_node));
        if (t == NULL) 
        {
            return; 
        }
        t->entry = A[i];
        t->next = pl->head; // Point to head to maintain circularity

        last->next = t; 
        last = t; 

        pl->size++;  
    }
}


void InsertCircularList(int pos, ListEntry e, LinkedList *pl) 
{
    List_node *p; 
    p = (List_node *)malloc(sizeof(List_node));
    if (p == NULL) 
    {
        return;  
    }
    p->entry = e;

    // If the list is empty, initialize the new node to point to itself
    if (pl->head == NULL) 
    {
        p->next = p;  // New node points to itself
        pl->head = p;  
    } 
    else if (pos == 0)  
    {
        List_node *last = pl->head;

        // Find the last node in the circular list
        while (last->next != pl->head) 
        {
            last = last->next;
        }

        // Insert the new node at the beginning
        p->next = pl->head;  // New node points to the current head
        last->next = p;  // Last node points to the new node
        pl->head = p;  // Update head to the new node
    } 
    else if (pos == pl->size)  // Inserting at the last position
    {
        List_node *last = pl->head;

        // Find the last node in the circular list
        while (last->next != pl->head) 
        {
            last = last->next;
        }

        last->next = p;  // Last node points to the new node
        p->next = pl->head;  // New node points to the head
    }
    else  // Inserting in the middle
    {
        List_node *q = pl->head;
        int count = 0;

        while (count < pos - 1 && q->next != pl->head) 
        {
            q = q->next;
            count++;
        }

        if (count != pos - 1) 
        {
            free(p);  
            return;
        }

        // Insert the new node in the middle
        p->next = q->next; 
        q->next = p;  
    }

    pl->size++;  
}


void DeleteCircularList(int pos, ListEntry *pe, LinkedList *pl)
{
    if (pos < 0 || pos >= pl->size || pl->head == NULL) 
    {
        return;
    }

    List_node *q, *temp;

    if (pos == 0) 
    {
        q = pl->head;

        // If the list contains only one node
        if (pl->head->next == pl->head) 
        {
            *pe = pl->head->entry;
            free(pl->head);
            pl->head = NULL;
        } 
        else 
        {
            // Find the last node (since it's a circular list)
            List_node *last = pl->head;
            while (last->next != pl->head) 
            {
                last = last->next;
            }

            // Save the entry and remove the head
            *pe = pl->head->entry;
            temp = pl->head->next;  // Store the new head
            free(pl->head);  // Free the old head

            pl->head = temp;  // Update head to the next node
            last->next = pl->head;  // Update the last node to point to the new head
        }
    } 
    else 
    {
        q = pl->head;
        int count = 0;

        while (count < pos - 1) 
        {
            q = q->next;
            count++;
        }

        // The node to delete is q->next
        temp = q->next;  
        *pe = temp->entry;  
        q->next = temp->next;  

        free(temp);  
    }

    pl->size--;  
}

void displayCircularList(List_node *p, List_node *head)
{
    if (p == NULL) return;  

    static int firstCall = 1;
    if (firstCall || p != head) // Only display if it's the first call or if we are not back to the head
    {
        firstCall = 0;
        printf("%d ", p->entry);
        displayCircularList(p->next, head); 
    }

    if (p == head)
    {
        firstCall = 1; // Reset for future calls
    }
}
