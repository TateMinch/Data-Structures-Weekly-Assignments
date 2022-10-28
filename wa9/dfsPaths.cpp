#include "dfsPaths.h"

DFSPaths::DFSPaths(Graph *G, int s) : s(s)
{
   dfs(G,s);
}

void DFSPaths::dfs(Graph *G, int v)
{
   marked[v] = true;
   for(int w : G->adj(v))
   {
      if(!marked[w])
      {
         prev[w] = v;
         dfs(G, w);
      }
   }
}

bool DFSPaths::hasPath(int v) {return marked[v];}

list<int> DFSPaths::pathTo(int v)
{
   list<int> path;
   // this needs work, right now, path is always empty
   if(!hasPath(v)) return path;
   for(int x = v; x != s; x = prev[x])
      path.push_front(x);
   path.push_front(s);
   return path;
}
