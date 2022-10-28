#include "application.h"
#include <iostream>

using namespace std;

Application::Application(int w, int h) : width(w), height(h), animate(false)
{
   sAppName = "Application";
   edgeWidth = 2;
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
   nCellSize = ScreenHeight() / height;
   maze = new Maze(width, height);
   cout << "Keyboard Controls:" << endl;
   cout << "------------------" << endl;
   cout << "<SPACE BAR>   - Complete construction of the maze immediately" << endl;
   cout << "A             - Animate construction of the maze" << endl;
   cout << "R             - Clear old maze and start new construction" << endl;
   cout << "Q or <ESCAPE> - Quit the program" << endl;
   cout << endl;
   return true;
}

void Application::completeMaze()
{
   while (maze->removeEdge());
}

void Application::drawGrid()
{
   Clear(olc::BLACK);
   
   DrawRect(0, 0, nCellSize * width, nCellSize * height);

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
}

void Application::resetMaze()
{
   delete maze;
   maze = new Maze(width, height);
}

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   drawGrid();
   if (animate)
      maze->removeEdge();

   if (GetKey(olc::Key::SPACE).bPressed)
      completeMaze();

   if (GetKey(olc::Key::A).bPressed)
      animate = !animate;

   if (GetKey(olc::Key::R).bPressed)
      resetMaze();
 
   return (!(GetKey(olc::Key::ESCAPE).bPressed) &&
           !(GetKey(olc::Key::Q).bPressed));
}

bool Application::OnUserDestroy()
{
   delete maze;
   return true;
}
