/********************************************************************//**
 * @file
 ***********************************************************************/
#include "application.h"
#include <iostream>
#include <cmath>

using namespace std;

Application::Application() {}

void Application::onClose()
{
   delete root;
}

void Application::onInit() {}

void Application::onKey(unsigned char key)
{
   static string nodeVal;
   // If the key was not the enter key, accumulate the value
   if (key == ENTER_KEY)
   {
      int val;
      stringstream stream1;
      stream1.str(nodeVal);
      stream1 >> val;
      root = insert(root, val);
      nodeVal.clear();
      glutSetWindowTitle("Tree Viewer - Enter integers followed by <return>");
      glutPostRedisplay();
   }
   else
   {  
      nodeVal += key;
      glutSetWindowTitle(nodeVal.c_str());
   }
}

/***************************************************************************//**
 * @brief Draw a node and the line connecting it to its parent
 *
 * @param[in] x - The window x-coordinate to draw the node
 * @param[in] y - The window y-coordinate to draw the node
 * @param[in] root - Node pointer for the node to draw
 * @param[in] depth - Integer describing the depth of the node
 ******************************************************************************/
void drawNode(int x, int y, Node* root, int depth)
{
   if (root == nullptr) return;

   stringstream ss;
   ss << root->data;
   DrawTextString(ss.str().c_str(), x, y, WHITE);
   if (root->left != nullptr)
   {
      drawNode(x - (256 >> depth), y - 64, root->left, depth+1);
      DrawLine(x, y, x-(256 >> depth), y-64, WHITE);
   }
   if (root->right != nullptr)
   {
      drawNode(x + (256 >> depth), y - 64, root->right, depth+1);
      DrawLine(x, y, x+(256 >> depth), y-64, WHITE);
   }
   return;
}

/***************************************************************************//**
 * @brief Function to start the drawing of the treee
 ******************************************************************************/
void Application::onRedraw()
{
   int xs = glutGet(GLUT_WINDOW_WIDTH) / 2;
   int ys = glutGet(GLUT_WINDOW_HEIGHT) - 30;
   
   drawNode(xs, ys, root, 0);
   glutPostRedisplay();
}
