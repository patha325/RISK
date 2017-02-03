#include "SDL.h"
#include "SDL_ttf.h"
//#include "ui_elements.h"
#include "label.h"
#include "Button.h"
#include "Image.h"
#include "Clickable.h"
#include <iostream>

using namespace std;

int main() {

  //Settings
  SDL_Surface* screen = NULL;
  int mscrh = 768;
  int mscrw = 1024;
  int scrh = 952;
  int scrw = 1604;
  int bitdepth = 32;
  int activate_gameengine = false;
  bool screen_active = true;
  SDL_Event event;
  
  ////////SDL UI setup////////
  
  SDL_Init( SDL_INIT_EVERYTHING );
  TTF_Init();

  ///Window:
  SDL_WM_SetCaption("Risk, med en fisk.... :)", NULL); 
  screen = SDL_SetVideoMode( mscrw, mscrh, bitdepth, SDL_SWSURFACE );
  
  ////////Adding the graphical elements:////////
  
  ///Screen:
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );

  ///BG-image:
  Image menubg (0,0,mscrw,mscrh, "backg.bmp");
  menubg.show(screen);
  
  /*

  ///Labels:
  Label texttest((scrw/2), 50);
  texttest.show(screen, "Risk", "data-latin.ttf" , 100 , 2);
  
  ///Textfields:  

  int tfw = 300; //TF-width
  int tfx = (scrw/2)-(tfw/2); //TF-xpos
  
  //Player1
  int tfy1 = (400);
  Textfield player1TF (tfx, tfy1, tfw);
  player1TF.show(screen);
  
  ///MODIFY///////////////////////////////////////////////////////////////////////////////////
  
  ///Buttons:
  
  ///Add-button:
  Button add (((scrw / 2) - 15) ,(tfy1 + 50), 30, 30);
  add.show(screen);
  Image addimage (((scrw / 2) - 15) ,(tfy1 + 50), 30, 30);
  addimage.show(screen , "add.bmp");
    
  ////////////////
  
  ///Start-button:
  int buttonw = 200;
  int buttonh = 75;
  int buttonx = (scrw/2)-(buttonw/2);
  int buttony = (scrh-100);
  Button start (buttonx, buttony, buttonw, buttonh);
  start.show(screen);
  Image startimage (buttonx, buttony, buttonw, buttonh);
  startimage.show(screen , "start.bmp");
  ///////////////////////////////////////////////////////////////////////////////////

  */  

  ///Start-button:
  Button Start(((mscrw/2)-200), 550, 400, 150, "start.bmp");
  Start.show(screen);

  SDL_Flip( screen );

  ////////Running Menu:///////////

  ///Program loop:

  while (screen_active)
    {
      
      if (SDL_PollEvent(&event))
	{
      
	  if (event.type == SDL_QUIT)
	    {
	      screen_active = false;
	      activate_gameengine = true;
	    }
	  
	  else if (event.type == SDL_MOUSEBUTTONUP)
	    {
		int x = event.button.x;
		int y = event.button.y;
		
		if (Start.hit (x, y) == true)
		  {
		    screen_active = false;
		    activate_gameengine = true;
		  }
	      }
	}
    }
  
  ///Menu clean-up:

  //TTF_CloseFont( font );
  TTF_Quit();
  SDL_Quit();
  
////////////////END OF MENU///////////////////////

////////////////GAME_UI/////////////////

