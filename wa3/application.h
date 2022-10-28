#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include "readPNG.h"

typedef unsigned char byte;

class Application : public olc::PixelGameEngine
{
   const char *filename;
   olc::Pixel **image;
   bool **bitMap;
   unsigned width, height;
public:
	Application(const char *);

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float) override;
    bool OnUserDestroy() override;
};

#endif
