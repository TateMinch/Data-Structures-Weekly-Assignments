#include "maxStack.h"

int main()
{
    MaxStack myStack;

   myStack.push(100);
   cout << myStack.max() << endl;  // will output '100'

   myStack.push(50);
   cout << myStack.max() << endl;  // will output '100'

   myStack.push(250);
   cout << myStack.max() << endl;  // will output '250'

   myStack.push(100);
   cout << myStack.max() << endl;  // will output '100'

   cout << myStack << endl; // should output the entire stack with associated
                            // max values

   myStack.pop();
   myStack.pop();
   cout << myStack << endl;

   cout << myStack.max() << endl;  // will output '100'
    return 0;
}