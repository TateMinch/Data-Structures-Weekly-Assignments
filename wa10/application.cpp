#include "application.h"
#include <iostream>

#define VERTEX_RADIUS 10

using namespace std;

Application::Application(int width) : width(width), wgraph(nullptr), functionType(NONE), index(0)
{
   sAppName = "Application";
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
   wgraph = new WeightedGraph(cin);
   // Arbitrarily pick the first two vertices in the graph as the start and
   // end nodes just to have something to show.
   set<int> vertices = wgraph->Vertices();
   set<int>::iterator it = vertices.begin();
   startNode = (*it);
   endNode = *(++it);

   cout << "Keyboard Controls:" << endl;
   cout << "------------------" << endl;
   cout << "J              - Solve the path using Dijkstra's SSSP" << endl;
   cout << "K              - Find MST using Kruskal's MST algorithm" << endl;
   cout << "P              - Find MST using Prim's MST algorithm" << endl;
   cout << endl;
   cout << "Mouse Controls:" << endl;
   cout << "---------------" << endl;
   cout << "Left mouse up  - move start node (green)" << endl;
   cout << "Right mouse up - move end node (red)" << endl;
   cout << endl; 
   return true;
}

// Draw the vertices and edges based on the graph.  Vertex name is the
// pixel coordinate index calculated as x + y * width where width is a
// parameter to the application.  Default width is 900 and the default
// window is Width x Width.  A bit of a hack but it works for this
void Application::drawGraph()
{
   Clear(olc::GREY);
   for (int v : wgraph->Vertices())
      for (Edge e : wgraph->adj(v))
         DrawLine(v % width, v / width, e.other(v) % width, e.other(v) / width, olc::WHITE);

   for (int v : wgraph->Vertices())
   {
      olc::Pixel color = olc::CYAN;
      if (v == startNode) color = olc::GREEN;
      if (v == endNode) color = olc::RED;
      FillCircle(v % width, v / width, VERTEX_RADIUS, color);
   }
}

// When a mouse button is pushed, find the vertex which was selected
// and return it
int Application::cellSelected(bool leftMouse)
{
   int x = GetMouseX();
   int y = GetMouseY();
   for (int v : wgraph->Vertices())
   {
      int vX = v % width;
      int vY = v / width;
      if (sqrt(pow(x-vX,2) + pow(y-vY,2)) <= VERTEX_RADIUS)
         return v;
   }
   return (leftMouse) ? startNode : endNode;
}

// Given a list of vertices from the graph, draw a path
// between them based on the passed in vertex list
void Application::drawPath(list<int> path)
{
   int v = startNode;
   for (int w : path)
   {
      DrawLine(v % width, v / width, w % width, w / width, olc::BLUE); 
      v = w;
   }
}

// Draw the edges in the edges vector.  The integer 'number' passed in
// tell the function how far into the edges vector to draw.  This
// allows us to incrementally show more and more of the edge list
// giving the impression that the algorithm is being animated.
// In reality, it's not, the two MST algorithms add edges to the
// edge vector as they're discovered so, if we slowly reveal more
// and more of the vector of edges, it looks like we're animating
// the algorithm.  Very tricksy (and not particularly efficienct
// but that's not the goal)
void Application::drawEdges(std::vector<Edge> edges, int number)
{
   for (int i = 0 ; i < number ; i++)
   {
      int v = edges[i].either();
      int w = edges[i].other(v);
      DrawLine(v % width, v / width, w % width, w / width, olc::BLUE);
   }
}

// Depending on which key was pressed in OnUserUpdate, this function
// will run one the specified algorithm.  Dijkstra's shortest path
// or either Kruskal's or Prim's MST algorithm.  We run the algorithm
// in question once but then slowly reveal more and more of the edge
// list from them (except Dijkstra, we just show the path)
void Application::drawFunction()
{
   static std::vector<Edge> edges;

   if (functionType == DIJKSTRA)
   {
      Dijkstra dij(wgraph, startNode);
      drawPath(dij.pathTo(endNode));
      return;
   }
   else if (functionType == KRUSKAL)
   {
      if (index == 0)
      {
         KruskalMST kruskal(wgraph);
         edges = kruskal.Edges();
      }
   }
   else if (functionType == PRIM)
   {
      if (index == 0)
      { 
         PrimMST prim(wgraph, endNode);
         edges = prim.Edges();
      }
   }
   
   index = min(index+1, (int)edges.size());
   drawEdges(edges, index);
} 

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   drawGraph();

   // Handle user input
   if (GetMouse(0).bReleased) { index = 0 ; startNode = cellSelected(true); }
   if (GetMouse(1).bReleased) { index = 0 ; endNode = cellSelected(false); }
   if (GetKey(olc::Key::J).bPressed) { index = 0 ; functionType = DIJKSTRA; }
   if (GetKey(olc::Key::K).bPressed) { index = 0 ; functionType = KRUSKAL; }
   if (GetKey(olc::Key::P).bPressed) { index = 0 ; functionType = PRIM; }

   drawFunction();

   // Exit if the escape key or the 'q' key was pressed
   return (!(GetKey(olc::Key::ESCAPE).bPressed) &&
           !(GetKey(olc::Key::Q).bPressed));
}

bool Application::OnUserDestroy()
{
   delete wgraph;
   return true;
}
