#include "SDL.h"
#include "SDL_image.h"
#include "ui_elements.h"


Button::Button( int x, int y, int w, int h )
{
  dim = new SDL_Rect;
  dim->x = x;
  dim->y = y;
  dim->w = w;
  dim->h = h;
}

void Button::show(SDL_Surface* surf)
{
    SDL_FillRect( surf, dim, SDL_MapRGB( surf->format, 0xFF, 0x00, 0x00 ) );
}

int Button::handle_events()
{
    //The mouse offsets
    int x = 0, y = 0;
    SDL_Event event;
    
    /*
    //If the mouse moved
    if( event.type == SDL_MOUSEMOTION )
    {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;
        
        //If the mouse is over the button
        if( ( x > dim->x ) && ( x < dim->x + dim->w ) && ( y > dim->y ) && ( y < dim->y + dim->h ) )
        {
	  //state = 1;
        }   
	
	else 
	  {
	    //state
	  }
	
    }

    */

    //If a mouse button was pressed
    if( event.type == SDL_MOUSEBUTTONDOWN )
      {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
	  {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;
	    
            //If the mouse is over the button
            if( ( x > dim->x ) && ( x < dim->x + dim->w ) && ( y > dim->y ) && ( y < dim->y + dim->h ) )
	      {
		return 2;
	      }
	  }
      }
    
    
    //If a mouse button was released
    if( event.type == SDL_MOUSEBUTTONUP )
      {
        //If the left mouse button was released
        if( event.button.button == SDL_BUTTON_LEFT )
	  { 
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;
	    
            //If the mouse is over the button
            if( ( x > dim->x ) && ( x < dim->x + dim->w ) && ( y > dim->y ) && ( y < dim->y + dim->h ) )
	      {
		return 3;
	      }
	  }
      }
    
    return 0;
}


////////////////////////////////

Image::Image(int x, int y, int w, int h)
{
  dim = new SDL_Rect;
  dim->x = x;
  dim->y = y;
  dim->w = w;
  dim->h = h;
  
}


void Image::show(SDL_Surface* surf, const char* imgurl)
  {
  
    SDL_Surface* image = surf;
    image = SDL_LoadBMP( imgurl );
    SDL_BlitSurface( image, NULL, surf, NULL );
  
  }

////////////////////////////////

Textfield::Textfield(int x, int y, int w)
{
  dim = new SDL_Rect;
  dim->x = x;
  dim->y = y;
  dim->w = w;
  dim->h = 30;
  
}

void Textfield::fetch_data()
{
  
}


void Textfield::show(SDL_Surface* surf)
{
  SDL_FillRect( surf, dim, SDL_MapRGB( surf->format, 0xFF, 0xFF, 0xFF ) );
}
