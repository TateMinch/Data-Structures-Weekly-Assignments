#include <iostream>
#include "graphics.h"

void DrawRectangle(float x1, float y1, float x2, float y2, ColorType c)
{
    glColor3fv( Colors[c] );
    glBegin( GL_LINE_LOOP );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

void DrawFilledRectangle(float x1, float y1, float x2, float y2, ColorType c)
{
    glColor3fv( Colors[c] );
    glBegin( GL_POLYGON );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y1 );
        glVertex2f( x2, y2 );
        glVertex2f( x1, y2 );
    glEnd();
    glFlush();
}

void DrawTextString(const char *str, int x, int y, ColorType c)
{
    glColor3fv( Colors[c] );
    glRasterPos2i( x, y );
    while ( *str )
       glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *str++ );
}

void DrawLine( float x1, float y1, float x2, float y2, ColorType c)
{
    // glLineWidth( 10 );
    glColor3fv( Colors[c] );
    glBegin( GL_LINES );
        glVertex2f( x1, y1 );
        glVertex2f( x2, y2 );
    glEnd();
    glFlush();
}
