#include <stdio.h>
#include <stdlib.h>

struct Array
{
   // int *A;   
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)      // arr  ( . )     or   *arr ( -> ) 
{
    int i;
    printf("\n elements \n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr ->length++] = x;
    }
}

void Insert(struct Array *arr ,int index ,int x)
{
    int i;
    if (index >=0 && index <= arr->length)
    {
        for (i = arr->length; i >index; i--)
        {
            arr->A[i] = arr->A[i-1];        //shift
        }
        arr->A[index] =x;
        arr->length++;
    }
}

int delete(struct Array *arr ,int index )
{
    int i;
    int x=0;
    if (index>=0 && index <= arr->length)
    {
        x=arr->A[index];
        for (i=index; i<arr->length-1 ;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr ,int key)
{
    int i;
    for (i=0 ; i<arr->length ;i++ )
    {
        if (key == arr->A[i])  
        {
            swap(&arr->A[i], &arr->A[i-1]);  //for improving next searching for the same element
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr ,int key)
{
    int l ,mid ,h;          //low   mid  high

    l = 0;      
    h = arr->length-1;

    while(l<=h)
    {
        mid =(l+h)/2;
        if (key == arr->A[mid])     return mid;
        else if (key < arr->A[mid]) h=mid-1;
        else if (key > arr->A[mid]) l=mid+1; 
    }
    return -1;

}

int BinarySearch_UsingRecursion(struct Array *arr ,int l ,int h,int key)
{
    int mid;
   
    if(l<=h)
    {
        mid =(l+h)/2;
        if (key == arr->A[mid])     
        return mid;

        else if (key < arr->A[mid]) 
        return BinarySearch_UsingRecursion(arr,l,mid-1,key);

        else if (key > arr->A[mid])  
        return BinarySearch_UsingRecursion(arr,mid+1,h,key);
    }
    return -1;

}

int Set(struct Array *arr,int index ,int x)
{
    if (index >=0 && index <= arr->length)
    {
       return  arr->A[index]=x;
    }
    return -1;
}

int get (struct Array *arr,int index )
{
    if(index >=0 && index <= arr->length)
    {
        return arr->A[index];
    }
    return -1;
}

int Max(struct Array *arr)
{
    int max =arr->A[0];
    for (int i=1 ;i<arr->length;i++)
    {
        if (arr->A[i] >max)  max = arr->A[i];
    }
    return max;
}

int Min(struct Array *arr)
{
    int min =arr->A[0];
    for (int i=1 ;i<arr->length;i++)
    {
        if (arr->A[i] < min)  min = arr->A[i];
    }
    return min;
}

int Sum(struct Array *arr)
{
    int sum =0;
    for (int i=0 ;i<arr->length;i++)
    {
        sum += arr->A[i];
    }
    return sum;        // Average = n/arr->length
}

int Sum_recursion(struct Array *arr, int n)
{
    if (n<0)  
    return 0;
    else    
    return Sum_recursion(arr ,n-1) + arr->A[n];
    
}

float Average(struct Array *arr)
{
    return (float)Sum(arr) / arr->length;
}

void reverse1(struct Array *arr)
{
    for (int i=0 ,j=arr->length-1 ; i<j  ;i++,j--)
    {
        swap(&arr->A[j],&arr->A[i]);
    }
}

void reverse(struct Array *arr)
{
    int *B =(int *)malloc(arr->length *sizeof (int));
    
    for (int i=arr->length-1 ,j=0  ; i>=0  ;i--,j++)
    {
        B[j]=arr->A[i];
    }

    for(int i=0 ;i<arr->length ; i++)
    {
        arr->A[i]=B[i];         //copy reversed array to the original array
    }
}

int isSorted (struct Array *arr)
{
    for (int i=0; i<arr->length-1 ; i++)
    {
        if (arr->A[i] >arr->A[i+1]) return 0;  //not sorted
    }
    return 1;   //is sorted
}

void Insert_Sort (struct Array *arr ,int x)
{
    int i =arr->length -1;
    if (arr->length == arr->size)  return ;

    while (i>=0 && arr->A[i] >x)
    {
        arr->A[i+1] =arr->A[i];
        i--;
    }
//x > arr->A[i]  ---> x is bigger than the previous element arr->A[i] 
//and smaller than the next element arr->A[i+1] that the reason to stop while loop
    arr->A[i+1] = x;  
    arr->length++;
}

void ReArrange_Sort (struct Array *arr)
{
    int i=0 ,j=arr->length-1;

    while (i<j)
    {
        while (arr->A[i] <0)    i++;
        
        while (arr->A[j] >0)    j--;

        if (i<j)    swap(&arr->A[i],&arr->A[j]);

    }

}

struct Array* merge (struct Array *arr ,struct Array *arr2)
{   // merge 2 sorted arrays  --->  1 sorted array
    int i ,j ,k;
    i=j=k;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

    while (i<arr->length  && j<arr2->length)
    {
        if (arr->A[i] < arr2->A[j]) 
        arr3->A[k++] =arr->A[i++];

        else 
        arr3->A[k++] =arr2->A[j++];
    }

        // Copy remaining elements 
    while (i < arr->length)
        arr3->A[k++] = arr->A[i++];

    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = arr->size + arr2->size;

    return arr3;
}

struct Array* Union (struct Array *arr ,struct Array *arr2)
{   // merge 2 sorted arrays  --->  1 sorted array  without reapeted elements
    int i ,j ,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

    while (i<arr->length  && j<arr2->length)
    {
        if (arr->A[i] < arr2->A[j]) 
        arr3->A[k++] =arr->A[i++];

        else if (arr->A[i] > arr2->A[j])  
        arr3->A[k++] =arr2->A[j++];

       else 
       {
            arr3->A[k++] =arr->A[i++];
            j++;            //skip reapeted element
       }
    }

        // Copy remaining elements 
    while (i < arr->length)
        arr3->A[k++] = arr->A[i++];

    while (j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = arr->size + arr2->size;

    return arr3;
}

struct Array* Intersect (struct Array *arr ,struct Array *arr2)
{  
    int i ,j ,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

    while (i<arr->length  && j<arr2->length)
    {
        if (arr->A[i] < arr2->A[j]) 
        i++;

        else if (arr->A[i] > arr2->A[j])  
        j++;

        else if (arr->A[i] == arr2->A[j])
       {
            arr3->A[k++] =arr->A[i++];
            j++;            //skip reapeted element
       }
    }

        

    arr3->length = k;
    arr3->size = arr->size + arr2->size;

    return arr3;
}

struct Array* diff (struct Array *arr ,struct Array *arr2)  //diff =arr -arr2
{   // make  array contians elements from the first array that not repeated in the second array
    int i ,j ,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

    while (i<arr->length  && j<arr2->length)
    {
        if (arr->A[i] < arr2->A[j]) 
        arr3->A[k++] =arr->A[i++];

        else if (arr->A[i] > arr2->A[j])  
        j++;

        else
        {
            i++; j++;            //skip reapeted element
        }
    }

    // Copy remaining elements from the first array 
    while (i < arr->length)
        arr3->A[k++] = arr->A[i++];



    arr3->length = k;
    arr3->size = arr->size + arr2->size;

    return arr3;
}


int main()
{
    struct Array arr1;
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr1.size = size;
    arr1.length = 0;

    int length;
    printf("Enter the number of elements you want to append: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++)
    {
        int element;
        printf("Enter element %d: ", (i + 1));
        scanf("%d", &element);
        Append(&arr1, element);
    }

    printf("______________ MENU ________________\n");
    printf("|         1. Insert                  |\n");
    printf("|         2. Delete                  |\n");
    printf("|         3. Search                  |\n");
    printf("|         4. Display                 |\n");
    printf("|         9. Reverse Array           |\n");
    printf("|        10. Sum of Elements         |\n");
    printf("|        11. Is Array Sorted?        |\n");
    printf("|        12. Get Max Element         |\n");
    printf("|        13. Get Min Element         |\n");
    printf("_____________________________________\n");

    int ch;
    printf("Enter your choice: ");
    scanf("%d", &ch);

    int x, index;

    switch (ch)
    {
    case 1:
        // Insert an element at a specific index
        printf("Enter element and index: ");
        scanf("%d%d", &x, &index);
        Insert(&arr1, index, x);
        display(arr1);
        break;

    case 2:
        // Delete an element at a specific index
        printf("Enter the index of the element to delete: ");
        scanf("%d", &index);
        x = deleteElement(&arr1, index); // Delete and get the deleted element
        printf("Deleted element: %d\n", x);
        display(arr1);
        break;

    case 3:
        // Search for an element using Binary Search
        printf("Enter element to search for: ");
        scanf("%d", &x);
        index = BinarySearch(&arr1, x);
        if (index != -1)
            printf("Element found at index: %d\n", index);
        else
            printf("Element not found\n");
        break;

    case 4:
        // Display the array
        display(arr1);
        break;

    case 9:
        // Reverse the array
        reverse(&arr1);
        printf("Reversed array: ");
        display(arr1);
        break;

    case 10:
        // Sum of array elements
        printf("Sum of elements: %d\n", Sum(&arr1));
        break;

    case 11:
        // Check if array is sorted
        if (isSorted(&arr1))
            printf("The array is sorted.\n");
        else
            printf("The array is not sorted.\n");
        break;

    case 12:
        // Get the maximum element
        printf("Max element: %d\n", Max(&arr1));
        break;

    case 13:
        // Get the minimum element
        printf("Min element: %d\n", Min(&arr1));
        break;

    default:
        printf("Invalid choice!\n");
    }

    return 0;
}