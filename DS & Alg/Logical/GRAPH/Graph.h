#include "../QUEUE/Queue_array/Queue.h"
#ifndef _GRAPH_
#define _GRAPH_

#define I __INT32_MAX__

void BFS(int G[][7], int start, int n);
void DFS(int G[][7], int start, int n);
//=========================================================

int cost[][8] =
    {
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 15, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };

int near[8] = {I, I, I, I, I, I, I, I};
int t1[2][7];


void Primis();
//==========================================================

int edges[3][9] =
    {
        {1,1,2,2,3,4,4,5,5},    
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,18,16,14,20,18} //size of path between 2 num in the above indexes
    };

int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] ={0};
int t2[2][6];

void Union(int u, int v);
int find(int u);
void Kurskal();

#endif