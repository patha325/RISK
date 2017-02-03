#include "SDL.h"
#include "SDL_image.h"
#include "Clickable.h"

#include <string>

Clickable::Clickable(){}


Clickable::Clickable( int x, int y, int w, int h)
{
     x_=x;
     y_=y;
     w_=w;
     h_=h;
}

void Clickable::Clicked()
{
     
}

void Clickable::set_clickable(int x, int y, int w, int h)
{
  x_=x;
  y_=y;
  w_=w;
  h_=h;
}

bool Clickable::hit(int x, int y)
{
     //Am I inside the "box"?
     if (x >= x_ && x <= x_+w_ &&  y >= y_ && y <= y_+h_)
	  return true;
     return false;
}
