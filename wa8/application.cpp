#include "application.h"
#include <iostream>

using namespace std;

Application::Application(int w, int h) : width(w), height(h), animate(false),
   solve(false)
{
   sAppName = "Application";
   edgeWidth = 2;
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
   nCellSize = ScreenHeight() / height;
   maze = new Maze(width, height);
   startNode = 0;
   endNode = (width * height - 1);
   cout << "Keyboard Controls:" << endl;
   cout << "------------------" << endl;
   cout << "<SPACE BAR>   - Complete construction of the maze immediately" << endl;
   cout << "A             - Animate construction of the maze" << endl;
   cout << "R             - Clear old maze and start new construction" << endl;
   cout << "S             - Solve the maze using BFS on the graph" << endl;
   cout << "Q or <ESCAPE> - Quit the program" << endl;
   cout << endl;
   cout << "Mouse Controls:" << endl;
   cout << "---------------" << endl;
   cout << "Left mouse up - move start node (green)" << endl;
   cout << "Right mouse up- move end node (red)" << endl;
   cout << endl;
   return true;
}

// Complete the maze all at once, don't animate the maze creation
void Application::completeMaze()
{
   while (maze->removeEdge());
}


// Draw the walls of the maze as they currently are.  This will be called
// continuously by the onUserUpdate method
void Application::drawGrid()
{
   Clear(olc::BLACK);
   
   DrawRect(0, 0, nCellSize * width - 1, nCellSize * height - 1);

   int x1, y1;
   for (auto &p : maze->edgeList())
   {
      if (p.first + 1 == p.second) // vertical between p.first and p.second
      {
         x1 = p.second % width * nCellSize;
         y1 = (p.first / width) * nCellSize;
         DrawLine(x1, y1, x1, y1 + nCellSize);
      }
      else
      {
         x1 = (p.first % width) * nCellSize;
         y1 = (p.second / width) * nCellSize;
         DrawLine(x1, y1, x1 + nCellSize, y1);
      }
   }
   drawCell(startNode, olc::GREEN);
   drawCell(endNode, olc::RED);
}

// Draw a filled rectangle in the cell described by 'index' and use the
// color described by 'color'
void Application::drawCell(int index, olc::Pixel color)
{
   auto p = [&](int index) { return make_pair(index % width, index / width); };

   FillRect(p(index).first * nCellSize + 2, p(index).second * nCellSize + 2,
            nCellSize - 4, nCellSize - 4, color);
}

// Given a list of cells in the grid, draw red rectangles to denote a node
// along the path from the startNode to the endNode
void Application::drawPath(list<int> path)
{
   list<int>::iterator it = path.begin();

   it++;
   while (it != path.end())
   {
      drawCell((*it), olc::BLUE);
      it++;
   }

   drawCell(startNode, olc::GREEN);
   drawCell(endNode, olc::RED);
}

// Free the existing maze and create a new one
void Application::resetMaze()
{
   delete maze;
   maze = new Maze(width, height);
}

// Return the cell that was selected by the mouse click
int Application::cellSelected() const
{
   return GetMouseX() / nCellSize + GetMouseY() / nCellSize * width;
}

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   drawGrid();
   if (animate)
      maze->removeEdge();

   // Create a new graph from the edgelist returned from the maze object
   Graph *graph = new Graph(maze->graphEdgeList());

   // Perform a breadth-first search on the graph object from the startNode
   BFSPaths bfs(graph, startNode);
   //cout << bfs.distance(1000);

   // If there is a path from the startNode to the endNode *and* the user
   // has toggled the solve flag, draw the path from the startNode to the
   // endNode
   if (maze->doneRemovingEdges() && solve && bfs.hasPath(endNode))
      drawPath(bfs.pathTo(endNode));

   // Change the startNode to where the left mouse was released
   if (GetMouse(0).bReleased) startNode = cellSelected();
   // Change the endNode to where the right mouse was released
   if (GetMouse(1).bReleased) endNode = cellSelected();

   // Complete the drawing of the maze
   if (GetKey(olc::Key::SPACE).bPressed)
      completeMaze();

   // Toggle the animation of the construction of the maze
   if (GetKey(olc::Key::A).bPressed)
      animate = !animate;

   // Remove the current maze and generate a new one
   if (GetKey(olc::Key::R).bPressed)
      resetMaze();

   // Toggle the solving of the current maze
   if (GetKey(olc::Key::S).bPressed)
      solve = !solve;

   // Free up the graph object if one exists
   if (graph != nullptr) delete graph;

   // Exit the application if the escape or q keys were pressed
   return (!(GetKey(olc::Key::ESCAPE).bPressed) &&
           !(GetKey(olc::Key::Q).bPressed));
}

// Do any necessary cleanup
bool Application::OnUserDestroy()
{
   delete maze;
   return true;
}
