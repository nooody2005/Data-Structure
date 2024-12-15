#include <stdio.h>

struct Diagonal
{
    int A[10];
    int n;
};
 
void Set (struct Diagonal *m, int i ,int j ,int x)
{
    if (i==j) 
    m->A[i-1] =x;
}

int Get (struct Diagonal *m ,int i ,int j )
{
    if (i==j) 
    return m->A[i-1];
    else 
    return 0;
}

void display (struct Diagonal *m)
{
    int i , j;
    for (i=0; i<m->n; i++)
    {
        for (j=0; j<m->n; j++)
        {
            if (i==j)
            {
                printf("%d  ",m->A[i]);
            }
            else 
            {
                printf("0  ");
            }
        }
        printf("\n");
    }
}

int main ()
{
    struct Diagonal m;
    m.n=5;
    Set(&m ,1,1,1);
    Set(&m ,2,2,2);
    Set(&m ,3,3,3);
    Set(&m ,4,4,4);
    Set(&m ,5,5,5);
  
    display(&m);
    printf("\n");
    printf("%d",Get(&m ,5,5));
   
}