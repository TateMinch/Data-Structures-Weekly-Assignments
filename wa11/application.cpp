#include "application.h"
#include <iostream>

using namespace std;

#define VERTEX_RADIUS 10

Application::Application(int width) : mapWidth(width), wgraph(nullptr)
{
   sAppName = "Application";
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
   wgraph = new WeightedGraph(cin);

   set<int> vertices = wgraph->Vertices();
   set<int>::iterator it = vertices.begin();
   startNode = (*it);
   endNode = *(++it);

   cout << "Keyboard Controls:" << endl;
   cout << "------------------" << endl;
   cout << endl;
   cout << "Mouse Controls:" << endl;
   cout << "---------------" << endl;
   cout << "Left mouse     - Move starting node" << endl;
   cout << endl; 
   return true;
}

// When a mouse button is pushed, find the vertex which was selected
// and return it
int Application::cellSelected(bool leftMouse)
{
   int x = GetMouseX();
   int y = GetMouseY();
   for (int v : wgraph->Vertices())
   {
      int vX = v % mapWidth;
      int vY = v / mapWidth;
      if (sqrt(pow(x-vX,2) + pow(y-vY,2)) <= VERTEX_RADIUS)
         return v;
   }
   return (leftMouse) ? startNode : endNode;
}

// Draw the vertices and edges based on the graph.  Vertex name is the
// pixel coordinate index calculated as x + y * width where width is a
// parameter to the application.  Default width is 900 and the default
// window is Width x Width
// Adding text to the vertices and edges make this messy
void Application::drawGraph()
{
   Clear(olc::GREY);
   for (int v : wgraph->Vertices())
      for (Edge e : wgraph->adj(v))
      {
         int x1 = v % mapWidth;
         int y1 = v / mapWidth;
         int x2 = e.other(v) % mapWidth;
         int y2 = e.other(v) / mapWidth;

         if (e.Weight() >= 0.0) 
            DrawLine(x1, y1, x2, y2, olc::WHITE);
         else
            DrawLine(x1, y1, x2, y2, olc::RED);
         char label[4];
         sprintf(label, "%.0f", e.Weight());
         DrawString((x1+x2)/2, (y1+y2)/2, label);
      }

   for (int v : wgraph->Vertices())
   {
      olc::Pixel color = olc::CYAN;
      if (v == startNode) color = olc::GREEN;
      if (bf->distance(v) == std::numeric_limits<double>::infinity())
         color = olc::BLACK;
      if (bf->distance(v) == -std::numeric_limits<double>::infinity())
         color = olc::RED;
      int x1 = v % mapWidth;
      int y1 = v / mapWidth;
      FillCircle(x1, y1, VERTEX_RADIUS, color);
      char label[5];
      if (bf->distance(v) == std::numeric_limits<double>::infinity())
         strcpy(label, "inf");
      else if (bf->distance(v) == -std::numeric_limits<double>::infinity())
         strcpy(label, "-inf");
      else
         sprintf(label, "%.0f", bf->distance(v));
      DrawString(x1 - VERTEX_RADIUS/2, y1, label);
   }
}

/*
// When a mouse button is pushed, find the vertex which was selected
void Application::drawPath(bool doAstar)
{
   std::list<int> path;
   std::map<int, bool> visitedMap;
    
   for (int row = 0 ; row < mapHeight ; row++)
      for (int col = 0 ; col < mapWidth ; col++)
         if (visitedMap[row * mapWidth + col])
            drawCell(row * mapWidth + col, olc::YELLOW);

   for (int v : path)
      drawCell(v, olc::WHITE);

   drawCell(startNode, olc::GREEN);
   drawCell(endNode, olc::RED);
} 
*/

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   bf = new BellmanFord(wgraph, startNode);
   drawGraph();

   if (GetMouse(0).bReleased) startNode = cellSelected(true);

   delete bf;
   return (!(GetKey(olc::Key::ESCAPE).bPressed) &&
           !(GetKey(olc::Key::Q).bPressed));
}

bool Application::OnUserDestroy()
{
   delete wgraph;
   return true;
}
