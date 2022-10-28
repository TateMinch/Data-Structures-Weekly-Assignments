#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "graph.h"

typedef unsigned char byte;

class Application : public olc::PixelGameEngine
{
   unsigned width, height;
   Graph *graph;
public:
   Application();

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;

private:
   void drawGraph();
};

#endif
