#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "dijkstra.h"
#include "kruskalMST.h"
#include "primMST.h"
#include <list>

typedef unsigned char byte;
enum FUNCTION {NONE, DIJKSTRA, KRUSKAL, PRIM};

class Application : public olc::PixelGameEngine
{
   int width;
   WeightedGraph *wgraph;
   int startNode, endNode;
   FUNCTION functionType;
   int index;
public:
   Application(int);

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;
   void drawGraph();
   int cellSelected(bool);
   void edgeSelected();
   void drawPath(std::list<int>);
   void drawEdges(std::vector<Edge>, int);
   void drawFunction();
};

#endif
