/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef DISJOINT_H
#define DISJOINT_H
#include <vector>

using namespace std;

/********************************************************************//**
 * @class Disjoint
 **********************************************************************/
class Disjoint
{
int *rank, *Parent, size;

public:
   Disjoint(int);
   ~Disjoint();

   int Find(int);
   void Union(int, int);
   void makeSet();
   int setCount() const;
};
#endif
