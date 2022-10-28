#include "disjoint.h"

Disjoint::Disjoint(int size) : count(size)
{
   ds.resize(size, -1);
}

int Disjoint::Find(int v)
{
   if (ds[v] == -1) return v;

   ds[v] = Find(ds[v]);
   return ds[v];
}

void Disjoint::Union(int i, int j)
{
   i = Find(i);
   j = Find(j);

   if (i == j) return;

   count--;   
   ds[i] = j;
}

int Disjoint::setCount() const
{
   return count;
}
