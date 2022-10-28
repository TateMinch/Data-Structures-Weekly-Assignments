#include "maze.h"
#include <iostream>

// When creating a new maze, start with all the walls that define the 
// height by width.  Place those in the edges vector of pairs of ints
Maze::Maze(int w, int h) : width(w), height(h)
{
   ds = new Disjoint(w * h);

   for (int row = 0 ; row < height ; row++)
      for (int col = 0 ; col < width ; col++)
      {
         int index = row * width + col;
         if (row < height - 1) edges.push_back(make_pair(index, index+width));
         if (col < width - 1) edges.push_back(make_pair(index, index+1));
      }
}

// Free up the disjoint set
Maze::~Maze()
{
   delete ds;
}

// Return the edges that make up the walls of the maze
std::vector<std::pair<int, int>> Maze::edgeList()
{
   return edges;
}

// Return the vector of pairs which represent the edgelist for the graph that
// represents the maze.  Somewhere in the maze creation, you need to create
// this graphEdgeList
std::vector<std::pair<int, int>> Maze::graphEdgeList()
{
   return graphEdges;
}

bool Maze::doneRemovingEdges()
{
    if (ds->setCount() == 1) return true;
    return false;
}

bool Maze::removeEdge()
{
   if (ds->setCount() == 1) return false;

   bool notDone = true;
   while (notDone)
   {
      int deletedEdge = rand() % edges.size();
      int v = edges[deletedEdge].first;
      int w = edges[deletedEdge].second;
      if (ds->Find(v) != ds->Find(w))
      {
         ds->Union(v, w);
         graphEdges.push_back(edges[deletedEdge]);
         std::swap(edges[deletedEdge], edges[edges.size()-1]);
         edges.pop_back();
         notDone = false;
      }
   }

   return true;
}
