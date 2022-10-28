#ifndef __DFSPATHS_H
#define __DFSPATHS_H
#include <list>
#include <map>
#include <vector>
#include "graph.h"

class DFSPaths
{
   map<int, bool> marked;
   map<int, int> prev;
   int s;

public:
   DFSPaths(Graph *G, int s);

   bool hasPath(int v);
   std::list<int> pathTo(int v);

private:
   void dfs(Graph *, int);
};
#endif
