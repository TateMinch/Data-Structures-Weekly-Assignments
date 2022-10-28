/***************************************************************************//**
 * @file bfsPaths.cpp
 ******************************************************************************/
#include "bfsPaths.h"


BFSPaths::BFSPaths(Graph *G, int v) : s(v)
{
   //call private bfs function
   bfs(G, s);
}

bool BFSPaths::hasPath(int v) { return marked[v]; }

int BFSPaths::distance(int v)
{
   return dist[v];
}

std::list<int> BFSPaths::pathTo(int v)
{
   std::list<int> path;
   if (!hasPath(v)) return path;
   for (int x = v ; x != s ; x = prev[x])
      path.push_front(x);
   path.push_front(s);
   return path;
}

void BFSPaths::bfs(Graph *G, int s)
{
   std::queue<int> frontier;
   frontier.push(s);
   marked[s] = true;
   dist[s] = 0;
   while (!frontier.empty())
   {
      int v = frontier.front();
      frontier.pop();
      for (int w : G->adj(v))
      {
         if (!marked[w])
         {
            frontier.push(w);
            marked[w] = true;
            prev[w] = v;
            dist[w] = dist[v] + 1;
         }
      }
   }
}

std::map<int, bool> BFSPaths::Visited() { return marked ; }