/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef APPLICATION_H
#define APPLICATION_H
#include <iostream>
#include <sstream>
#include <vector>
#include "graphics.h"
#include "node.h"
#include "wa4.h"

#define ENTER_KEY 13

/// Width of the graphical node to draw
const int NODE_WIDTH = 20;
/// Height of the graphical node to draw
const int NODE_HEIGHT = 20;

using namespace std;

/********************************************************************//**
 * @class Application
 **********************************************************************/
class Application
{
   /// Root pointer
   Node *root;
public:
   Application();

   /// Function to accumulate keys for a node value
   void addToNodeVal(char key);

   void onClose();
   void onInit();
   void onRedraw();
   void onKey(unsigned char);
};
#endif
