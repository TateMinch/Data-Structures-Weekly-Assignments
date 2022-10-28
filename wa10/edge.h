/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef EDGE_H
#define EDGE_H
#include <iostream>

/********************************************************************//**
 * @class Edge
 *
 * A simple edge class for use in the weightedGraph class
 **********************************************************************/
class Edge
{
   int v, w; 
   double weight;
public:
   Edge(int v, int w, double weight);

   int either() const;
   int other(int) const;
  
   // Used to compare one edge to another by weight (used in the heaps)
   bool operator<(const Edge &) const;

   // Convenience friend function to print out edges
   friend std::ostream &operator <<(std::ostream &, const Edge &);
   double Weight() const;
};

// A class used in the priority_queue declaration
class CompareEdge
{
public:
   bool operator()(Edge e, Edge f)
   {
      return e < f;
   }
};

#endif
