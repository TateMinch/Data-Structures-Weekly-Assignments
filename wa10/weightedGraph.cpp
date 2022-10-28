#include "weightedGraph.h"

// If you've been keeping up with the Graph API, this looks very similar

WeightedGraph::WeightedGraph() : numVertices(0) {}

// Construct the graph from an edge list in an istream
WeightedGraph::WeightedGraph(std::istream &fin)
{
   int v, w;
   double weight;
   while (fin >> v >> w >> weight)
      addEdge(Edge(v, w, weight));
}

// Accessors
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

// Add an edge.  Note, this creates an undirected graph
void WeightedGraph::addEdge(Edge e)
{
   int v = e.either();
   int w = e.other(v);
   edges[v].insert(e);
   edges[w].insert(e);
   vertices.insert(v);
   vertices.insert(w);
}
