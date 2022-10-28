/********************************************************************//**
 * @file
 ***********************************************************************/
#include "maxStack.h"

MaxStack::MaxStack()
{
   headptr = nullptr;
   tailptr = nullptr;
   stackSize = 0;
}

MaxStack::~MaxStack()
{

}

bool MaxStack::empty()
{
   return headptr == nullptr;
}

int MaxStack::size()
{
   return stackSize;
}

int MaxStack::top()
{
    if(headptr == nullptr)
    {
        cout << "Empty stack" << endl;
        throw;
    }
    return headptr->item;
}

void MaxStack::push(int newItem)
{
    vector<int>::iterator it = maxTracker.end() - 1;
    node* temp = new (nothrow) node;

    if (temp == nullptr)
    {
        return;
    }

    temp->item = newItem;
    temp->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = temp;
        stackSize++;
        maxTracker.push_back(newItem);
        outputTime.push_back(newItem);
        sameSizeMax.push_back(newItem);
        return;
    }
    if(*it < newItem)
    {
        maxTracker.push_back(newItem);
    }
    outputTime.push_back(newItem);
    sameSizeMax.push_back(max());
    temp->next = headptr;
    headptr = temp;
    stackSize++;
}

void MaxStack::pop()
{
    vector<int>::iterator it = maxTracker.end() - 1;
    node* temp = new (nothrow) node;

    if (empty())
    {
        cout << "Stack is empty" <<  endl;
        return;
    }

    temp = headptr;
    if(temp->item == *it)
    {
        maxTracker.pop_back();
    }
    outputTime.pop_back();
    sameSizeMax.pop_back();
    headptr = headptr->next;
    delete temp;
    stackSize--;

    if (headptr == nullptr)
    {
        tailptr = nullptr;
    }
}

int MaxStack::max()
{
    vector<int>::iterator it = maxTracker.end() - 1;
    if(empty())
    {
        cout << "Empty Stack!" << endl;
        throw;
    }
   return *it;
}

ostream& operator<<(ostream &os, const MaxStack &mst)
{
    int i;
   os << "MaxStack:" << endl;
   // Here you will want to output the contents of the stack to the ostream
    for(i = (int)mst.outputTime.size() - 1; i >= 0 ; i--)
    {
        os << mst.outputTime[i] << " ["  << mst.sameSizeMax[i] << "] " << endl;
    }
   return os;   
}
