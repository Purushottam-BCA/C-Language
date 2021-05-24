
/* Identify and implement the kind of the tree that maintainss a sorted stream of data.

Binary Search Tree will be the best choice for maintaining data in sorted manner.
In BST :- 
(1) Smaller values than ROOT is kept in its left sub tree
(2) Larger values than ROOT is kept in its right sub tree

Also in INORDER traversal we can display data in sorted order  
                 15     
               /   \
              9    26
            / \   /  \
           5  12 18  47
                /    / 
               17   32    
                   /
                  31        */

#include<stdio.h>
#include<stdlib.h>

struct binary_search{
   int data;
   struct binary_search *left,*right;
};

typedef struct binary_search BST;

BST* create(int item) 
{
   BST *temp=(BST*)malloc(sizeof(BST));
   temp->data = item;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

BST* insert(BST *root, int item)    // Inserting Data into  Binary Search TREE
{
   if(root==NULL) return create(item);  // If TREE is empty then First Create 
   if(item < root-> data)               // If Value < ROOT Then Left Subtree
      root->left = insert(root->left,item);
   else if(item > root-> data)          // If value > ROOT Then Right Subtree
      root->right = insert(root->right,item);
   return root;                         // Else return the address of inserted node.
}

//---------------- TRAVERSAL -----------------
void inorder(BST *root)
{
   if (root != NULL)
   {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
   }
}

/* Find the Node with lowest value in tree  Left->Leaf(Value) */
BST * minValue(BST * node)
{
   BST *temp = node;
    while(temp && temp->left != NULL )
        temp = temp->left;
    return temp;
}

//---------------- DELETE -----------------

BST* delete(BST *root, int item)
{
    if(root == NULL) return root; 
    if(item < root->data)
        root->left  = delete(root->left, item);
    else if(item > root->data)
        root->right  = delete(root->right, item);
    // if item = root's value then This node is to be deleted
    else
    {
        // node with only one child or no child
        if(root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        // node with two children : (smallest in the right subtree)
        BST *temp = minValue(root->right);
        // Copy the inorder successor's content the node
        root->data = temp->data;
        // Delete the inorder successor because it is already swapped
        root->right = delete(root->right, temp->data);
    }
    return root;
}

//---------------- SEARCH -----------------
BST* search(BST *root, int item)
{
   if (root == NULL || root->data == item)  // If it is found
      return root;
   if (item > root->data) 
      return search(root->right, item);
   return search(root->left, item);
}

int main()
{
   BST *root = NULL;  // Initially TREE is empty.  
   root=insert(root,15);                  
   root=insert(root,9);                  
   root=insert(root,26);
   root=insert(root,18);
   root=insert(root,12);
   root=insert(root,32);
   root=insert(root,5);
   root=insert(root,47);
   root=insert(root,17);
   root=insert(root,31);
   printf("\n BEFORE DELETION INORDER (SORTED) : ");
   inorder(root);
   root=delete(root,18);
   root=delete(root,32);
   root=delete(root,17);
   printf("\n ATER DELETION INORDER (SORTED) : ");
   inorder(root);
   if(search(root , 23))
      printf("\n Element 23 found");
   else
      printf("\n Element 23 not found"); 
   if(search(root , 31))
      printf("\n Element 31 found");
   else
      printf("\n Element 31 not found"); 
   return 0;
}

