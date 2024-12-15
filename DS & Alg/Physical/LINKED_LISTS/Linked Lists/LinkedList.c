
#include "LinkedList.h"
#include <limits.h>

// To store an array in a linked list
void CreateList(LinkedList *pl, int A[], int n)
{
    if (n == 0) return;  

    pl->head = (List_node*)malloc(sizeof(List_node));
    if (pl->head == NULL) 
    {
        return;
    }
    pl->head->entry = A[0];
    pl->head->next = NULL;

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
        t->next = NULL;
        last->next = t;
        last = t;

        pl->size++;  
    }
}


void Create(LinkedList *pl)
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

void InsertList(int pos, ListEntry e, LinkedList *pl) 
{
    // Check for valid position
    if (pos < 0 || pos > pl->size) 
    {
        printf("Invalid position.\n");
        return;
    }

    List_node *p = (List_node *)malloc(sizeof(List_node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    p->entry = e;
    p->next = NULL;

    // Insert at the head
    if (pos == 0) {
        p->next = pl->head;
        pl->head = p;
    }
    // Insert in the middle or end
    else {
        List_node *q = pl->head;
        int count = 0;
        while (q) {
            if (count == pos - 1) break;
            q = q->next;
            count++;
        }

        // If `q` is still NULL, something went wrong
        if (q == NULL || count != pos - 1) {
            printf("Position out of bounds.\n");
            free(p);
            return;
        }

        p->next = q->next;
        q->next = p;
    }

    // Increment the size
    pl->size++;
    printf("Node inserted successfully.\n");
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


int max(LinkedList *pl) 
{
    int m = INT_MIN;
    List_node *current = pl->head;

    while (current) 
    {
        if (current->entry > m)     m = current->entry;
        current = current->next;  
    }

    return m;
}


int remax(List_node *head) 
{
    if (head == NULL) 
    return INT_MIN;  

    int x = remax(head->next);  
    return (x > head->entry) ? x : head->entry;  
}


List_node *Search(LinkedList *pl, int key) 
{
    List_node *current = pl->head;

    while (current) 
    {
        if (key == current->entry)
            return current;  
        current = current->next;
    }
    return NULL;  
}

List_node *reSearch(List_node *head, int key) 
{
    if (head == NULL) 
    {
        return NULL;
    }

    if (key == head->entry) 
    {
        return head;  
    }

    return reSearch(head->next, key);  
}

void reverse(LinkedList *pl) 
{
    List_node *q = NULL, *r = NULL;
    List_node *current = pl->head;  

    while (current) 
    {
        r = q;                      // Step 1: Store the previous node
        q = current;                // Step 2: Current node becomes the new "previous"
        current = current->next;    // Step 3: Move to the next node
        q->next = r;                // Step 4: Reverse the link
    }
    pl->head = q;                   // Step 5: Update the head of the list
}

void reverse2(LinkedList *pl, List_node *current) 
{
    if (current == NULL) 
    {
        return;
    }

    if (current->next == NULL) 
    {
        pl->head = current;  
        return;
    }

    reverse2(pl, current->next);  

    current->next->next = current;  
    current->next = NULL;  // Set the next of the current node to NULL to avoid cycles
}


void concat(LinkedList *pl, LinkedList *second)
{
    if (pl->head == NULL) 
    {
        pl->head = second->head;
        return;
    }

    List_node *con = pl->head;
    while (con->next != NULL)
    {
        con=con->next;
    }

    // Link the last node of the first list to the head of the second list
    con->next = second->head;
}


// Link 2 sorted lists 
void concatSorted(LinkedList *pl, LinkedList *second)
{
    // If the first list is empty, return the second list as the merged list
    if (pl->head == NULL) 
    {
        pl->head = second->head;
        return;
    }

    List_node *con1=pl->head;
    List_node *con2 = second->head;

    List_node *last ,*third; 

    // last is temp pointer to select the smallest node
    // so we make it = NULL again

    if(con1->entry < con2->entry)
    {
        third =last = con1;
        con1 = con1->next;
    }
    else 
    {
        third =last = con2;
        con2 = con2->next;
    }

    // con1 now pointed to the last node in the first List 
    pl->head = third;   //to update the head of the first node in the first or the second list

    while (con1 != NULL && con2 != NULL)
    {
        if (con1->entry < con2->entry)
        {
           last ->next =con1;
           last=con1;
           con1=con1->next;
        }
        else 
        {
            last ->next=con2;
            last =con2;
            con2 =con2->next;
        }
    }
    // Attach the remaining part of either list
    if (con1!=NULL)
    {
        last->next =con1;
    }
    if (con2!=NULL)
    {
        last->next =con2;
    }

}

void display(LinkedList *pl)
{
    List_node *current = pl->head;  

    if (ListEmpty(pl)) 
    {
        printf("The list is empty.\n");
        return;
    }

    while (current != NULL) 
    {
        printf("%d ", current->entry);  
        current = current->next; 
    }
    printf("\n");
}

