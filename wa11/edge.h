/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef EDGE_H
#define EDGE_H
#include <iostream>

/********************************************************************//**
 * @class Edge
 **********************************************************************/
class Edge
{
   int v, w; 
   double weight;
public:
   Edge(int, int, double);

   int either() const;
   int other(int) const;
   bool operator<(const Edge &) const;
   friend std::ostream &operator <<(std::ostream &, const Edge &);
   double Weight() const;
};
#endif
