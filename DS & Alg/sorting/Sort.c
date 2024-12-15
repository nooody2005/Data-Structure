#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // For INT32_MIN
#include "Sort.h"
#include "../physical/LINKED_LISTS/Linked Lists/LinkedList.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// adaptive and stable (when the element wanted to be sorted is equal to any element in the array the original order is stable not differ )
void Bubble_Sort(int A[], int n) // make the array sorted
{                                // num of swap for the worst case =O(n^2)
    int i, j, flag = 0;          // num of swap for the best case =O(1)
                                 // num of Comp.. of the worst case =O(n^2)
    for (i = 0; i < n - 1; i++)  // num of comp for the best case =O(n) ..so it is adaptive
    {                            //..if the array is already sorted the first loop for j just will made itterations = n-1 and break
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (!flag)
            break; // already sorted ---> best case --> O(n)
    }
}

// adaptive and stable
void Insertion_Sort(int A[], int n) // shift ---> to insert a new element with maintaining order sorted
{                                   // for lists
    int i, j, x;                    // num of swap for the worst case =O(n^2)
    for (i = 1; i < n; i++)         // num of swap for the best case =O(1) ..so it is adaptive
    {                               // num of Comp.. of the worst case =O(n^2)
        j = i - 1;                  // num of comp for the best case =O(n)
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// not adaptive and not stable (when 2 elements are equal the next order may differ from the original order in any loop)
void Selection_Sort(int A[], int n) // useful for swap
{                                   // num of swap for worst case = O(n)
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        // if (k!=i)           //avoid unnecessary swaps  --> this check makes code Adaptive to unnecessary swaps
        //  if array is already sorted this check made it skip swap --> make code better
        swap(&A[i], &A[k]);
    }
}

//  each partition call takes O(n) time.
// There are O(log n) recursive levels (in the best case).
// Therefore, the total time complexity of Quick Sort in the best case is O(n log n).

// the worst case when the array is already sorted or reverse sorted is O(n^2)

int Partition(int A[], int l, int h) // partion function
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot && i <= h); // i ---> stop when it reaches element greater than pivot
        do
        {
            j--;
        } while (A[i] > pivot); // j ---> stop when it reaches element smaller than pivot

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[l], &A[j]);

    return j; // position of pivot
}

// n log n  ===??       n for calling (partition function) .....   log n -->  for calling (Quick_Sort)  in the best case
void Quick_Sort(int A[], int l, int h) // l --> low ...  h--> high
{                                      // best case = n log n   --> when partition in the middle
    int j;                             // worst case = n^2      --> when already sorted
    if (l < h)
    {
        j = Partition(A, l, h);  // to get position of pivot
        Quick_Sort(A, l, j);     // between elements berfore pivot .. from low to pivot      //Log(n) of 2
        Quick_Sort(A, j + 1, h); // between elements after pivot   .. from pivot to high
    }
}

// difference between Quick_Sort and Selection
// Selection ====> select the position  --> then find out the element for this position  .. select ( Index )
// Quick Sort ===> select the element   --> then find out the position for that element  ..select ( element)

// merge 2 sorted lists
//  O(n+m)
void Merge(int A[], int B[], int n, int m) // n --> length of A  ..  m ---> length of B
{
    int l = n + m; // l ---> length of merged array
    int arr[l];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            arr[k++] = A[i++];
        }
        else
        {
            arr[k++] = B[j++];
        }
    }

    while (i < n)
    {
        arr[k++] = A[i++];
    }
    while (j < m)
    {
        arr[k++] = B[j++];
    }
}

// to merge single array .. need extra array ..merging not in place
// O(n)
void Merge_sort(int A[], int l, int mid, int h) // l-->low .. h --> high
{
    int i = l, j = mid + 1;
    int B[h + 1]; // extra array we need it
    int k = l;    // k iterate for extra array

    while (i <= mid && j <= h)
    {
        if (A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= h)
    {
        B[k++] = A[j++];
    }

    // Copy the sorted elements back to the original array
    for (int x = l; x <= h; x++)
    {
        A[x] = B[x];
    }
}

void Recusive_Merge_Sort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        Recusive_Merge_Sort(A, l, mid);
        Recusive_Merge_Sort(A, mid + 1, h);
        Merge_sort(A, l, mid, h); // Merge single array
    }
}

// we can use (merge_sort) function for single array for sorting array assumming each element in array like list
// O(n log n)

/*void Iterative_merge_sort(int A[], int n)     //there are few fixes...
{
    int p;
    for (p = 2; p <= n; p = p * 2)
    {
        for (int i = 0; i + p - 1 < n; i = i + p)
        {
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;
            merge_sort(A, low, mid, high); // n
        }
    }
    if (p / 2 < n)
        Merge_sort(A, 0, p / 2 - 1, n - 1); // after merge all lists .. must check sort like single array
}*/

