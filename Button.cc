#include "Button.h"
#include "Clickable.h"
#include "SDL.h"
#include "SDL_image.h"
#include "label.h"
#include <string>
#include "SDL_ttf.h"
#include "Image.h"
#include <iostream>

Button::Button() : Image(), Clickable()
{
}


Button::Button( int x, int y, int w, int h, 
const char* imgurl)
     : Image( x, y, w, h, imgurl), Clickable( x, y ,w ,h)
{
     
}

void Button::set_button( int x, int y, int w, int h , int color)
{
  set_image( x,  y,  w,  h);
  set_clickable(x,y,w,h);

  lbl.set_label(x+5,y+8,"data-latin.ttf",20,color);
  }



void Button::b_show(SDL_Surface* dest_surf, std::string color, std::string text)
{
  const char* colors = color.c_str();
  show(dest_surf,colors);
  const char* str = text.c_str();

  lbl.show(dest_surf,str);
}

void Button::Clicked()
{
     
}
