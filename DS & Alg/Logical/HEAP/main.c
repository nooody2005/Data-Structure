#include "Heap.c"

int main()
{

    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Printf(A, sizeof(A) / sizeof(A[0]), "A");

    Heapify(A, sizeof(A) / sizeof(A[0]));
    Printf(A, sizeof(A) / sizeof(A[0]), "Heapified A");
    printf("\n");

    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B) / sizeof(B[0]), "B");

    Heapify(B, sizeof(B) / sizeof(B[0]));
    Print(B, sizeof(B) / sizeof(B[0]), "Heapified B");

    return 0;
}