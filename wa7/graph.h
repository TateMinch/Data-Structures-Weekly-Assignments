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
   unordered_map<int, set<int>> vertices;  // adjacency hash
   int numVertices, numEdges;              // #vertices, #edges
public:
   Graph();                                // default constructor
   Graph(istream &);                       // construct graph from stdin
   Graph(const vector<vector<int>> &grid); // construct graph from 2d array
   virtual ~Graph();                       // virtual destructor

   set<int> Vertices() const;              // Return the set of vertices
   set<int> adj(int v);                    // Return vertices adjacent to v
   int V() const;                          // Number of vertices
   int E() const;                          // Number of edges
private:
   virtual void addEdge(int, int);         // Add an edge to the edge list
};
#endif
