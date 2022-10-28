#include <iostream>
#include "node.h"

using namespace std;

int height(Node *);

Node *rotateRight(Node *y)
{
   Node *x = y->left;
   Node *temp = x->right;

   x->right = y;
   y->left = temp;

   y->ht = max(height(y->left),height(y->right)) + 1;
   x->ht = max(height(x->left), height(x->right)) + 1;

   return x;
}

Node *rotateLeft(Node *x)
{
   Node *y = x->right;
   Node *temp = y->left;

   y->left = x;
   x->right = temp;

   x->ht = max(height(x->left), height(x->right)) + 1;
   y->ht = max(height(y->left), height(y->right)) + 1;

   return y;
}

int tempBalance(Node *N)
{
   if(N == nullptr)
      return 0;
   
   return height(N->left) - height(N->right);
}

/**************************************************************************//**
 * This function does a BST insert (no balancing).
 *
 * YOU need to implement an AVL balancing insert function
 *
 * @param[inout] root - The root of the subtree currently being processed
 * @param[in] data - The data element to add to the tree
 *
 * @return - The root of the subtree currently being processed
 *****************************************************************************/
Node *insert(Node *root, int data)
{
   if (root == nullptr)
      root = new Node(data);

   else if (data < root->data)
      root->left = insert(root->left, data);
   else
      root->right = insert(root->right, data);

   root->ht = 1 + max(height(root->left),
   height(root->right));

   int balance = tempBalance(root);
   
   if(balance > 1 && data > root->left->data)
   {
      root->left = rotateLeft(root->left);
      return rotateRight(root);
   }
   if(balance > 1 && data < root->left->data)
      return rotateRight(root);
   if(balance < -1 && data < root->right->data)
   {
      root->right = rotateRight(root->right);
      return rotateLeft(root);
   }

   if(balance < -1 && data > root->right->data)
      return rotateLeft(root);

   return root;
}

/**************************************************************************//**
 * This function returns the height of the node passed in
 *
 * @param[in] node - The node whose height we want
 *
 * @return - The height of the node passed in
 *****************************************************************************/
int height(Node *node)
{
   if (!node) return -1;
   return node->ht;
}
