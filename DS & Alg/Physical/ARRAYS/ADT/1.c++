#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Array
{
    // public:
private:
    int *A;
    int size;
    int length;

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int _size)
    {
        size = _size;
        length = 0;
        A = new int[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    int BinarySearch(int key)
    {
        int l, mid, h; // low   mid  high

        l = 0;
        h = length - 1;

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
                return mid;
            else if (key < A[mid])
                h = mid - 1;
            else if (key > A[mid])
                l = mid + 1;
        }
        return -1;
    }

    int BinarySearch_UsingRecursion(int l, int h, int key)
    {
        int mid;

        if (l <= h)
        {
            mid = (l + h) / 2;
            if (key == A[mid])
                return mid;

            else if (key < A[mid])
                return BinarySearch_UsingRecursion(l, mid - 1, key);

            else if (key > A[mid])
                return BinarySearch_UsingRecursion(mid + 1, h, key);
        }
        return -1;
    }

    int Set(int index, int x)
    {
        if (index >= 0 && index <= length)
        {
            return A[index] = x;
        }
        return -1;
    }

    int get(int index)
    {
        if (index >= 0 && index <= length)
        {
            return A[index];
        }
        return -1;
    }

    int Max()
    {
        int max = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] > max)
                max = A[i];
        }
        return max;
    }

    int Min()
    {
        int min = A[0];
        for (int i = 1; i < length; i++)
        {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }

    int Sum()
    {
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            sum += A[i];
        }
        return sum; // Average = n/arr->length
    }

    int Sum_recursion(int n)
    {
        if (n < 0)
            return 0;
        else
            return Sum_recursion(n - 1) + A[n];
    }

    float Average()
    {
        return (float)Sum() / length;
    }

    void reverse1()
    {
        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            swap(&A[j], &A[i]);
        }
    }

    void reverse()
    {
        // int *B = (int *)malloc(arr->length * sizeof(int));
        int *B = new int[length * sizeof(int)];

        for (int i = length - 1, j = 0; i >= 0; i--, j++)
        {
            B[j] = A[i];
        }

        for (int i = 0; i < length; i++)
        {
            A[i] = B[i]; // copy reversed array to the original array
        }
    }

    int isSorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
                return 0; // not sorted
        }
        return 1; // is sorted
    }

    void Insert_Sort(int x)
    {
        int i = length - 1;
        if (length == size)
            return;

        while (i >= 0 && A[i] > x)
        {
            A[i + 1] = A[i];
            i--;
        }
        // x > arr->A[i]  ---> x is bigger than the previous element arr->A[i]
        // and smaller than the next element arr->A[i+1] that the reason to stop while loop
        A[i + 1] = x;
        length++;
    }

    void ReArrange_Sort()
    {
        int i = 0, j = length - 1;

        while (i < j)
        {
            while (A[i] < 0)
                i++;

            while (A[j] > 0)
                j--;

            if (i < j)
                swap(&A[i], &A[j]);
        }
    }

    Array *merge(Array *arr2)
    { // merge 2 sorted arrays  --->  1 sorted array
        int i, j, k;
        i = j = k;
        // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
        Array *arr3 = new Array[sizeof(Array)];

        while (i < length && j < arr2->length)
        {
            if (A[i] < arr2->A[j])
                arr3->A[k++] = A[i++];

            else
                arr3->A[k++] = arr2->A[j++];
        }

        // Copy remaining elements
        while (i < length)
            arr3->A[k++] = A[i++];

        while (j < arr2->length)
            arr3->A[k++] = arr2->A[j++];

        arr3->length = k;
        arr3->size = size + arr2->size;

        return arr3;
    }

    Array *Union(Array *arr2)
    { // merge 2 sorted arrays  --->  1 sorted array  without reapeted elements
        int i, j, k;
        i = j = k = 0;
        // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
        Array *arr3 = new Array[sizeof(Array)];

        while (i < length && j < arr2->length)
        {
            if (A[i] < arr2->A[j])
                arr3->A[k++] = A[i++];

            else if (A[i] > arr2->A[j])
                arr3->A[k++] = arr2->A[j++];

            else
            {
                arr3->A[k++] = A[i++];
                j++; // skip reapeted element
            }
        }

        // Copy remaining elements
        while (i < length)
            arr3->A[k++] = A[i++];

        while (j < arr2->length)
            arr3->A[k++] = A[j++];

        arr3->length = k;
        arr3->size = size + arr2->size;

        return arr3;
    }

    Array *Intersect(Array *arr2)
    {
        int i, j, k;
        i = j = k = 0;

        // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
        Array *arr3 = new Array[sizeof(Array)];

        while (i < length && j < arr2->length)
        {
            if (A[i] < arr2->A[j])
                i++;

            else if (A[i] > arr2->A[j])
                j++;

            else if (A[i] == arr2->A[j])
            {
                arr3->A[k++] = A[i++];
                j++; // skip reapeted element
            }
        }

        arr3->length = k;
        arr3->size = size + arr2->size;

        return arr3;
    }

    Array *diff(Array *arr2) // diff =arr -arr2
    {                        // make  array contians elements from the first array that not repeated in the second array
        int i, j, k;
        i = j = k = 0;

        // struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
        Array *arr3 = new Array[sizeof(Array)];

        while (i < length && j < arr2->length)
        {
            if (A[i] < arr2->A[j])
                arr3->A[k++] = A[i++];

            else if (A[i] > arr2->A[j])
                j++;

            else
            {
                i++;
                j++; // skip reapeted element
            }
        }

        // Copy remaining elements from the first array
        while (i < length)
            arr3->A[k++] = A[i++];

        arr3->length = k;
        arr3->size = size + arr2->size;

        return arr3;
    }

    void display();
    void Append(int x);
    void Insert(int index, int x);
    int deleteElement(int index);
};

