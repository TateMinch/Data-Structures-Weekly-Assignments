#ifndef ALLOC2D_H
#define ALLOC2D_H

#include <cstring>
#include "olcPixelGameEngine.h"

bool **alloc2D_bool( int nrows, int ncols );
olc::Pixel** alloc2D( int nrows, int ncols );
void free2D( bool **image );
void free2D( olc::Pixel** image );

#endif
