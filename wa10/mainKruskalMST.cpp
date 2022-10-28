#include <iostream>
#include "weightedGraph.h"
#include "kruskalMST.h"

using namespace std;

int main()
{
   WeightedGraph *G = new WeightedGraph(cin);
   KruskalMST mst(G);

   for (Edge e : mst.Edges())
      cout << e << endl;

   cout << "MST Weight: " << mst.Weight() << endl;
}
