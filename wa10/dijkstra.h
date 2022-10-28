#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <queue>
#include <vector>
#include <functional>
#include <list>
#include <limits>
#include "weightedGraph.h"

// The nodes that will be placed on the minHeap
struct DijNode 
{
   int vertex;
   double dist;
   DijNode (int v, double d) : vertex(v), dist(d) {}
};

// The comparator so that the priority_queue can correctly order the
// nodes by weight
struct compareDijNodes
{
   bool operator()(const DijNode d1, const DijNode d2)
   { 
      return d1.dist > d2.dist ; 
   }
};

class Dijkstra 
{
   std::map<int, double> dist;
   std::map<int, int> prev;
   std::map<int, bool> known;
   std::priority_queue<DijNode, std::vector<DijNode>, compareDijNodes> pq;
   int start;
public:
   Dijkstra(WeightedGraph *, int);

   double distance(int);
   bool hasPath(int);
   std::list<int> pathTo(int);
private:
   void relax(int, Edge);
};

#endif


