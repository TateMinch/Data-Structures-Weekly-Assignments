#ifndef MAXSTACK_H
#define MAXSTACK_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MaxStack
{
public:
   MaxStack();
   ~MaxStack();

   bool empty();
   int size();
   int top();
   void push(int);
   void pop();
   int max();
   friend ostream& operator<<(ostream &, const MaxStack &);

private:
    struct node
    {
        int item;
        node* next;
    };
    node* headptr;
    node* tailptr;
    int stackSize;
    vector<int> maxTracker;
    vector<int> sameSizeMax;
    vector<int> outputTime;
};
#endif