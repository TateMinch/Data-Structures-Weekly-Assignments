#define OLC_PGE_APPLICATION
#include "application.h"

int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      cout << "Usage: " << argv[0] << " text_file" << endl;
   }
   else
   {
      Application demo(argv[1]);
      if (demo.Construct(500, 500, 1, 1))
         demo.Start();
   }

   return 0;
}
