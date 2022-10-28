/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef BRIDGES_H
#define BRIDGES_H
#include <list>
#include <map>
#include "graph.h"
/********************************************************************//**
 * @class Bridges
 **********************************************************************/
class Bridges
{
   map<int, int> id;
   map<int, int> low;
   map<int, bool> marked;
   list<pair<int, int>> bridge;
   int ID;
public:
   Bridges(Graph *);

   list<pair<int, int>> bridges();

private:
   void dfs(Graph *, int, int);
};
#endif
