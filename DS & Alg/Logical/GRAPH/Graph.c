#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void BFS(int G[][7], int start, int n)
{
    int i = start;
    Queue *q;
    int visited[7] = {0};

    printf("%d ", i);

    visited[i] = 1;
    EnQueue(i, q);

    while (!Queue_Empty(q))
    {
        i = DeQueue2(q);
        for (int j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                EnQueue(j, q);
            }
        }
    }
}

void DFS(int G[][7], int start, int n) // iterative
{
    static int visited[] = {0};
    int j = 0;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited == 0)
            {
                DFS(G, j, n);
            }
        }
    }
}

//================ Spaning Tree ===================

void Primis()
{
    int i, j, k, u, v, n = 7, min = I;

    for (i = 1; i <= n; i++) // get the minimum element to start with ..
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i, v = j;
            }
        }
    }

    t1[0][0] = u, t1[1][0] = v; // write down the index for the min..  element
    near[u] = near[v] = 0;      // it means this index it was visited ..

    for (i = 1; i <= n; i++)
    {
        if (near[i] != 0 && cost[i][u] < cost[i][v]) // ele.. not vsited && compare between elements are connected in this index
        {
            near[i] = u; // write down the visited index for the min.. element
        }
        else // if 2 elements (are connected) are equaled .. write down the visited index for any element..
        {
            near[i] = v;
        }
    }

    for (i = 1; i < n - 1; i++)
    {
        min = I;
        for (j = i; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }

        t1[0][i] = k;
        t1[1][i] = near[k];
        near[k] = 0;

        for (j = i; j <= n; j++)
        {
            if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
            {
                near[j] = k;
            }
        }
    }
}

//====================

void Union(int u, int v)
{
    if (set[u] < set[v]) // parent is minus(-) (sum of its children)
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u;
    while (set[x] > 0) // if it is child(+)
    {
        x = set[x];
    }
    return x;
}

void Kurskal()
{
    int i =0 ,j ,k , n=7 ,e=9 , min ,u ,v;

    while(i <n-1)
    {
        min = I;
        for (j=0 ; j<e ;j++)
        {
            if (included [j] == 0 && edges[2][j] <min)
            {
                min = edges[2][j];
                k=j;                                //index  of the min.. path (in index row 2) between 2 num.s..
                u = edges[0][j] ; v= edges[1][j];   // 2 num.s..
            }
        }
    }
    
    if (find(u)!=find(v))   
    {
        t2[0][i] =u ,t2[1][i]=v;
        Union(find(u),find(v));
        i++;
    }
    included[k];
    
}