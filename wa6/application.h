#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "maze.h"

typedef unsigned char byte;

class Application : public olc::PixelGameEngine
{
   unsigned width, height;
   int nCellSize;
   int edgeWidth;
   Maze *maze;
   bool animate;
public:
   Application(int, int);

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;
   void drawGrid();
   void completeMaze();
   void resetMaze();
};

#endif
