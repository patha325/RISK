

#include "SDL.h"
#include <iostream>
using namespace std;

int main() {

  //Settingsf
  SDL_Surface* screen = NULL;
  int scrh = 768;
  int scrw = 1024;
  int bitdepth = 32;
  int activate_gameengine = false;
  bool screen_active = true;
  //SDL_Event event;
  
  ////////SDL UI setup////////

  SDL_Init( SDL_INIT_EVERYTHING );
  
  SDL_WM_SetCaption("Risk, med en fisk.... :)", NULL); 
  
  screen = SDL_SetVideoMode( scrw, scrh, bitdepth, SDL_SWSURFACE );

  ////////Adding the graphical elements:////////

  ///Screen color 00:00:00
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

  ///////Adding the background image:////////
  ///*
  
  Image backgroundimage (0,0,scrw,scrh);
  backgroundimage.show(screen , "backg.bmp");

  //*/
  ////////////////
  
  

  ///////Adding the player name textfields:////////
  ///*


  int tfw = 300;
  int tfx = (scrw/2)-(tfw/2);

  //Player1
  int tfy1 = (400); //playernumberfunction

  Textfield player1TF (tfx, tfy1, tfw);
  player1TF.show(screen);


  ///player add-Button:///

  Button add (((scrw / 2) - 15) ,(tfy1 + 50), 30, 30);
  add.show(screen);
  
  Image addimage (((scrw / 2) - 15) ,(tfy1 + 50), 30, 30);
  addimage.show(screen , "add.bmp");
 
  ////////////////

///////Adding the "Start" button:////////
  ///*

  int buttonw = 200;
  int buttonh = 75;
  int buttonx = (scrw/2)-(buttonw/2);
  int buttony = (scrh-100);

  Button start (buttonx, buttony, buttonw, buttonh);
  start.show(screen);

  Image startimage (buttonx, buttony, buttonw, buttonh);
  startimage.show(screen , "start.bmp");


  SDL_Flip( screen );

  ///////Quit?////////
  

  /// Program loop: ///
  while (screen_active)
  {

    if (start.handle_events() == 3 || start.handle_events() == 4)
      {
	screen_active = false;
	activate_gameengine = true;
      }
    
    if (player1TF.active_TF() == true)
      {
	player1TF.show_indic(screen);
	SDL_Flip( screen );
	cout << "textfieldinput" << endl;
	//player1TF.fetch_data();
	SDL_Delay(2000);  // temporary
	player1TF.hide_indic(screen);
	SDL_Flip( screen );
      }
    
    if (add.handle_events() == 3)
      {
	//int tfw = 300;
	//int tfx = (scrw/2)-(tfw/2);
	
	//Next Player TF
	int tfy2 = tfy1 + 50;
	
	Textfield player2TF (tfx, tfy2, tfw);
	player2TF.show(screen);
	
	
	///Player add-Button:///
	
	Button add2 (((scrw / 2) - 15) ,(tfy2 + 50) ,30 ,30);
	add2.show(screen);
	
	Image addimage2 (((scrw / 2) - 15) ,(tfy2 + 50) ,30 ,30);
	addimage2.show(screen , "add.bmp");
	SDL_Flip( screen );
      }
    
  }

  SDL_Quit();

////////////////END OF MENU///////////////////////

////////////////GAME_UI/////////////////


if (activate_gameengine == true)
    {

      SDL_Surface* screen = NULL;

      ////////SDL UI setup////////
      
      SDL_Init( SDL_INIT_EVERYTHING );
      
      SDL_WM_SetCaption("Risk... , med en fisk?", NULL); 
      
      screen = SDL_SetVideoMode( scrw, scrh, bitdepth, SDL_SWSURFACE );
      
      ////////Adding the graphical elements:////////
      
      ///Screen color 00:00:00
      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x77, 0x00 ) );

      ///////Adding the background image:////////
      ///*
      
      Image backgroundimage (0,0,scrw,scrh);
      backgroundimage.show(screen , "backg.bmp");
      
      //*/
      ////////////////
      
      
      SDL_Flip( screen );
      
      ///////Quit?////////
      //SDL_Event event;
      bool screen_active = true;
      while (screen_active)
	{
	  if (start.handle_events() == 4)
	    {
	      screen_active = false;
	    }
	  
	  
	}
      
      SDL_Quit(); 
    }


//////////////////////////////////////

  
  return 0; 
}



