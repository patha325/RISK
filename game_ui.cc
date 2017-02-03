#include "SDL.h"
#include "SDL_ttf.h"
#include "label.h"
#include "Button.h"
#include "Image.h"
#include "Clickable.h"
#include <iostream>
#include "game_engine.h"
#include "game_ui.h"
#include <string>
#include <sstream>


using namespace std;

Game_UI::Game_UI()
{
  //Settings
  screen = NULL;
  mscrh = 768;
  mscrw = 1024;
  scrh = 952;
  scrw = 1604;
  bitdepth = 32;
  activate_gameengine = false;
  screen_active = false;
}

void Game_UI::crossreference(Game_Engine* game_init)
{
  game = game_init;
}

 void Game_UI::init_menu() 
{ 
  ////////SDL UI setup////////
  SDL_Init( SDL_INIT_EVERYTHING );
  TTF_Init();

  ///Window:
  SDL_WM_SetCaption("Risk, med en fisk.... :)", NULL); 
  screen = SDL_SetVideoMode( mscrw, mscrh, bitdepth, SDL_SWSURFACE );
  
  ////////Adding the graphical elements:////////
  
  ///Screen:
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );


  menubg.set_image(0,0,mscrw,mscrh);
  start.set_button(((mscrw/2)-200), 550, 400, 150);

}

void Game_UI::update_menu_ui()
{
  ///BG-image:
  menubg.show(screen,"backg.bmp");
  ///Start-button:  
  start.show(screen, "start.bmp");

  SDL_Flip( screen );

}



string Game_UI::get_button_menu()
{
  while(true)
    {
      if (SDL_PollEvent(&event))
	{
      
	  if (event.type == SDL_QUIT)
	    kill_game();
	    
	  else if (event.type == SDL_MOUSEBUTTONUP)
	    {
	      int x = event.button.x;
	      int y = event.button.y;
	  
	      if (start.hit (x, y) == true)
		return "start";		
	    }
	}
    }
  return "";
}

void Game_UI::kill_menu()
{
  ///Menu clean-up:
  //TTF_CloseFont( font );
  TTF_Quit();
  SDL_Quit();
}


void Game_UI::init_game() 
{
  ////////SDL UI setup////////
  SDL_Init( SDL_INIT_EVERYTHING );
  TTF_Init();
  SDL_WM_SetCaption("RISK", NULL);
  screen = SDL_SetVideoMode( scrw, scrh, bitdepth, SDL_SWSURFACE );
  ///Screen:
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x77, 0x00 ) );


  counter = 3;
     

  //INITIATE BUTTONS
  
  counter_lbl.set_label(1140,860,"data-latin.ttf",20,4);


  end.set_button(1486,850,80,80);
  up.set_button(1040,850,80,80);
  down.set_button(1396,850,80,80);
  energize.set_button(1130,850,256,80);
  
  alaska.set_button(90,77, 30, 30);
  northwest_territory.set_button(180,106, 30,30);
  alberta.set_button(187,262, 30, 30);
  ontario.set_button(247,202, 30, 30);
  
  western_united_states.set_button(100,300, 30, 30);
  central_america.set_button(162,477, 30, 30);
  eastern_united_states.set_button(271,421, 30, 30);
  quebec.set_button(334,280, 30, 30);
  
  greenland.set_button(456,168, 30, 30);
  
  venezuela.set_button(429,567, 30, 30);
  peru.set_button(360,699, 30, 30);
  brazil.set_button(519, 711, 30, 30);
  argentina.set_button(444,822, 30, 30);
  
 

  iceland.set_button(649,199, 30, 30);
  great_britain.set_button(729,205, 30, 30);
  scandinavia.set_button(843,130, 30, 30);
  northern_europe.set_button(855,292, 30, 30);
  southern_europe.set_button(864,364, 30, 30);
  western_europe.set_button(678,342, 30, 30);
  ukraine.set_button(963, 181, 30, 30);
  north_africa.set_button(702, 531, 30, 30);
  egypt.set_button(918, 516, 30, 30);
  congo.set_button(846, 576, 30, 30);
  east_africa.set_button(975,627, 30, 30);
  south_africa.set_button(886, 747, 30, 30);
  madagascar.set_button(1030,727, 30, 30);
  ural.set_button(1075,109, 30, 30);
  siberia.set_button(1170,79, 30, 30);
  yakutsk.set_button(1311,48, 30, 30);
  kamchatka.set_button(1429,39, 30, 30);
  irkutsk.set_button(1261, 219, 30, 30);
  mongolia.set_button(1336,310, 30, 30);
  japan.set_button(1441,306, 30, 30);
  afghanistan.set_button(1059,331, 30, 30);
  middle_east.set_button(1015,457, 30, 30);
  india.set_button(1137,454, 30, 30);   
  china.set_button(1260,367, 30, 30);
  siam.set_button(1257,471, 30, 30);
  indonesia.set_button(1293,600, 30, 30);
  new_guinea.set_button(1479,603, 30, 30);
  western_australia.set_button(1387,660, 30, 30);
  eastern_australia.set_button(1465,738, 30, 30);

  

  img.set_image(0, 0, scrw, scrh);
  img.show(screen, "risk_map.png");
}

