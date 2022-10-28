#ifndef READPNG_H
#define READPNG_H
#include <iostream>
#include "lodepng.h"
#include "olcPixelGameEngine.h"
#include "alloc2d.h"

using namespace std;

olc::Pixel **readPNG(const char *filename, unsigned &width, unsigned &height);
bool **convertToBitMap(olc::Pixel **image, unsigned width, unsigned height);
#endif
