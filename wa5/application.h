#ifndef APPLICATION_H
#define APPLICATION_H
#include "olcPixelGameEngine.h"
#include <fstream>
#include <iostream>
#include "function.h"
#include "hashTable.h"

typedef unsigned char byte;

class Application : public olc::PixelGameEngine
{
   char *filename;
   HashTable hash;
   int width, height;
   std::ifstream inputStream;

public:
   Application(char *);

public:
   bool OnUserCreate() override;
   bool OnUserUpdate(float) override;
   bool OnUserDestroy() override;

private:
   void updateDisplay();
};

#endif
