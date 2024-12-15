/*2-Binarry Search
2.1 Implement a function that performs binary search
algorithm using a recursive approach.
2.2 Implement a function that performs binary search
algorithm using Iterative approach.*/


#include <stdio.h>


// Recursive Binary Search
int reSearch(int arr[], int left, int right, int target) 
{
    if (right >= left) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return reSearch(arr, left, mid - 1, target);

        return reSearch(arr, mid + 1, right, target);
    }

    // Element is not exit in the array
    return -1;
}



// Iterative Binary Search 
int iterativeSearch(int arr[], int n, int target) 
{
    int left = 0, right = n - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}


int main() 
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int type , result;
    printf("Enter 1 for recursive binary search or 2 for iterative binary search: ");
    scanf("%d", &type);


    if (type == 1 )   //for recursive binary search
    {
        result = reSearch(arr, 0, n - 1, target);
    }

    else if (type == 2)  //for iterative binary search
    {
        result = iterativeSearch(arr, n, target);
    }
     else
    {
        printf("Invalid option.\n");
        return 1; 
    }


    if (result != -1)
        printf("Element is exit at index %d\n", result);
    else
        printf("Element is not exit in array\n");

    return 0;
}

