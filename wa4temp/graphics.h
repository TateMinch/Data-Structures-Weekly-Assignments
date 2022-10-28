#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GL/freeglut.h>
#include <iostream>

enum ColorType {RED=0,GREEN, BLUE, WHITE, BLACK, ORANGE, GOLD, EMERALD, RUBY, SILVER, COPPER, SAPPHIRE, INVISIBLE, LAST_COLOR};

const std::string ColorName[]
{
   "Red", "Green", "Blue", "White", "Black", "Orange", "Gold", "Emerald", "Ruby", "Silver", "Copper", "Sapphire", "Invisible", "No Color"
};

const float Colors[][3] = {
   {1.0, 0.0, 0.0},  // RED
   {0.0, 1.0, 0.0},  // GREEN
   {0.0, 0.0, 1.0},  // BLUE
   {1.0, 1.0, 1.0},  // WHITE
   {0.0, 0.0, 0.0},  // BLACK
   {1.0, 0.55, 0.0},  // ORANGE
   {1.0, 215.0/255, 0}, // GOLD
   {31.0/255, 78.0/255, 47.0/255}, // EMERALD
   {88.0/255, 7.0/255, 37.0/255}, // RUBY
   {192.0/255, 192.0/255, 192.0/255}, // SILVER
   {72.0/255, 45.0/255, 20.0/255}, // COPPER
   {6.0/255, 32.0/255, 73.0/255}, // SAPPHIRE
   {0.0, 0.0, 0.0}, // INVISIBLE
};

void DrawRectangle(float, float, float, float, ColorType color);
void DrawFilledRectangle(float, float, float, float, ColorType f);
void DrawLine(float, float, float, float, ColorType color);
void DrawTextString( const char *string, int x, int y, ColorType color);
#endif
