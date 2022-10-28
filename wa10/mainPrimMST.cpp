#include <iostream>
#include "primMST.h"

using namespace std;

int main()
{
   WeightedGraph *G = new WeightedGraph(cin);

   // Just grab the first vertex in the vertex set
   std::set<int>::iterator it = G->Vertices().begin();
 
   // Start the algorithm at the first vertex
   PrimMST mst(G, *it);

   for (Edge e : mst.Edges())
      cout << e << endl;

   cout << "MST Weight: " << mst.Weight() << endl;
   delete G;
}
