#include "weightedGraph.h"

WeightedGraph::WeightedGraph() : numVertices(0) {}

WeightedGraph::WeightedGraph(std::istream &fin) : numVertices(0), numEdges(0)
{
   int v, w;
   double weight;
   while (fin >> v >> w >> weight)
   {
      addEdge(Edge(v, w, weight));
      numEdges++;
   }

   numVertices = vertices.size();
}

int WeightedGraph::V() const { return numVertices ; }
int WeightedGraph::E() const { return vertices.size() ; }

std::set<int> WeightedGraph::Vertices() const
{
   return vertices;
}

std::multiset<Edge> WeightedGraph::adj(int v)
{
   return edges[v];
}

std::multiset<Edge> WeightedGraph::Edges()
{
   std::multiset<Edge> returnVal;
   for (auto &kv : edges)
      for (Edge e : adj(kv.first))
         returnVal.insert(e);

   return returnVal;
}

void WeightedGraph::addEdge(Edge e)
{
   int v = e.either();
   int w = e.other(v);
   edges[v].insert(e);
   vertices.insert(v);
   if (vertices.find(w) == vertices.end())
      vertices.insert(w);
}
