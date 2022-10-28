#ifndef EVENT_H_
#define EVENT_H_
#include <iostream>
#include <GL/freeglut.h>
#include <sstream>
#include "application.h"

using namespace std;

#define ESCAPE_KEY 27

// Yes, technically these should all be in their own interface/implementation
// files.  It's just easier to manage this way since this is frequently changed
// What should be done is to abstract the Application object into a base class 
// and then just always derive your actual state class from that.

/***************************************************************************//**
 * @class Event abstract base class
 ******************************************************************************/
class Event
{
public:
   virtual void doAction(Application&) = 0;
   virtual ~Event();
};

/***************************************************************************//**
 * @class InitEvent - initialization event
 ******************************************************************************/
class InitEvent : public Event
{
   /// The number of columns and rows (width and height) of the window
   int columns, rows;
public:
   InitEvent(int, int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class DisplayEvent - display event
 ******************************************************************************/
class DisplayEvent : public Event
{
public:
   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class KeyboardEvent : public Event
{
   /// The key involved in this event
   unsigned char key;
   /// The x-location of where the event took place
   int xLoc;
   /// The y-location of where the event took place
   int yLoc;

public:
   /// Constructor
   KeyboardEvent(unsigned char, int, int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class MouseClickEvent : public Event
{
   /// The button involved in the event
   int button;
   /// The state of the button for this event (e.g. up, down)
   int state;
   /// The x-location of where the event took place
   int xLoc;
   /// The y-location of where the event took place
   int yLoc;

public:
   /// Constructor
   MouseClickEvent(int, int, int, int);

   void doAction(Application &);

private:
   bool isLeft();
   bool isRight();
   bool isDown();
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class MouseDragEvent : public Event
{
   /// The x-location of where the event took place
   int xLoc;
   /// The y-location of where the event took place
   int yLoc;

public:
   /// Constructor
   MouseDragEvent(int, int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class MouseMoveEvent : public Event
{
   /// The x-location of where the event took place
   int xLoc;
   /// The y-location of where the event took place
   int yLoc;

public:
   /// Constructor
   MouseMoveEvent(int, int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class ReshapeEvent : public Event
{
   /// The new width after the reshape (resize) of the window completes
   int width;
   /// The new height after the reshape (resize) of the window completes
   int height;
public:
   ReshapeEvent(int, int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class TimerEvent : public Event
{
   int tick;
public:
   TimerEvent(int);

   void doAction(Application &);
};

/***************************************************************************//**
 * @class
 ******************************************************************************/
class CloseEvent : public Event
{
public:
   CloseEvent();

   void doAction(Application &);
};
#endif
