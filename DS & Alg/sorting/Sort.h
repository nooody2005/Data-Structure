#ifndef __SORT

void swap(int *x ,int *y);
void Bubble_Sort(int A[], int n);                   //O(n^2)
void Insertion_Sort(int A[], int n);                //O(n^2)
void Selection_Sort(int A[], int n);                //O(n^2)

int Partition(int A[], int l ,int h); 
void Quick_Sort(int A[], int l ,int h);             //O(n log n)
void Merge(int A[], int B[], int n, int m);         //O(n log n)
void Merge_sort(int A[], int l, int mid, int h);
void Recusive_Merge_Sort(int A[] ,int l , int h);   //O(n log n)
void Iterative_merge_sort(int A[], int n);          //O(n log n)
void IMergeSort(int A[], int n);
int Find_Max(int A[], int n);
void Count_sort(int A[] , int n);                   //O(n)
void Bin_Sort(int A[], int n);                      //O(n)
//===========================================================
int getBinIndex(int x, int idx);
void initializeBins(List_node **p, int n);
void InsertBin(List_node **ptrBins, int value, int idx);
int DeleteBin(List_node **ptrBins, int idx);
void RadixSort(int A[], int n);                     // O(n)
//===========================================================
void Shell_Sort(int A[], int n);                    //O(n)




#endif