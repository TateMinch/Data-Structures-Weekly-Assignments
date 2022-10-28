#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <set>
#include <map>
#include "edge.h"

// A weighted Graph API very similar to our Graph API
class WeightedGraph
{
   int numVertices;
   // Multi-set in order to allow edges with the same weight in the set
   std::map<int, std::multiset<Edge>> edges;
   std::set<int> vertices;
public:
   WeightedGraph();

   /// Constructor expects and edge list (v w weight)
   WeightedGraph(std::istream &);

   /// The usual suspects
   std::multiset<Edge> adj(int);
   std::multiset<Edge> Edges();
   std::set<int> Vertices() const;
   int V() const;
   int E() const;

private:
   void addEdge(Edge);
};

#endif
