#include <iostream>
#include "application.h"

using namespace std;

Application::Application(char *fname) : filename(fname)
{
   sAppName = "Hash HeatMap";
}

// Called once at the start, so create things here
bool Application::OnUserCreate()
{
   inputStream.open(filename, std::ios_base::in);
   return true;
}

// Convert a scaled number into a scaled color
olc::Pixel calcColor(int minimum, int maximum, int value)
{
   float mn = minimum;
   float mx = maximum;
   float ratio = 2.0 * (value - mn) / (mx - mn);
   float red = (0.0 > (ratio-1.0)) ? 0.0 : (ratio - 1.0);
   float blue = (0.0 > (1.0-ratio)) ? 0.0 : (1.0 - ratio);
   float green = 1.0 - blue - red;
  
   return olc::PixelF(red, green, blue);
}

// Update the display after every new word placed in the hash table
// The grid is N x N where N = sqrt(HashTable.capacity)
void Application::updateDisplay()
{
   Clear(olc::BLACK);
   int nMapWidth = sqrt(hash.tableSize()) + 1;
   int nMapHeight = nMapWidth;
   int nBorderWidth = 2;
   int nCellSize = ScreenWidth() / nMapWidth;
   int maxVal = 0;
   for (string word : hash.getKeys())
   {
      int hashVal = hash.hashFn(word);
      maxVal = max(maxVal, hash.size(hashVal));
   }

   for (int x = 0 ; x < nMapWidth ; x++)
   {
      for (int y = 0 ; y < nMapHeight ; y++)
      {
         FillRect(x * nCellSize, y * nCellSize, nCellSize - nBorderWidth, nCellSize - nBorderWidth, olc::WHITE);
      }
   }

   for (string word : hash.getKeys())
   {
      int hashVal = hash.hashFn(word);
      int x = hashVal % nMapWidth;
      int y = hashVal / nMapWidth;
      olc::Pixel color = calcColor(0, maxVal, hash.size(hashVal));
      FillRect(x * nCellSize, y * nCellSize, nCellSize - nBorderWidth, nCellSize - nBorderWidth, color);
   }
}

// This member function is called repeatedly until the program exits.
bool Application::OnUserUpdate(float fElapsedTime)
{
   static bool notDone = true;

   if (notDone)
   {
      try
      {
         string nextWord = readNextWord(inputStream);
         hash[nextWord]++;
         updateDisplay();
      }
      catch (const char *msg)
      {
         notDone = false;
         for (string word : hash.getKeys())
            cout << word << " " << hash[word] << endl;
      }
   }
   return true;
}

bool Application::OnUserDestroy()
{
   return true;
}
