/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef PRIMMST_H
#define PRIMMST_H
#include <set>
#include <queue>
#include "weightedGraph.h"

/********************************************************************//**
 * @class PrimMST
 *
 * A minimum spanning tree (MST) client class which uses the 
 * WeightedGraph and Edge classes
 **********************************************************************/
class PrimMST
{
   std::map<int, bool> marked;
   std::vector<Edge> mst;
   std::priority_queue<Edge, std::vector<Edge>, CompareEdge> minHeap;
   double weight;
public:
   PrimMST(WeightedGraph *, int);

   std::vector<Edge> Edges();              // Vector of edges in the MST
   double Weight() const;                  // Total weight of the MST
private:
   void visit(WeightedGraph *, int);
};
#endif