void Iterative_merge_sort(int A[], int n)
{
    int p;
    for (p = 1; p < n; p *= 2) // Start with size 1, then 2, 4, 8, ...
    {
        for (int i = 0; i + p < n; i += 2 * p) // Merge every pair of subarrays
        {
            int low = i;
            int mid = i + p - 1;
            int high = (i + 2 * p - 1 < n - 1) ? (i + 2 * p - 1) : (n - 1); // Don't go out of bounds
            Merge_sort(A, low, mid, high);
        }
    }
}

void IMergeSort(int A[], int n) // updated
{
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge_sort(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge_sort(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        Merge_sort(A, 0, p / 2 - 1, n - 1);
    }
}

int Find_Max(int A[], int n)
{
    int max = INT32_MIN; // minimum value for integer
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
// it's faster and easier but .. more consuming memory
void Count_sort(int A[], int n) // O(n)
{
    int i, j, max, *c;
    max = Find_Max(A, n);
    c = (int *)malloc(sizeof(int) * (max + 1)); // freq ..size of array is = max number of elements

    for (i = 0; i < max + 1; i++) // initialize ferq array
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        c[A[i]]++;
    }

    i = 0;
    j = 0;
    while (j < max + 1)
    {
        if (c[j] > 0) // index (j) = A[i] ...
        {
            A[i++] = j; // after sorting freq of each element .. copy index(j =A[i]) to array
            c[j]--;     // decrement freq of each element
        }
        else
            j++;
    }
}

// it used in LinkedList... taking alot of extra space
void Bin_Sort(int A[], int n) // O(n)
{
    int i, j, max;
    max = Find_Max(A, n);
    int **Bins; // array of lists (nodes) .. each element of array may contains num of nodes
    Bins = (int *)malloc(sizeof(int) * (max + 1));

    for (i = 0; i < max + 1; i++)
    {
        Bins[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        Insert(Bins[A[i]], A[i]); // insert array of Bins in index(A[i])
    }

    i = 0;
    j = 0;
    while (i < max + 1) // O(n) although nested loop but ... delete..
    {
        while (Bins[i] != NULL)
        {
            A[j++] = Delete(Bins[i]);
        }
        i++;
    }
}

// To make (bin sort) simple ..introduce (Radix Sort)
//  bin sort will be a problem in the large numbers .. imagine you make an array of nodes ..size = the largest element

//===============================================================================================================================

int getBinIndex(int x, int idx)
{
    return (int)(x / pow(10, idx)) % 10;
}

void initializeBins(List_node **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = NULL;
    }
}

void InsertBin(List_node **ptrBins, int value, int idx)
{
    List_node *temp = (List_node *)malloc(sizeof(List_node));
    temp->entry = value;
    temp->next = NULL;

    if (ptrBins[idx] == NULL)
    {
        ptrBins[idx] = temp; // ptrBins[idx] is head ptr
    }
    else
    {
        List_node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int DeleteBin(List_node **ptrBins, int idx)
{
    List_node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->entry;
    free(p) ;
    return x;
}

void RadixSort(int A[], int n)          // O(dn)
{
    int max = Max(A, n);
    int nPass = countDigits(max);

    // Create bins array
    List_node **bins = (List_node *)malloc(sizeof(List_node) * 10);

    // Initialize bins array with nullptr
    initializeBins(bins, 10);

    // Update bins and A for nPass times
    for (int i = 0; i < nPass; i++)
    {

        // Update bins based on A values
        for (int j = 0; j < n; j++)
        {
            int binIdx = getBinIndex(A[j], i);
            InsertBin(bins, A[j], binIdx);
        }

        // Update A with sorted elements from bin
        int i = 0;
        int j = 0;
        while (i < 10)
        {
            while (bins[i] != NULL)
            {
                A[j++] = DeleteBin(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }

    // Delete heap memory
    free(bins);
}
 
//==========================================================================================================================

void Shell_Sort(int A[], int n)         //O(n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap; // j start the first element (when i= gap) ..

            while (j >= 0 && A[j] > temp) // if element in the start of the array > temp (element in the end of the array  (after gap)) ..
            {
                A[j + gap] = A[j]; // A[j+gap] = A[i] (temp) ---->  A[j]
                j = j - gap;       // if (j > gap ) make this operation otherwise skip ..
            }
            A[j + gap] = temp; // A[i] ----> temp (A[j])
        } // swap elements before gap with elements after gap (if before > after)
    }
}
