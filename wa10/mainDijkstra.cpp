#include <iostream>
#include "dijkstra.h"

using namespace std;

int main()
{
   WeightedGraph *G = new WeightedGraph(cin);

   int startNode = *(G->Vertices().begin());
   int endNode = *(G->Vertices().rbegin());

   Dijkstra dij(G, startNode);

   if (dij.hasPath(endNode))
      for (int v : dij.pathTo(endNode))
         cout << v << " ";

   cout << endl;
   delete G;
   return 0;
}
