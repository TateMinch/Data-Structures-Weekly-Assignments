#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "bellmanFord.h"
#include <list>

#define BLOCKED olc::GREY
#define START olc::GREEN
#define END   olc::RED
#define HEAVY olc::VERY_DARK_YELLOW
#define MEDIUM olc::DARK_YELLOW
#define LIGHT olc::YELLOW
#define NORMAL olc::BLUE

const std::map<int, olc::Pixel> intToPixel = {
   {1, olc::BLUE}, {2, olc::YELLOW}, {3, olc::DARK_YELLOW},
   {4, olc::VERY_DARK_YELLOW}, {6, olc::RED}, {7, olc::GREEN}, {-1, olc::GREY}
};

class Application : public olc::PixelGameEngine
{
   int mapHeight, mapWidth, cellSize, border;
   WeightedGraph *wgraph;
   int startNode, endNode;
   std::vector<std::vector<int>> grid;
   BellmanFord *bf;
public:
   Application(int width);

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;
   void drawGraph();
   //void drawPath(bool);
   //void drawCell(int, olc::Pixel);
   int cellSelected(bool);
};

#endif
