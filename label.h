#ifndef LABEL_H
#define LABEL_H


#include "SDL/SDL_ttf.h"

#include <string>

class Label
{
 private:
  TTF_Font *font;
  SDL_Color labelc;
  SDL_Rect* dim;

  const char* ifont;
  int size;
  int colorn;

 public:
  Label();
  Label( int x, int y);
  void show(SDL_Surface*, const char*); 
  void set_label(int, int, const char*, int , int); 
	  
};

#endif
