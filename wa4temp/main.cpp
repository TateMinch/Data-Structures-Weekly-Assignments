#include "callbacks.h"

/// We like our main very lean
int main(int argc, char** argv)
{
   initOpenGL(argc, argv, 900, 600);

   glutMainLoop();
   
   return 0;
}
