#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <set>
#include <map>
#include <vector>
#include "edge.h"

#define validRow(r) (r >= 0 && r < height)
#define validCol(c) (c >= 0 && c < width)
#define INVALID_VALUE -1

#define canEnter(r, c) (validRow(r) && validCol(c) && \
                       (grid[r][c] != INVALID_VALUE))

class WeightedGraph
{
   int numVertices, numEdges;
   std::map<int, std::multiset<Edge>> edges;
   std::set<int> vertices;
public:
   WeightedGraph();
   WeightedGraph(std::istream &);

   void addEdge(Edge);
   std::multiset<Edge> adj(int);
   std::multiset<Edge> Edges();
   std::set<int> Vertices() const;
   int V() const;
   int E() const;
};

#endif
