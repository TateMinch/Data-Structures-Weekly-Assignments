#define OLC_PGE_APPLICATION
#include <iostream>
#include "application.h"

using namespace std;

int main(int argc, char *argv[])
{
   int N = 15;
   if (argc != 1 && argc != 2)
   {
      cout << "Usage: " << argv[0] << "[N]" << endl;
      cout << "optional: N = build an N x N maze (default 15)" << endl;
   }
   else
   {
      if (argc == 2)
      {
         try
         {
            N = stoi(argv[1]);
         }
         catch (...)
         {
            cout << "Usage: " << argv[0] << "[N]" << endl;
            cout << "optional: N = build an N x N maze (default 15)" << endl;
            return -1;
         }
      }

      Application demo(N, N);
      if (demo.Construct(900, 900, 1, 1))
         demo.Start();
   }
   return 0;
}
