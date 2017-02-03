#include "label.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <iostream>
#include <sstream>


Label::Label()
{
  dim = new SDL_Rect;
}

Label::Label(int x , int y)
{
  dim = new SDL_Rect;
  dim->x = x;
  dim->y = y;
  
  

}

void Label::show(SDL_Surface* surf, const char* labeltext)
{
  
  SDL_Surface* labelsurf = NULL;
  labelsurf = TTF_RenderText_Solid( font, labeltext, labelc );

  if( labelsurf == NULL )
    {
      std::cerr << "label content failure" << std::endl;
    }

  SDL_BlitSurface( labelsurf, NULL, surf, dim );

  
  
}

void Label::set_label(int x, int y, const char* init_ifont , int init_size , int colorn)
{
  dim->x = x;
  dim->y = y;

  ifont = init_ifont;
  size = init_size;

	if (colorn == 0)
	{
		labelc = { 255, 0, 0 };
	}
	else if (colorn == 1)
	{
		labelc = { 0, 255, 0 };
	}
	else if (colorn == 2)
	{
		labelc = { 0, 0, 255 };
	}
	else if (colorn == 3)
	{
		labelc = { 255, 255, 0 };
	}
	else if (colorn == 4)
	  {
	    labelc = {255,255,255};
	  }
	else 
	{
		labelc = { 0, 0, 0 };
	}

font = TTF_OpenFont( ifont, size );
  if( font == NULL )
    {
      std::cerr << "font load failure" << std::endl;
    }

}
