
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.c"
#include "CircularList.c"

// Example visit function for TraverseList
void printEntry(ListEntry e)
{
    printf("%d ", e); // Assuming ListEntry is an integer
}

int isloop(LinkedList *pl)
{
    List_node *p, *q;
    p = q = pl->head;

    while (p != NULL && q != NULL && q->next != NULL)
    {
        p = p->next;
        q = q->next->next; // Move q by two steps

        if (p == q)
        {
            return 1;
        }
    }

    return 0;
}

void menu()
{
    printf("\n-------------------\n");
    printf("1. Create LinkedList\n");
    printf("2. Insert into LinkedList\n");
    printf("3. Delete from LinkedList\n");
    printf("4. Display LinkedList\n");
    printf("5. Search in LinkedList\n");
    printf("6. Reverse LinkedList\n");
    printf("7. Get max from LinkedList\n");
    printf("8. Create Circular LinkedList\n");
    printf("9. Insert into Circular LinkedList\n");
    printf("10. Delete from Circular LinkedList\n");
    printf("11. Display Circular LinkedList\n");
    printf("12. Check if list has loop\n");
    printf("0. Exit\n");
    printf("-------------------\n");
    printf("Choose an option: ");
}

int main()
{
    LinkedList list;
    LinkedList circularList;
    ListEntry entry;
    int pos, choice, key, A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);

    while (1)
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Create a normal LinkedList
            CreateList(&list, A, size);
            printf("LinkedList created with elements: ");
            display(&list);
            break;

        case 2: // Insert into LinkedList
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            printf("Enter element to insert: ");
            scanf("%d", &entry);
            InsertList(pos, entry, &list);
            printf("Updated LinkedList: ");
            display(&list);
            break;

        case 3: // Delete from LinkedList
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            DeleteList(pos, &entry, &list);
            printf("Deleted element: %d\n", entry);
            printf("Updated LinkedList: ");
            display(&list);
            break;

        case 4: // Display LinkedList
            printf("LinkedList elements: ");
            display(&list);
            break;

        case 5: // Search in LinkedList
            printf("Enter key to search: ");
            scanf("%d", &key);
            List_node *result = Search(&list, key);
            if (result != NULL)
            {
                printf("Element %d found in the list.\n", key);
            }
            else
            {
                printf("Element %d not found.\n", key);
            }
            break;

        case 6: // Reverse LinkedList
            reverse(&list);
            printf("Reversed LinkedList: ");
            display(&list);
            break;

        case 7: // Get max from LinkedList
            printf("Maximum element in the list: %d\n", max(&list));
            break;

        case 8: // Create a Circular LinkedList
            CreateCircular(&circularList, A, size);
            printf("Circular LinkedList created with elements: ");
            displayCircularList(circularList.head, circularList.head);
            break;

        case 9: // Insert into Circular LinkedList
            printf("Enter position to insert in Circular List: ");
            scanf("%d", &pos);
            printf("Enter element to insert: ");
            scanf("%d", &entry);
            InsertCircularList(pos, entry, &circularList);
            printf("Updated Circular LinkedList: ");
            displayCircularList(circularList.head, circularList.head);
            break;

        case 10: // Delete from Circular LinkedList
            printf("Enter position to delete from Circular List: ");
            scanf("%d", &pos);
            DeleteCircularList(pos, &entry, &circularList);
            printf("Deleted element: %d\n", entry);
            printf("Updated Circular LinkedList: ");
            displayCircularList(circularList.head, circularList.head);
            break;

        case 11: // Display Circular LinkedList
            printf("Circular LinkedList elements: ");
            displayCircularList(circularList.head, circularList.head);
            break;

        case 12: // Check for loop
            if (isloop(&list))
            {
                printf("The LinkedList contains a loop.\n");
            }
            else
            {
                printf("No loop detected in the LinkedList.\n");
            }
            break;

        case 0: // Exit
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice! Please choose a valid option.\n");
            break;
        }
    }

    return 0;
}