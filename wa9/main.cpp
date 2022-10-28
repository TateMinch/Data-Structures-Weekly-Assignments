#define OLC_PGE_APPLICATION
#include <iostream>
#include "application.h"

using namespace std;

int main(int argc, char *argv[])
{
   int W = 900;
   if (argc == 2)
   {
      try
      {
         W = stoi(argv[1]);
      }
      catch (...)
      {
         cout << "Usage: " << argv[0] << "[W]" << endl;
         cout << "optional: W = Width of the window (default 900)" << endl;
         return -1;
      }
   }
   Application demo(W);
   if (demo.Construct(W, W, 1, 1))
      demo.Start();
   return 0;
}
