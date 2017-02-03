#ifndef Image_H
#define Image_H

#include "SDL.h"
#include "SDL_image.h"

#include <string>


class Image
{

 public:
  SDL_Rect dim;
  SDL_Surface* surf;
    
  Image();
  Image ( int x, int y, int w, int h, 
	  const char* imgurl);
  void set_image ( int x, int y, int w, int h);
  ~Image();
  void show(SDL_Surface* dest_surf, const char* imgurl);
};


#endif
