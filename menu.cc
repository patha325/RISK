

#include "SDL.h"
//#include "SDL_image.h"
#include "ui_elements.h"
//#include "SDL_TTF.h"

using namespace std;

int main() {

  //Settingsf
  SDL_Surface* screen = NULL;
  int scrh = 768;
  int scrw = 1024;
  int bitdepth = 32;
  int activate_gameengine = false;
  bool screen_active = true;
  SDL_Event event;
  
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

  player1TF.fetch_data();

  //Player2
  int tfy2 = (450); //playernumberfunction

  Textfield player2TF (tfx, tfy2, tfw);
  player2TF.show(screen);

  player2TF.fetch_data();

  //Player3
  int tfy3 = (500); //playernumberfunction

  Textfield player3TF (tfx, tfy3, tfw);
  player3TF.show(screen);
 
 player3TF.fetch_data();

  //Player4
  int tfy4 = (550); //playernumberfunction

  Textfield player4TF (tfx, tfy4, tfw);
  player4TF.show(screen);
 
 player4TF.fetch_data();


  //*/
  ////////////////

///////Adding the "Start" button:////////
  ///*

  int buttonw = 200;
  int buttonh = 75;
  int buttonx = (scrw/2)-(buttonw/2);
  int buttony = (scrh-100);

  Button start (buttonx, buttony, buttonw, buttonh);
  start.show(screen);


  //*/
  ////////////////

  SDL_Flip( screen );

  ///////Quit?////////
  
  while (screen_active)
  {

    if (start.handle_events() == 3)
      {
	screen_active = false;
      }
    
    /*
    if ( SDL_PollEvent(&event))
      {
	if (event.type == SDL_QUIT)
	  {
	    screen_active = false;
	    
	  }
      }
      */

  }

  SDL_Quit();

////////////////END OF MENU///////////////////////


  //activate_gameengine = true;

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
      
      SDL_Flip( screen );
      
      ///////Quit?////////
      SDL_Event event;
      bool screen_active = true;
      while (screen_active)
	{
	  if (SDL_PollEvent(&event))
	    {
	      if (event.type == SDL_QUIT)
		{
		  screen_active = false;
		  
		}
	    }
	}
      
      SDL_Quit(); 
    }


//////////////////////////////////////

  
  return 0; 
}



