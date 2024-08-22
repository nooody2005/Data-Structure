/*1- Bubble Sort:
Implement a function that takes in an array and returns
the sorted version of this array using bubble sort
algorithm.*/

#include <stdio.h>

void bubbleSort(int arr[], int n) 
{
    int i, j;
    for (i = 0; i < n-1; i++) 
    {
        for (j = 0; j < n-i-1; j++) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[], int n) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {0, 1, 6 ,5 ,9 ,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    print(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: \n");
    print(arr, n);
    
    return 0;
}
