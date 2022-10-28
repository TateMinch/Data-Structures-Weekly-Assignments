/***************************************************************************//**
 * @file callbacks.cpp
 ******************************************************************************/
#include "callbacks.h"

// The callbacks are functions sent to FreeGlut when subscribing to events
// that are of interest to the program.  We make them very thin since they
// are useless in terms of maintaining or modifying state without using
// unsavory things like global variables.

// There are callback functions in here that might not be used in a specific
// application (mouseDrag, mouseMove, etc.)  They're here so I don't need
// to create them each time something changes.

// OpenGL thinks the y = 0 coordinate is at the top of the screen.  Flip it over
int actualY(int y)
{
   return glutGet(GLUT_WINDOW_HEIGHT) - y;
}

/***************************************************************************//**
 * @brief A callback function for refreshing the display
 ******************************************************************************/
void display() 
{
   utilityCentral(new DisplayEvent());
}

/***************************************************************************//**
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x   - the x-coordinate when the key was pressed
 * @param[in] y   - the y-coordinate when the key was pressed
 ******************************************************************************/
void keyboard(unsigned char key, int x, int y)
{
   utilityCentral(new KeyboardEvent(key, x, actualY(y)));
}

/***************************************************************************//**
 * @brief A callback function for handling window resize events
 *
 * @param[in] w      - new window width
 * @param[in] h      - new window height
 ******************************************************************************/
void reshape(const int w, const int h)
{
    // dispatch the reshape event
    utilityCentral(new ReshapeEvent(w, h));
}

/***************************************************************************//**
 * @brief A callback function for handling the close event.  This happens
 *    when the [x] in the upper right corner of the window is pressed but 
 *    not reliably due to GLUT implementation decisions.  This is the catchall
 *    for all close events (escape key, [x], 'q' key, etc.)
 *
 * @param[in] w      - new window width
 * @param[in] h      - new window height
 ******************************************************************************/
void onClose()
{
   utilityCentral(new CloseEvent());
}

/***************************************************************************//**
 * @brief Main event dispatch function
 *
 * Any events to which the application has subscribed will be routed through
 * this function.  If you need to maintain application state, this is a good
 * place to do so.  All events have an 'action' method which take a Game
 * object.  The Game class can react to the various events by inspecting the
 * event object that is currently acting.
 *
 * @param[in] event - Pointer to an Event object.
 ******************************************************************************/
void utilityCentral(Event *event)
{
   static Application application;

   event->doAction(application);
   delete event;
}

/***************************************************************************//**
 * Initialize glut callback functions, set the display mode, create a window
 ******************************************************************************/
void initOpenGL(int argc, char** argv, int wCols, int wRows)
{
   glutInit(&argc, argv);

// Choose the display mode for the window.  GLUT_DOUBLE means double buffering
// GLUT_SINGLE is single buffering.  GLUT_RGBA is 24-bit color with 8-bit alpha

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

   glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,GLUT_ACTION_CONTINUE_EXECUTION);

// Set window size and position
   glutInitWindowSize(wCols, wRows);

   glutInitWindowPosition(100, 100);

   glutCreateWindow("SD Mines - Paint");

// Subscribe to GLUT events

   glutDisplayFunc(display);

   glutKeyboardFunc(keyboard);

   glutReshapeFunc(reshape);

   glutCloseFunc(onClose);

// This is the color which will be used to clear the display / back plane
// when glClear() is called
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

// Use the InitEvent object to perform startup operations for the application
// This could also be done in the Canvas constructor without needing another
// derived event type
   utilityCentral(new InitEvent(wCols, wRows));
}
