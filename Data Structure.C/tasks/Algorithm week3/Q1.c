/*1- Merge Sort:
Implement a function that takes in an array and returns
the sorted version of this array using Merge sort
algorithm.
*/


#include <stdio.h>

#define MAX_SIZE 1000  


void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[MAX_SIZE];
    int R[MAX_SIZE];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    // Merge the temporary arrays arr[left  -- right]
    int i = 0; // first subarray
    int j = 0; // second subarray
    int k = left; // merged subarray

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k++] = L[i++];
        } 
        else 
        {
            arr[k++] = R[j++];
        }
    }

    // Copy remaining elements of L[], if any
    while (i < n1) 
    {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[], if any
    while (j < n2) 
    {
        arr[k++] = R[j++];
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) 
    {
        printf("Array size exceeds maximum size of %d.\n", MAX_SIZE);
        return 1; 
    }

    int arr[MAX_SIZE];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
