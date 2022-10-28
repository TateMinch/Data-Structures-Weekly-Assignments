#include "event.h"

Event::~Event() {}

/***************************************************************************//**
 * @brief Constructor
 *
 * This event should only happen once on initial startup.  If the app state
 * needs initialization, here is where that would likely happen
 *
 * @param[in] c - columns (in pixels) of the window
 * @param[in] r - rows (in pixels) of the window
 ******************************************************************************/
InitEvent::InitEvent(int c, int r) : columns(c), rows(r) {}

void InitEvent::doAction(Application &app)
{
   glClear(GL_COLOR_BUFFER_BIT);
   app.onInit(); // Here any app initialization happens
}

/***************************************************************************//**
 * @brief Constructor
 *
 * Display event is called under a number of circumstances.  During its action
 * method, we just swap the buffers (we are assuming double buffer mode)
 * If there is a repaint required by the app, here is where that would likely
 * happen
 ******************************************************************************/
void DisplayEvent::doAction(Application &app)
{
   glClear(GL_COLOR_BUFFER_BIT);
   app.onRedraw();
   glutSwapBuffers();
}

/***************************************************************************//**
 * @brief Constructor
 *
 * This event gets called continuously as the window is resized.  This event
 * usually also triggers a display event
 *
 * @param[in] w - width (in pixels) of the window
 * @param[in] h - height (in pixels) of the window
 ******************************************************************************/
ReshapeEvent::ReshapeEvent(int w, int h) : width(w), height(h) {}

void ReshapeEvent::doAction(Application &app)
{
   // Set type of perspective (projection, modelview)
   glMatrixMode( GL_PROJECTION);
   // Load the identity matrix
   glLoadIdentity();
    // project 3d world space into 2d
   gluOrtho2D(0.0, width, 0.0, height);
    // point the camera at the 2d projection
   glViewport(0, 0, width, height);
}

/***************************************************************************//**
 * @brief Constructor
 *
 * A keyboard key has been pressed.  This object's action method will react
 * to the escape key by leaving the main glut event loop.  If you need to do
 * resource freeing, doing so before leaving the glut main loop (or immediately
 * thereafter) is suggested
 *
 * @param[in] k - the ascii value of the key that was pressed
 * @param[in] x - the x-coordinate of where the key 'k' was pressed
 * @param[in] y - the y-coordinate of where the key 'k' was pressed
 ******************************************************************************/
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k), xLoc(x), yLoc(y) {}

void KeyboardEvent::doAction(Application &app)
{
   if (key == ESCAPE_KEY)
      glutLeaveMainLoop();
   else
      app.onKey(key);
}

CloseEvent::CloseEvent() {}

void CloseEvent::doAction(Application &app)
{
   app.onClose();
}
