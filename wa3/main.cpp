#define OLC_PGE_APPLICATION
#include "application.h"

int main(int argc, char *argv[])
{
   Application demo(argv[1]);
   if (demo.Construct(256, 240, 1, 1))
      demo.Start();

   return 0;
}
