#include <stdio.h>
#include "Heap.h"

// Heap ----> Complete Binary Search
// Max Heap ---> evey node has element grater than or equal to its descendants
// Min Heap ---> evey node has element smaller than or equal to its descendants
// After deletion all elements from Heap ---> get sorted array (in ---> ascending order) these are saved in array but out of Heap

void Insert(int A[], int n);
void CreateHeap() // n log n
{
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 2; i <= 7; i++)
    {
        Insert(A[i], i);
    }
}

void Insert(int A[], int n) // log n
{
    int i = n;
    int temp = A[n];

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2]; // swap element with new element which bigger than it
        i = i / 2;
    }
    A[i] = temp;
}

void Delete(int A[], int n) // n log n
{
    int i, j;        // we can delete in heap from only the first place (the biggest element)
    int temp = A[n]; // imagine the first element is deleted ... became the first place in heap empty so we need rearrange the array of heap
    A[1] = A[n];     // swap the first element with the last element ..start rearranging

    i = 1;
    j = 2 * i;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j]) // compare the left child with right child for each parent to select the bigger
            j = j + 1;       // if the next is bigger ..

        if (A[i] < A[j]) // compare each parent with his bigger child
        {
            swap(A[i], A[j]); // if child is bigger than his parent swap his place with it
            i = j;
            j = 2 * j; // move to the next parent
        }
        else
            break; // Heap became in correct arrange
    }
    A[n] = temp;
}

void Heapify(int A[], int n)                //O(n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        int j = 2 * i + 1; // Left child for current i

        while (j < n - 1)
        {
            // Compare left and right children of current i
            if (A[j] < A[j + 1])
            {
                j = j + 1;
            }

            // Compare parent and largest child
            if (A[i] < A[j])
            {
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}