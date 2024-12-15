/*3-Write a C program to delete element from the array at specified position.
The program should also print an error message 
if the delete position is invalid.*/


#include <stdio.h>

void deleteElement(int arr[], int* size, int pos) 
{
    if (pos < 0 || pos >= *size) 
    {
        printf("Error: Invalid position.\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;

    printf("Array after deletion:\n");
    for (int i = 0; i < *size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; 

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Enter the position of the element to delete (0 to %d): ", size - 1);
    scanf("%d", &pos);

    deleteElement(arr, &size, pos);

    return 0;
}
