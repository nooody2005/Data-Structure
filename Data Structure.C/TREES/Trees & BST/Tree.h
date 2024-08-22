#ifdef TREE
#define TREE

#define Tree_entry int
//typedef int Tree_entry

typedef struct Tree_node
{
    Tree_entry entry;
    struct Tree_node *left , *right;
}Tree_node;

typedef Tree_node *Tree;

/*
typedef struct Tree 
{
    Tree_node *root;
    int size;
    int depth;
}Tree;
*/

void CreateTree(Tree *tree);
int Tree_Empty(Tree *tree);
int Tree_Full(Tree *tree);
void ClearTree(Tree *tree);
int TreeSize(Tree *tree);
int TreeDepth(Tree *tree);
void Insert_Recursion(Tree *pt, Tree_entry e);  
void InsertNode(Tree *tree, Tree_entry e);
void inorder(Tree *tree, void (*pvisit)(Tree_entry));
void preorder(Tree *tree, void (*pvisit)(Tree_entry));
void postorder(Tree *tree, void (*pvisit)(Tree_entry));

#endif

