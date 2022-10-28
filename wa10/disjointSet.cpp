/********************************************************************//**
 * @file
 ***********************************************************************/
#include "disjointSet.h"

DisjointSet::DisjointSet() { }

// Using a map (or unordered_map if you need the performance) assign
// specific names to the disjoint sets instead of depending on the
// names to be in the range 0 - |V|-1
void DisjointSet::makeSet(int v)
{
   ds[v] = -1;
}

// Everything else is the same.  Use path compression for a bit more
// performance
int DisjointSet::Find(int v)
{
   if (ds[v] == -1) return v;

   ds[v] = Find(ds[v]);
   return ds[v];
}

// First check that the two items aren't already in the same set, then
// place one into the other
void DisjointSet::Union(int i, int j)
{
   i = Find(i);
   j = Find(j);

   if (i == j) return;

   ds[i] = j;
}
