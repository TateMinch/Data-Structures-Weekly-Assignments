#include "graph.h"

Graph::Graph() { }

Graph::Graph(istream &instream) : numVertices(0), numEdges(0)
{
   int v, w;
   while (!instream.eof())
   {
      instream >> v >> w;
      addEdge(v, w);
   }

   numVertices = vertices.size();
   for (int u : Vertices())
      numEdges += adj(u).size();

   numEdges /= 2;
}

Graph::~Graph() {}

Graph::Graph(const vector<pair<int, int>> &edgeList) : numVertices(0), numEdges(0)
{
   for (pair<int, int> p : edgeList)
      addEdge(p.first, p.second);

   numVertices = vertices.size();
   for (int u : Vertices())
      numEdges += adj(u).size();

   numEdges /= 2;
}

int Graph::V() const { return numVertices ; }
int Graph::E() const { return numEdges ; }

set<int> Graph::Vertices() const
{
   set<int> retVal;
   for (auto &kv : vertices)
      retVal.insert(kv.first);

   return retVal;
}

set<int> Graph::adj(int v)
{
   return vertices[v];
}

void Graph::addEdge(int v, int w)
{
   vertices[v].insert(w);
   vertices[w].insert(v);
}
