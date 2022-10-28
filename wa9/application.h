#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "bfsPaths.h"
#include "dfsPaths.h"
#include "bridges.h"
#include <list>

typedef unsigned char byte;
enum PATHTYPE {NONE, BFS, DFS};

class Application : public olc::PixelGameEngine
{
   int width;
   Graph *graph;
   int startNode, endNode;
   PATHTYPE pathType;
public:
   Application(int);

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;
   void drawGraph();
   int cellSelected(bool);
   void edgeSelected();
   void drawPath(list<int>&);
};

#endif
