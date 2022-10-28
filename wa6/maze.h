/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <utility>           // For pair, make_pair
#include <vector>

/********************************************************************//**
 * @class Maze
 **********************************************************************/
class Maze
{
   std::vector<std::pair<int,int>> edges;
public:
   Maze(int, int);
   ~Maze();

   std::vector<std::pair<int, int>> edgeList();
   bool removeEdge();
};
#endif
