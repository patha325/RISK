#ifndef GAME_UI_H
#define GAME_UI_H

class Game_Engine;

#include "SDL.h"
#include "SDL_ttf.h"
#include "label.h"
#include "Button.h"
#include "Image.h"
#include "Clickable.h"
#include <iostream>
#include <string>

class Game_UI 
{

 private:
  Game_Engine* game;

  SDL_Event event;
  SDL_Surface* screen;
  int mscrh;
  int mscrw;
  int scrh;
  int scrw;
  int bitdepth;
  int activate_gameengine;
  bool screen_active;
  
  //Menu Variables:

  Image menubg;
  Button start;



  //Game Variables:
  
  int counter;

  Label counter_lbl;

  Button end;
  Button up;
  Button down;
  Button energize;

  Button alaska;
  Button northwest_territory;
  Button alberta;
  Button ontario;
  Button western_united_states;
  Button central_america;
   Button eastern_united_states;
  Button quebec;
  Button greenland;
  
  //South America
  Button venezuela;
   Button peru;
   Button brazil;
  Button argentina;
  
  //Europe
  Button iceland;
  Button great_britain;
  Button scandinavia;
  Button northern_europe;
  Button southern_europe;  
  Button western_europe;
  Button ukraine;
    
  //Africa
  Button north_africa;
  Button egypt;
  Button congo;
  Button east_africa;
  Button south_africa;  
  Button madagascar;
  
  //Asia
  Button ural;
  Button siberia;
  Button yakutsk;
  Button kamchatka;
  Button irkutsk;
  Button mongolia;
  Button japan;
  Button afghanistan;
  Button middle_east;
  Button india;
  Button china;
  Button siam;

  //Australia
  Button indonesia;
  Button new_guinea;
  Button western_australia;
  Button eastern_australia;

  
  Image img;

 public:
  
  Game_UI();
  void crossreference(Game_Engine*);

  void init_menu();
  void init_game();

  void update_menu_ui();
  void update_game_ui(); 

  std::string get_button_menu();
  std::string get_button_game();

  std::string* get_argument(std::string);

  void kill_menu();
  void kill_game();
  
}; 




#endif
