/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include <unordered_map>
#include <list>
#include <limits>
#include "edge.h"
#include "weightedGraph.h"

/********************************************************************//**
 * @class BellmanFord
 **********************************************************************/
class BellmanFord
{
   std::unordered_map<int, double> dist;
   std::unordered_map<int, int> prev;
   int start;
public:
   BellmanFord(WeightedGraph *G, int);

   bool hasPath(int);
   std::list<int> pathTo(int);
   double distance(int);
private:
   void relax(int, Edge);
};
#endif
