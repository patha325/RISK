
#ifndef UI_ELEMENTS_H
#define MENY_H
#include "SDL.h"
#include "SDL/SDL_image.h"

#include <string>

class Button
{
    private:
    SDL_Rect* dim;

    public:
    Button( int x, int y, int w, int h );
    int handle_events();
    void show(SDL_Surface* surf);
};


class Image
{

 private:
  SDL_Rect* dim;

 public:
  Image ( int x, int y, int w, int h);
  void show(SDL_Surface* surf, const char* imgurl);

};

class Textfield
{
 private:
  SDL_Rect* dim;
  SDL_Rect* idim;
  //bool indic_active;

 public:
  Textfield (int x, int y, int w);
  void show(SDL_Surface* surf);
  void fetch_data();
  void show_indic(SDL_Surface* surf2);
  void hide_indic(SDL_Surface* surf3);
  bool active_TF();

};


#endif
