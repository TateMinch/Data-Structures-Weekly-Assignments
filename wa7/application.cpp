#include "application.h"
#include <iostream>

using namespace std;

Application::Application()
{
   sAppName = "Application";
}

// Called once at the start, so create things here
//
// Read standard input for the graph description file.  The format of the file
// is:
//
// M N
// . .      .           row 1
// . .      .           row 2
// . .      .           ...
//                      row M
// c c      c
// o o      o
// l l      l
//
// 1 2 ...  N
//
// Example
//
// 4 5
// 1 1 1 1 1
// 1 1 0 0 1
// 0 1 1 0 1
// 0 0 1 1 1
//
// A cell with a '0' is a 'blocked' cell meaning it cannot be entered or
// exited.  From a graph perspective, there is no vertex at the location
// A cell with any other value should be considered a vertex in the graph
// and neighboring cells (up, down, right, left) are considered 'adjacent'
// and therefore there are edges between them.  This *not* an adjacency
// matrix!  Vertices are named based on their 1-d address / index.
//
// index = row * M + col
//
bool Application::OnUserCreate()
{
   vector<vector<int>> grid;
   cin >> height >> width;
   grid.resize(height);
   
   for (unsigned row = 0 ; row < height ; row++)
   {
      grid[row].resize(width);
      for (unsigned col = 0 ; col < width ; col++)
         cin >> grid[row][col];
   }
   graph = new Graph(grid); // read from standard input

   return true;
}

// DrawGraph : The assumption is that the vertices are named based on their
// 2-d location.  In general, we can't make that sort of assumption but this
// is the case here.  We leverage that knowledge in order to place the
// vertices and the edges between adjacent vertices.
void Application::drawGraph()
{
   Clear(olc::BLACK);
   int cellX = (ScreenWidth() - 20) / (width + 1);
   int cellY = (ScreenHeight() - 10) / (height + 1);
   int radius = min(min(20, cellX), cellY);

   for (int v : graph->Vertices())
   {
      int row = v / width;
      int col = v % width;

      for (int w : graph->adj(v))
      {
         int arow = w / width;
         int acol = w % width;
         if (row >= arow && col <= acol)
            DrawLine((col+1)*cellX, (row+1)*cellY, (acol+1)*cellX, (arow+1)*cellY, olc::GREEN);
      }
   }

   // Draw the vertices after the edges are in so the vertices are on top
   for (int v : graph->Vertices())
   {
      int row = v / width;
      int col = v % width;
      FillCircle((col + 1) * cellX, (row + 1) * cellY, radius, olc::RED);
   }
}

// This member function is called repeatedly until the program exits.
// The graph is repeatedly drawn even though it does not change.
// This will 'loop' until either the 'q' or <escape> keys are pressed
bool Application::OnUserUpdate(float fElapsedTime)
{
   drawGraph();

   return (!(GetKey(olc::Key::ESCAPE).bPressed) &&
           !(GetKey(olc::Key::Q).bPressed));
}

bool Application::OnUserDestroy()
{
   delete graph;
   return true;
}
