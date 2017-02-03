#ifndef Button_H
#define Button_H

#include "SDL.h"
#include "SDL_image.h"
#include "Image.h"
#include "Clickable.h"
#include "label.h"

#include <string>
#include "SDL_ttf.h"


class Button : public Image, public Clickable
{
public:
     Button();
     Button(int x, int y, int w, int h, const char* imgurl);
     void Clicked();
     void set_button(int x, int y, int w, int h ,int color= 5);
     Label lbl;
     
     void b_show(SDL_Surface* , std::string, std::string);
};


#endif
