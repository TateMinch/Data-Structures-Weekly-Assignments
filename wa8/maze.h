/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <utility>           // For pair, make_pair
#include <ctime>
#include <cstdlib>
#include "disjoint.h"

/********************************************************************//**
 * @class Maze
 **********************************************************************/
class Maze
{
   // Maze walls
   std::vector<std::pair<int,int>> edges;
   // Edges which make up the edgelist for the graph that represents the
   // connections between the cells in the maze
   std::vector<std::pair<int, int>> graphEdges;
   Disjoint *ds;
   int width, height;
public:
   Maze(int, int);
   ~Maze();

   // Return the edges that make up the maze walls
   std::vector<std::pair<int, int>> edgeList();
   bool removeEdge();
   // Return the edges that make up the graph that represents the paths in the     // maze
   std::vector<std::pair<int, int>> graphEdgeList();
   bool doneRemovingEdges();


};
#endif
