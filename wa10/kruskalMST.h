/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <set>
#include <queue>
#include "weightedGraph.h"
#include "disjointSet.h"

/********************************************************************//**
 * @class Kruskal
 * 
 * A minimum spanning tree (MST) client class which uses the 
 * WeightedGraph and Edge classes
 **********************************************************************/
class KruskalMST
{
   std::vector<Edge> mst;                  // The MST edge list
   double weight;                          // Total weight of the MST
public:
   KruskalMST(WeightedGraph *);

   std::vector<Edge> Edges();              // Vector of edges in the MST
   double Weight() const;                  // Total weight of the MST
};
#endif
