/********************************************************************//**
 * @file
 ***********************************************************************/
#include "edge.h"

Edge::Edge(int s, int e, double w) : v(s), w(e), weight(w) {}

double Edge::Weight() const { return weight ; }

int Edge::either() const { return v ; }
int Edge::other(int vertex) const
{
   if (vertex == v) return w;
   return v;
}

bool Edge::operator<(const Edge &rhs) const
{
   return (weight > rhs.weight);
}

std::ostream &operator<<(std::ostream &os, const Edge &e)
{
   int v = e.either();
   int w = e.other(v);
   os << v << " - " << w << " " << e.weight;
   return os;
}
