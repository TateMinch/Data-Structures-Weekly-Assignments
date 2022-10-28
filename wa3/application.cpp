#include "application.h"
#include <iostream>

using namespace std;

Application::Application(const char *filename) : filename(filename)
{
   sAppName = "Application";
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
      // read an RGBA PNG image from a file
   image = readPNG(filename, width, height);
   // convert RGBA Pixels into boolean values.  true = white, false = black
   bitMap = convertToBitMap(image, width, height);
   // Matches the window size to the width and height of the image, the
   // game engine handles scaling so resizing the window will scale the
   // QR image proportionally
   olc::PixelGameEngine::SetScreenSize(width, height);

   for(int i = 0; i < height; i++)
   {
      for(int j = 0; j < width; j++)
      {
         if(image[i][j] != image[i][j+1])
         {
            cout << "QR code located at " << j + 1 << ", " << i << endl;
            return true;
         }
      }
   }
   return true;
}

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   // This draws the QR image into the window.
   for (int y = 0; y < ScreenHeight(); y++)
      for (int x = 0; x < ScreenWidth(); x++)
         Draw(x, y, (bitMap[y][x] ? olc::WHITE : olc::BLACK));
         // could draw the color image this way
         // Draw(x, y, image[y][x]);
   return true;
}

bool Application::OnUserDestroy()
{
   free2D(bitMap);
   free2D(image);
   return true;
}
