#include "bridges.h"

Bridges::Bridges(Graph *G) : ID(0)
{
   // you need to implement the constructor
   for(int v : G->Vertices())
   {
      if(!marked[v])
         dfs(G,-1, v);
   }
}

list<pair<int, int>> Bridges::bridges()
{
   return bridge;
}

void Bridges::dfs(Graph *G, int prev, int v)
{
   // you need to implement the dfs that gathers the id and low-id
   // values to find bridges
   marked[v] = true;
   low[v] = id[v] = ID++;
   for(int w : G->adj(v))
   {
      if(w == prev) continue;
      if(!marked[w])
      {
         dfs(G,v,w);
         low[v] = min(low[w],low[v]);
         if(id[v] < low[w])
         {
            bridge.push_back(pair<int,int>(v,w));
         }
         else
         {
            low[v] = min(low[v],id[w]);
         }
      }
   }
}