void Array ::display() // arr  ( . )     or   *arr ( -> )
{
    int i;
    printf("\n elements \n");
    for (i = 0; i < length; i++)
        printf("%d ", A[i]);
}

void Array ::Append(int x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}

void Array ::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i - 1]; // shift
        }
        A[index] = x;
        length++;
    }
}

int Array ::deleteElement(int index)
{
    int i;
    int x = 0;
    if (index >= 0 && index <= length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}

// int main()       // if class is defined public
// {
//     Array *arr1;
//     cout <<"enter the size of the array :" << endl;
//     cin >> arr1->size;
//     arr1->A = new int (arr1->size * sizeof(int));
// }

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    Array arr1(size);

    int length;
    cout << "Enter the number of elements you want to append: ";
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        int element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        arr1.Append(element);
    }

    cout << "______________ MENU ________________\n";
    cout << "|         1. Insert                  |\n";
    cout << "|         2. Delete                  |\n";
    cout << "|         3. Search                  |\n";
    cout << "|         4. Display                 |\n";
    cout << "|         5. Merge Arrays            |\n";
    cout << "|         6. Union Arrays            |\n";
    cout << "|         7. Intersect Arrays        |\n";
    cout << "|         8. Difference of Arrays    |\n";
    cout << "|         9. Reverse Array           |\n";
    cout << "|        10. Sum of Elements         |\n";
    cout << "|        11. Is Array Sorted?        |\n";
    cout << "|        12. Get Max Element         |\n";
    cout << "|        13. Get Min Element         |\n";
    cout << "_____________________________________\n";

    int ch;
    cout << "Enter your choice: ";
    cin >> ch;

    int x, index;

    switch (ch)
    {
    case 1:
        // Insert an element at a specific index
        cout << "Enter element and index: ";
        cin >> x >> index;
        arr1.Insert(index, x);

        break;

    case 2:
        // Delete an element at a specific index
        cout << "Enter the index of the element to delete: ";
        cin >> index;
        x = arr1.deleteElement(index); // Delete and get the deleted element
        cout << "Deleted element: " << x << endl;
 
        break;

    case 3:
        // Search for an element using Binary Search
        cout << "Enter element to search for: ";
        cin >> x;
        index = arr1.BinarySearch(x);
        if (index != -1)
            cout << "Element found at index: " << index << endl;
        else
            cout << "Element not found" << endl;
        break;

    case 4:
        // Display the array
        arr1.display();
        break;

    case 5:
    {
        // Merge two arrays
        cout << "Enter the size of the second array: ";
        cin >> size;
        Array arr2(size);
        cout << "Enter elements of second array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            arr2.Append(x);
        }

        Array *arr3 = arr1.merge(&arr2);
        cout << "Merged array: ";
        arr3->display();
        delete arr3;
        break;
    }

    case 6:
    {
        // Union of two arrays
        cout << "Enter the size of the second array: ";
        cin >> size;
        Array arr2(size);
        cout << "Enter elements of second array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            arr2.Append(x);
        }

        Array *arr3 = arr1.Union(&arr2);
        cout << "Union array: ";
        arr3->display();
        delete arr3;
        break;
    }

    case 7:
    {
        // Intersection of two arrays
        cout << "Enter the size of the second array: ";
        cin >> size;
        Array arr2(size);
        cout << "Enter elements of second array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            arr2.Append(x);
        }

        Array *arr3 = arr1.Intersect(&arr2);
        cout << "Intersection array: ";
        arr3->display();
        delete arr3;
        break;
    }

    case 8:
    {
        // Difference between two arrays
        cout << "Enter the size of the second array: ";
        cin >> size;
        Array arr2(size);
        cout << "Enter elements of second array:" << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> x;
            arr2.Append(x);
        }

        Array *arr3 = arr1.diff(&arr2);
        cout << "Difference array: ";
        arr3->display();
        delete arr3;
        break;
    }

    case 9:
        // Reverse the array
        arr1.reverse1();
        cout << "Reversed array: ";
        arr1.display();
        break;

    case 10:
        // Sum of array elements
        cout << "Sum of elements: " << arr1.Sum() << endl;
        break;

    case 11:
        // Check if array is sorted
        if (arr1.isSorted())
            cout << "The array is sorted." << endl;
        else
            cout << "The array is not sorted." << endl;
        break;

    case 12:
        // Get the maximum element
        cout << "Max element: " << arr1.Max() << endl;
        break;

    case 13:
        // Get the minimum element
        cout << "Min element: " << arr1.Min() << endl;
        break;

    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}