void Game_UI::update_game_ui()
{

  end.show(screen, "end.png");
  up.show(screen, "plus.png");
  down.show(screen, "minus.png");   
  energize.show(screen, "army.png");


  string str1 = "Armies: " + game->get_reinforcements();
  const char* counter_text = str1.c_str();

  
  if (game->get_reinforcements() == "0")
     {
       stringstream sstr;
      sstr << counter;
      string str = "Armies: " + sstr.str();
         counter_text = str.c_str();
        }
  
  counter_lbl.show(screen, counter_text);

  
  //North America
  alaska.b_show(screen, game->get_owner("alaska"), game->get_armies("alaska"));
 
  northwest_territory.b_show(screen, game->get_owner("northwest_territory"), game->get_armies("northwest_territory"));

  alberta.b_show(screen, game->get_owner("alberta"), game->get_armies("alberta"));
  
  ontario.b_show(screen, game->get_owner("ontario"), game->get_armies("ontario"));

  

  western_united_states.b_show(screen, game->get_owner("western_united_states"), game->get_armies("western_united_states"));

  central_america.b_show(screen, game->get_owner("central_america"), game->get_armies("central_america"));
  
  eastern_united_states.b_show(screen, game->get_owner("eastern_united_states"), game->get_armies("eastern_united_states"));

  quebec.b_show(screen, game->get_owner("quebec"), game->get_armies("quebec"));

  greenland.b_show(screen, game->get_owner("greenland"), game->get_armies("greenland"));
  
 
  //South America


  venezuela.b_show(screen, game->get_owner("venezuela"), game->get_armies("venezuela"));

   peru.b_show(screen, game->get_owner("peru"), game->get_armies("peru"));

  brazil.b_show(screen, game->get_owner("brazil"), game->get_armies("brazil"));
     
  argentina.b_show(screen, game->get_owner("argentina"), game->get_armies("argentina"));
     
  
  //Europe

  iceland.b_show(screen, game->get_owner("iceland"), game->get_armies("iceland"));

  great_britain.b_show(screen, game->get_owner("great_britain"), game->get_armies("great_britain"));

  scandinavia.b_show(screen, game->get_owner("scandinavia"), game->get_armies("scandinavia"));

  northern_europe.b_show(screen, game->get_owner("northern_europe"), game->get_armies("northern_europe"));

  southern_europe.b_show(screen, game->get_owner("southern_europe"), game->get_armies("southern_europe"));

  western_europe.b_show(screen, game->get_owner("western_europe"), game->get_armies("western_europe"));

  ukraine.b_show(screen, game->get_owner("ukraine"), game->get_armies("ukraine"));


  //Africa

  north_africa.b_show(screen, game->get_owner("north_africa"), game->get_armies("north_africa"));
     
  egypt.b_show(screen, game->get_owner("egypt"), game->get_armies("egypt"));
     
  congo.b_show(screen, game->get_owner("congo"), game->get_armies("congo"));
     
  east_africa.b_show(screen, game->get_owner("east_africa"), game->get_armies("east_africa"));
     
  south_africa.b_show(screen, game->get_owner("south_africa"), game->get_armies("south_africa"));
     
  madagascar.b_show(screen, game->get_owner("madagascar"), game->get_armies("madagascar"));
     


  //Asia

  ural.b_show(screen, game->get_owner("ural"), game->get_armies("ural"));
   
  siberia.b_show(screen, game->get_owner("siberia"), game->get_armies("siberia"));

  yakutsk.b_show(screen, game->get_owner("yakutsk"), game->get_armies("yakutsk"));

  kamchatka.b_show(screen, game->get_owner("kamchatka"), game->get_armies("kamchatka"));

  irkutsk.b_show(screen, game->get_owner("irkutsk"), game->get_armies("irkutsk"));
   
  mongolia.b_show(screen, game->get_owner("mongolia"), game->get_armies("mongolia"));

  japan.b_show(screen, game->get_owner("japan"), game->get_armies("japan"));
 
  afghanistan.b_show(screen, game->get_owner("afghanistan"), game->get_armies("afghanistan"));

  middle_east.b_show(screen, game->get_owner("middle_east"), game->get_armies("middle_east"));
   
  india.b_show(screen, game->get_owner("india"), game->get_armies("india"));

  china.b_show(screen, game->get_owner("china"), game->get_armies("china"));
   
  siam.b_show(screen, game->get_owner("siam"), game->get_armies("siam"));
     
 
  //Australia

  indonesia.b_show(screen, game->get_owner("indonesia"), game->get_armies("indonesia"));

  western_australia.b_show(screen, game->get_owner("western_australia"), game->get_armies("western_australia"));

  eastern_australia.b_show(screen, game->get_owner("eastern_australia"), game->get_armies("eastern_australia"));
 
  new_guinea.b_show(screen, game->get_owner("new_guinea"), game->get_armies("new_guinea"));
  
  SDL_Flip( screen );
}
      
