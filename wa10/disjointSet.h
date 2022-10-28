/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef DISJOINT_H
#define DISJOINT_H
#include <vector>
#include <map>
using namespace std;

/********************************************************************//**
 * @class Disjoint
 *
 * This is slightly different than the version we looked at earlier in
 * the semester.  Instead of generating all the disjoint sets with a
 * single 'makeSet' call.  We call makeSet for each of the items in the
 * disjoint set so that we're not restricted to set names that are only
 * in the range from 0 - |V|-1
 **********************************************************************/
class DisjointSet
{
   map<int, int> ds;
public:
   DisjointSet();

   void makeSet(int);
   int Find(int);
   void Union(int, int);
};
#endif
