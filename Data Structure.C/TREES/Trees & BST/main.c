#include <stdio.h>
#include "Tree.c"


void visit(Tree_entry entry) 
{
    printf("%d ", entry);
}

int main()
{
    Tree t;
    CreateTree(&t);
}