////////Init Game UI:///////////
  if (activate_gameengine == true)
    {

      ////////SDL UI setup////////
      
      SDL_Init( SDL_INIT_EVERYTHING );
      
      SDL_WM_SetCaption("Risk... , med en fisk?", NULL); 
      
      screen = SDL_SetVideoMode( scrw, scrh, bitdepth, SDL_SWSURFACE );
      
      ////////Adding the graphical elements:////////
      
      ///Screen:
      SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x77, 0x00 ) );

      //worldmap
      Image img (0, 0, scrw, scrh, "risk_map.png");
      img.show(screen);
      
      
      //North America
      
      Button Alaska(90,77, 30, 30, "playerred.png");
      Alaska.show(screen);
      
      Button NWT(180,106, 30, 30, "playerred.png");
      NWT.show(screen);
      
      Button Alberta(187,262, 30, 30, "playerred.png");
      Alberta.show(screen);

      Button Ontario(247,202, 30, 30, "playerred.png");
      Ontario.show(screen);

      Button WUS(100,300, 30, 30, "playerred.png");
      WUS.show(screen);

      Button CAmerica(162,477, 30, 30, "playerred.png");
      CAmerica.show(screen);

      Button EUS(271,421, 30, 30, "playerred.png");
      EUS.show(screen);

      Button Quebec(334,280, 30, 30, "playerred.png");
      Quebec.show(screen);

      Button Greenland(456,168, 30, 30, "playerred.png");
      Greenland.show(screen);

      //South America
      Button Venezuela(429,567, 30, 30, "playerred.png");
      Venezuela.show(screen);

      Button Peru(360,699, 30, 30, "playerred.png");
      Peru.show(screen);

      Button Brazil(519, 711, 30, 30, "playerred.png");
      Brazil.show(screen);

      Button Argentina(444,822, 30, 30, "playerred.png");
      Argentina.show(screen);

      //Europe
      Button Iceland(649,199, 30, 30, "playerred.png");
      Iceland.show(screen);

      Button GB(729,205, 30, 30, "playerred.png");
      GB.show(screen);

      Button Scandinavia(843,130, 30, 30, "playerred.png");
      Scandinavia.show(screen);

      Button NE(855,292, 30, 30, "playerred.png");
      NE.show(screen);

      Button SE(864,364, 30, 30, "playerred.png");
      SE.show(screen);

      Button WE(678,342, 30, 30, "playerred.png");
      WE.show(screen);

      Button Ukraine(963, 181, 30, 30, "playerred.png");
      Ukraine.show(screen);

      //Africa
      Button NA(702, 531, 30, 30, "playerred.png");
      NA.show(screen);

      Button Egypt(918, 516, 30, 30, "playerred.png");
      Egypt.show(screen);

      Button Congo(846, 576, 30, 30, "playerred.png");
      Congo.show(screen);

      Button EA(975,627, 30, 30, "playerred.png");
      EA.show(screen);

      Button SA(886, 747, 30, 30, "playerred.png");
      SA.show(screen);

      Button Madagascar(1030,727, 30, 30, "playerred.png");
      Madagascar.show(screen);

      //Asia

      Button Ural(1075,109, 30, 30, "playerred.png");
      Ural.show(screen);

      Button Siberia(1170,79, 30, 30, "playerred.png");
      Siberia.show(screen);

      Button Yakutsk(1311,48, 30, 30, "playerred.png");
      Yakutsk.show(screen);

      Button Kamchatka(1429,39, 30, 30, "playerred.png");
      Kamchatka.show(screen);

      Button Irkutsk(1261, 219, 30, 30, "playerred.png");
      Irkutsk.show(screen);

      Button Mongolia(1336,310, 30, 30, "playerred.png");
      Mongolia.show(screen);

      Button Japan(1441,306, 30, 30, "playerred.png");
      Japan.show(screen);

      Button Afghanistan(1059,331, 30, 30, "playerred.png");
      Afghanistan.show(screen);

      Button MiddleEast(1015,457, 30, 30, "playerred.png");
      MiddleEast.show(screen);

      Button India(1137,454, 30, 30, "playerred.png");
      India.show(screen);

      Button China(1260,367, 30, 30, "playerred.png");
      China.show(screen);

      Button Siam(1257,471, 30, 30, "playerred.png");
      Siam.show(screen);

      //Australia


      Button Indonesia(1293,600, 30, 30, "playerred.png");
      Indonesia.show(screen);

      Button NewGuinea(1479,603, 30, 30, "playerblue.png");
      NewGuinea.show(screen);

      Button WAu(1387,660, 30, 30, "playergreen.png");
      WAu.show(screen);

      Button EAu(1465,738, 30, 30, "playeryellow.png");
      EAu.show(screen);
      
      ///////////////////////////////////////////////////////////////////////////      

      SDL_Flip( screen );
      
      ///////Quit?////////
      //SDL_Event event;
      bool screen_active = true;
      while (screen_active)
	{
	  if (SDL_PollEvent(&event))
	    {
	      
	      if (event.type == SDL_QUIT)
		{
		  screen_active = false;
		  activate_gameengine = true;
		}
	      
	    }
	}
      
      SDL_Quit(); 
    }

  return 0; 
}

////////////////END OF GAME_UI/////////////////

