#ifndef __NODE_H
#define __NODE_H
struct Node
{
   int data;
   Node* left;
   Node* right;
   int ht;

   Node(int d, Node* l=nullptr, Node* r=nullptr, int ht=0): data(d), left(l), right(r), ht(ht){}
   ~Node() { delete left ; delete right ; }
};
#endif
