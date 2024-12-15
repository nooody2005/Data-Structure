#include <stdio.h>
#include "Hash.h"

#define SIZE 10

int hash(int key)
{
    return key % SIZE;                      // return the first digit in the number key
}                                       
int prob(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0)      //get the closet empty place after index
        i++;
    return (index + i) % SIZE;              //return the index of empty place
}
void InsertH(int H[], int key)
{
    int index = hash(key);                  

    if (H[index] != 0)                      //if index is not empty 
        index = prob(H, key);               //search for the closet empty place after index
    H[index] = key;                         // then insert
}
int SearchH(int H[], int key)
{
    int index = hash(key);

    int i = 0;

    while (H[(index + i) % SIZE] != key)    //if key not founded .. search places after its index
        i++;

    return (index + i) % SIZE;              //return index
}

