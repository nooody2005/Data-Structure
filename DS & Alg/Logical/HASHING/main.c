#include "Hash.c"
#include "Chaining.c"

int main()
{
    List_node *HT[10];
    List_node *temp;
    int i;

    for (i = 0; i < 10; i++)
        HT[i] = NULL;

    InsertC(HT, 12);
    InsertC(HT, 22);
    InsertC(HT, 42);

    temp = SearchC(HT[hash(21)], 21);

    printf("%d ", temp->entry);

    return 0;
}