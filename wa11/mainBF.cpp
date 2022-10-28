#include <iostream>
#include "bellmanFord.h"

using namespace std;

int main()
{ 
   WeightedGraph *graph = new WeightedGraph(cin);

   BellmanFord bf(graph, 0);

   for (int v : graph->Vertices())
   {
      cout << v << "\tAdj" << endl;
      for (Edge e : graph->adj(v))
         cout << e << " ";
      cout << endl;
   }

   cout << "Distances:" << endl;
   for (int v : graph->Vertices())
   {
      if (v == 0) continue;
      cout << v << "\t" << bf.distance(v) << endl;
   }
   return 0;
}
