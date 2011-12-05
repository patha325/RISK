#include "SDL.h"
#include "SDL_image.h"
#include "ui_elements.h"
#include <string>
#include <iostream>


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
  
  if (SDL_PollEvent(&event))
    {
      
      if (event.type == SDL_QUIT)
	{
	  return 4;
	}
      
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
      return 1;
      }   
      
      else 
      {
      return 0; 
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

// char*
void Image::show(SDL_Surface* surf, const char* imgurl)
{
  
  SDL_Surface* image = NULL;
  //image = SDL_LoadBMP ("earth.bmp");
  //SDL_Surface* surf = NULL;
  image = SDL_LoadBMP(imgurl);
  if (image == NULL) 
    {
      std::cerr << "image was null for url: \"" << imgurl << "\"" << std::endl;
      exit(1);
    }
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
  /*
  int x = 0, y = 0;
  SDL_Event event;



  
  if (SDL_PollEvent(&event))
    {
	//If a key was pressed if
	( event.type == SDL_KEYDOWN ) 
	  {
	    //textinput
	  }
      }
  
  */

}


void Textfield::show(SDL_Surface* surf)
{
  SDL_FillRect( surf, dim, SDL_MapRGB( surf->format, 0xFF, 0xFF, 0xFF ) );
}

void Textfield::show_indic(SDL_Surface* surf2)
{ 
  dim->x = dim->x - 20;
  dim->w = 20;
  dim->h = 20;

  SDL_FillRect( surf2, dim, SDL_MapRGB( surf2->format, 0x00, 0xFF, 0x00 ) );
  
  dim->x = dim->x + 20;
}

void Textfield::hide_indic(SDL_Surface* surf3)
{ 
  dim->x = dim->x - 20;
  dim->w = 20;
  dim->h = 20;

  SDL_FillRect( surf3, dim, SDL_MapRGB( surf3->format, 0xFF, 0x00, 0x00 ) );
  
  dim->x = dim->x + 20;
}


bool Textfield::active_TF()
{

  int x = 0, y = 0;
  SDL_Event event;
  
  if (SDL_PollEvent(&event))
    {
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
		  return true;
		}
	    }
	}

      return false;
    }


}
