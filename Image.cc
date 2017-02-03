#include "Image.h"
#include "SDL.h"
#include "SDL_image.h"

#include <string>

Image::Image() {}

Image::Image ( int x, int y, int w, int h, 
const char* imgurl)
{
     dim.x = x;
     dim.y = y;
     dim.w = w;
     dim.h = h;

     surf = IMG_Load(imgurl);
}

void Image::set_image ( int x, int y, int w, int h)
{
     dim.x = x;
     dim.y = y;
     dim.w = w;
     dim.h = h;


}

Image::~Image()
{
     SDL_FreeSurface(surf);
}

void Image::show(SDL_Surface* dest_surf, const char* imgurl)
{  
  surf = IMG_Load(imgurl);
  SDL_BlitSurface(surf, NULL, dest_surf, &dim);
}