string Game_UI::get_button_game()
{
  while(true) 
    {
      if (SDL_PollEvent(&event))
	{   
	  if (event.type == SDL_QUIT)
	    kill_game();
	  else if (event.type == SDL_MOUSEBUTTONUP)
	    {
	      
	      int x = event.button.x;
	      int y = event.button.y;

	      if (end.hit (x, y))
		return "end";	

	      if (up.hit (x, y))
		{
		  counter++;
		  update_game_ui();
		}
	      if (down.hit (x, y) && counter > 1)
		{
		  counter--;
		  update_game_ui();
		}
	      if (energize.hit (x, y))
		{
		  stringstream sstr1;
		  sstr1 << counter;
		  string str1 = sstr1.str();
		  return str1;
		}

	     
	      if (alaska.hit(x,y))
		      return "alaska";
		 if (northwest_territory.hit(x,y))
		      return "northwest_territory";
		 if (ontario.hit(x,y))
		      return "ontario";
		 if(alberta.hit(x,y))
		      return "alberta";
		 if (western_united_states.hit(x,y))
		      return "western_united_states";
		 if (central_america.hit(x,y))
		      return "central_america";
		 if (eastern_united_states.hit(x,y))
		      return "eastern_united_states";
		 if(quebec.hit(x,y))
		      return "quebec";
		 if (greenland.hit(x,y))
		      return "greenland";
		 if (venezuela.hit(x,y))
		      return "venezuela";
		 if (peru.hit(x,y))
		      return "peru";
		 if(brazil.hit(x,y))
		      return "brazil";
		 if (argentina.hit(x,y))
		      return "argentina";
		 if (iceland.hit(x,y))
		      return "iceland";
		 if (great_britain.hit(x,y))
		      return "great_britain";
		 if(scandinavia.hit(x,y))
		      return "scandinavia";
		 if (northern_europe.hit(x,y))
		      return "northern_europe";
		 if (southern_europe.hit(x,y))
		      return "southern_europe";
		 if (western_europe.hit(x,y))
		      return "western_europe";
		 if(ukraine.hit(x,y))
		      return "ukraine";
		 if (north_africa.hit(x,y))
		      return "north_africa";
		 if (egypt.hit(x,y))
		      return "egypt";
		 if (congo.hit(x,y))
		      return "congo";
		 if(east_africa.hit(x,y))
		      return "east_africa";
		 if (south_africa.hit(x,y))
		      return "south_africa";
		 if (madagascar.hit(x,y))
		      return "madagascar";
		 if (ural.hit(x,y))
		      return "ural";
		 if(siberia.hit(x,y))
		      return "siberia";
		 if (yakutsk.hit(x,y))
		      return "yakutsk";
		 if (kamchatka.hit(x,y))
		      return "kamchatka";
		 if (irkutsk.hit(x,y))
		      return "irkutsk";
		 if(mongolia.hit(x,y))
		      return "mongolia";
		 if (japan.hit(x,y))
		      return "japan";
		 if (afghanistan.hit(x,y))
		      return "afghanistan";
		 if (middle_east.hit(x,y))
		      return "middle_east";
		 if(india.hit(x,y))
		      return "india";
		 if (china.hit(x,y))
		      return "china";
		 if(siam.hit(x,y))
		      return "siam";
		 if (indonesia.hit(x,y))
		      return "indonesia";
		 if (new_guinea.hit(x,y))
		      return "new_guinea";
		 if (western_australia.hit(x,y))
		      return "western_australia";
		 if(eastern_australia.hit(x,y))
		      return "eastern_australia";

	      
		
	    }
	}
    }
}

string* Game_UI::get_argument(string phase)
{
  string* r_string = new string[2];
  
  while(true)
    {
      string arg = get_button_game();
      
      if (arg == "end")
	{
	  r_string[0] = arg;
	  return r_string;
	}

      stringstream sstr1;
      sstr1 << counter;
      string str1 = sstr1.str();
      if (arg == str1)
	{
	  r_string[0]=arg;
	  return r_string;
	}
      if (event.button.button == SDL_BUTTON_LEFT )
	r_string[0] = arg;
      if (event.button.button == SDL_BUTTON_RIGHT && r_string[0] != "")
	r_string [1] = arg;

      if (phase == "reinforcement" && r_string[0] != "")
	return r_string;

      if ((phase == "attack" || phase == "movement") && r_string[0] != "" && r_string[1] != "")
	return r_string;
    }
}

void Game_UI::kill_game()
{     
  ///Game Menu clean-up:
  //TTF_CloseFont( font );
  TTF_Quit();
  SDL_Quit();
  exit(1);

}

