#ifndef Clickable_H
#define Clickable_H

#include "SDL.h"
#include "SDL_image.h"

#include <string>


class Clickable
{
public:
   Clickable();
     Clickable ( int x, int y, int w, int h);
     void Clicked();
     bool hit(int x, int y);
     void set_clickable(int x, int y, int w, int h);
private:     
     int x_;
     int y_;
     int w_;
     int h_;
};   
#endif
