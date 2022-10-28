#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Graph
{
   unordered_map<int, set<int>> vertices;
   int numVertices, numEdges;
public:
   Graph();
   Graph(istream &);
   Graph(const vector<pair<int, int>> &);
   virtual ~Graph();

   set<int> Vertices() const;
   set<int> adj(int);
   virtual void addEdge(int, int);
   int V() const;
   int E() const;
};
#endif
