
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "../../QUEUE/Queue_array/Queue.h"
#include "../../STACK/Stack_array/Stack.h"

void CreateTree(Tree *tree)
{
    *tree = NULL;
}

int Tree_Empty(Tree *tree)
{
    return !*tree;
}

int Tree_Full(Tree *tree)
{
    return 0;
}

void ClearTree(Tree *tree)
{
    if (*tree)
    {
        ClearTree(&(*tree)->left);
        ClearTree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

int TreeSize(Tree *tree)
{
    if (!*tree)
        return 0;

    return 1 + TreeSize(&(*tree)->left) + TreeSize(&(*tree)->right);
}

int TreeDepth(Tree *tree)
{
    if (!*tree)
        return 0;

    int a = TreeDepth(&(*tree)->left);
    int b = TreeDepth(&(*tree)->right);

    return (a > b) ? 1 + a : 1 + b;
}

void Insert_Recursion(Tree *pt, Tree_entry e)
{
    if (*pt == NULL)
    {
        *pt = (Tree)malloc(sizeof(Tree_node));
        if (*pt == NULL)
        {
            return;
        }
        (*pt)->entry = e;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else
    {
        if (e < (*pt)->entry)
        {
            Insert_Recursion(&(*pt)->left, e);
        }
        else
        {
            Insert_Recursion(&(*pt)->right, e);
        }
    }
}

void InsertNode(Tree *pt, Tree_entry e)
{
    Tree_node *t = (Tree_node *)malloc(sizeof(Tree_node));
    if (t == NULL)
    {
        return;
    }
    t->entry = e;
    t->left = NULL;
    t->right = NULL;

    if (!(*pt))
    {
        *pt = t;
    }
    else
    {
        Tree_node *pre = NULL, *cur = *pt;
        while (cur)
        {
            pre = cur;
            if (e < cur->entry)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (e < pre->entry)
            pre->left = t;
        else
            pre->right = t;
    }
}

void Delete_node(Tree *pt)
{
    // Deletion logic goes here
}

void inorder(Tree *tree, void (*pvisit)(Tree_entry))
{
    if (*tree)
    {
        inorder(&(*tree)->left, pvisit);
        (*pvisit)((*tree)->entry); // printf("%d",&(*tree)->entry);
        inorder(&(*tree)->right, pvisit);
    }
}

void preorder(Tree *tree, void (*pvisit)(Tree_entry))
{
    if (*tree)
    {
        (*pvisit)((*tree)->entry);
        preorder(&(*tree)->left, pvisit);
        preorder(&(*tree)->right, pvisit);
    }
}

void postorder(Tree *tree, void (*pvisit)(Tree_entry))
{
    if (*tree)
    {
        postorder(&(*tree)->left, pvisit);
        postorder(&(*tree)->right, pvisit);
        (*pvisit)((*tree)->entry);
    }
}

void Level_order(Tree *tree, void (*pvisit)(Tree_entry))
{
    Queue q;
    printf("%d", &(*tree)->entry);
    EnQueue(&q, &(*tree)->entry);
    while (!is_Empty(&q))
    {
        DeQueue(&(*tree), &q);
        if ((*tree)->left)
        {
            printf("%d", &(*tree)->left->entry);
            EnQueue(&q, (*tree)->left);
        }

        if ((*tree)->right)
        {
            printf("%d", &(*tree)->right->entry);
            EnQueue(&q, (*tree)->right);
        }
    }
}

//================================ Binary search =======================================
Tree_node *RSearch(Tree *tree, int key)
{
    if (*tree == NULL)
        return NULL;

    if (key == (*tree)->entry)
        return tree;

    else if (key < (*tree)->entry)
        return RSearch(&(*tree)->left, key);

    else
        return RSearch(&(*tree)->right, key);
}

void InserBinary(Tree *tree, int key)
{
    Tree_node *r = NULL, *p;
    while (tree != NULL)
    {
        r = tree;
        if (key == (*tree)->entry)
            return;

        else if (key < (*tree)->entry)
            tree = &(*tree)->left;

        else
            tree = (*tree)->right;
    }
    p = malloc(sizeof(Tree));
    p->left = p->right = NULL;

    if (p->entry < r->entry)
        r->left = p;
    else
        r->right = p;
}

Tree_node *Delete(Tree *tree, int key)
{
    
}

// void CreateTree(Tree *tree)
// {
//     *tree = NULL;
// }

// int Tree_Empty(Tree *tree)
// {
//     return (! *tree);
// }

// int tree_Full(Tree *tree)
// {
//     return 0;
// }

// void ClearTree(Tree *tree)
// {
//     if (! *tree)
//     {
//         ClearTree(&(*tree)->left);
//         ClearTree(&(*tree)->right);
//     }
//     free(*tree);
//     *tree = NULL;
// }

// int TreeSize(Tree *tree)
// {
//     if (! *tree)
//     return 0;

//     return (1 + TreeSize(&(*Tree)->left) + TreeSize(&(*Tree)->right) );

// }

// int TreeDepth(Tree *tree)
// {
//     if (! *tree)
//     return 0;

//     int a = TreeDepth(&(*Tree)->left);
//     int b = TreeDepth(&(*Tree)->right);

//     return (a>b) ? 1+a : 1+b ;
// }

// void Insert_Recursion(Tree *pt, Tree_entry e)   // recursion is STACK
// {
//     if (*pt == NULL)   // (!*pt) = (*pt == NULL)
//     {                                           // Create a new node if the tree is empty
//         *pt = (Tree)malloc(sizeof(Tree_node));    // (Tree) = (Tree_node *)
//         if (*pt == NULL)
//         {
//             return;
//         }
//         (*pt)->entry = e;
//         (*pt)->left = NULL;
//         (*pt)->right = NULL;
//     }
//     else
//     {
//         if (e < (*pt)->entry)         //Binary search tree
//         {                             // right > left
//             Insert_Recursion(&(*pt)->left, e);  //recursion is stack
//         }
//         else
//         {
//             Insert_Recursion(&(*pt)->right, e);
//         }
//     }
// }

// void InsertNode(Tree *pt, Tree_entry e)  //without stack so you can allocate  a new node in the first
// {                                        //without checking if NULL or not buz allocate it only one time
//     Tree_node *t = (Tree_node *)malloc(sizeof(Tree_node));
//      if (t == NULL)
//     {
//         // Handle memory allocation failure
//         return;
//     }
//     t->entry = e;
//     t->left = NULL;
//     t->right = NULL;

//     if (!(*pt))    // *pt == NULL  //if it is the first node
//     {
//         *pt = t ;
//     }
//     else
//     {
//         Tree_node *pre = NULL;
//         Tree_node *cur = *pt;
//         while (cur)
//         {
//             pre =cur;

//             if (e < cur->entry)     cur = cur->left;
//             else                    cur = cur->right;

//         }

//     }
//     // if current (cur) point to NULL (while is false)
//     // pre will point to new node that was allocated
//     if (e < pre->entry)         pre->left = t;
//     else                        pre->right= t;

// }

// void Delelete_node (Tree *pt)
// {

// }

// void inorder(Tree *tree,void (*pvisit)(Tree_entry))     // Traverse function (left + v + right)
// {
//     if ( *tree)
//     {
//         inorder(&(*tree)->left ,pvisit);
//         (*pvisit)((*tree)->entry);
//         inorder (&(*tree)->right ,pvisit);
//     }
// }

// void preorder(Tree *tree, void (*pvisit)(Tree_entry)) // Traverse function (v + left + right)
// {
//      if ( *tree)
//     {
//         (*pvisit)((*tree)->entry);
//         preorder(&(*tree)->left ,pvisit);
//         preorder (&(*tree)->right ,pvisit);
//     }
// }

// void postorder(Tree *tree, void (*pvisit)(Tree_entry))   // Traverse function (left + right + v)
// {
//     if ( *tree)
//     {
//         postorder(&(*tree)->left ,pvisit);
//         postorder (&(*tree)->right ,pvisit);
//         (*pvisit)((*tree)->entry);
//     }
// }

/*
void CreateTree(Tree *tree)
{
    tree->root = NULL;
    tree->size =0;
    tree->depth=0;
}

int Tree_Empty(Tree *tree)
{
    return (! tree->root);
}

int tree_Full(Tree *tree)
{
    return 0;
}

void ClearTree(Tree *tree)
{
    ClearTree(&tree->root);
    tree->size = 0;
    tree->depth = 0;
}

int TreeSize(Tree *tree)
{
    if (!tree->root)
    return 0;

    return (1 + TreeSize(&Tree->left) + TreeSize(Tree->right) );
}

int TreeDepth(Tree *tree)
{
     if (! tree->root)
    return 0;

    int a = TreeDepth(Tree->left);
    int b = TreeDepth(Tree->right);

    return (a>b) ? 1+a : 1+b ;
}


void Insert_Recursion(Tree *tree, Tree_entry e)
{
    if (tree->root == NULL)
    {
        *tree = (Tree_node *)malloc(sizeof(Tree_node));       // Create a new node if the tree is empty
        if (tree->root == NULL)
        {
            return;
        }

        tree->entry = e;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        if (e < tree->entry)
        {
            Insert_Recursion(tree->left, e);
        }
        else
        {
            Insert_Recursion(tree->right, e);
        }
    }
}

void InsertNode(Tree *pt, Tree_entry e)  //without stack so you can allocate  a new node in the first
{                                        //without checking if NULL or not buz allocate it only one time
    Tree_node *t = (Tree_node *)malloc(sizeof(Tree_node));
    if (t == NULL)
    {
        // Handle memory allocation failure
        return;
    }
    t->entry = e;
    t->left = NULL;
    t->right = NULL;

    if (*pt == NULL)    // If the tree is empty
    {
        *pt = t;    // Assign the new node as the root
    }
    else
    {
        Tree_node *pre = NULL;
        Tree_node *cur = *pt;
        while (cur)
        {
            pre =cur;

            if (e < cur->entry)     cur = cur->left;
            else                    cur = cur->right;

        }

    }
    // if current (cur) point to NULL (while is false)
    // pre will point to new node that was allocated
    if (e < pre->entry)         pre->left = t;
    else                        pre->right= t;


}

void inorder(Tree *tree,void (*pvisit)(Tree_entry) )
{
    if (tree)
    {
        inorder(tree->left,pvisit);
        (*pvisit)(tree->entry);
        inorder(tree->right,pvisit);
    }
}

void preorder(Tree *tree, void (*pvisit)(Tree_entry))
{
    if (tree)
    {
        (*pvisit)(tree->entry);
        preorder(tree->left,pvisit);
        preorder(tree->right,pvisit);
    }
}

void postorder(Tree *tree, void (*pvisit)(Tree_entry))
{
    if (tree)
    {
        postorder(tree->left,pvisit);
        postorder(tree->right,pvisit);
        (*pvisit)(tree->entry);
    }
}

*/
