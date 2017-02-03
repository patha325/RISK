
#include <vector>
#include <string>
#include "game_engine.h"
#include "game_ui.h"

using namespace std;

vector<Player> players;
vector<string> colors = {"red","blue","green","yellow"};
void new_player(string name, int np)
{

  Player temp = Player(name,colors[np]);
  players.push_back(temp);

}


int main()
{

  cout <<endl << "Welcome to RISK"<<endl;
  cout << "Imput the players name, end input with end." <<endl;
  cout << "There can only be between 2-4 players." <<endl;
  string name;
  int np =0;
  while (true)
    { 
      if (np == 4)
	break;
      cin >> name;
      if (name == "end")
	{
	  if(np < 2)
	    cout << "Input more players!" <<endl;
	  else break;
	}
      else
	{
	  new_player(name, np);
	  np ++;
	}
    }
 
  // CREATING THE GAME
  Game_Engine game =Game_Engine(players);
  Game_UI ui = Game_UI();

  Game_Engine* game_p =  &game;
  ui.crossreference(game_p);
  Game_UI* ui_p = &ui;
  game.crossreference(ui_p);
  
  ui.init_menu();
  ui.update_menu_ui();

  string arg = ui.get_button_menu();

  if (arg == "start")
    {
      ui.kill_menu();
            
      ui.init_game();
      ui.update_game_ui();
      /*
      while(true)
	{
	  string* arg = ui.get_argument("reinforcement");
	  cout << arg[0] << arg[1] << endl;

	  ui.update_game_ui();
	  
	}*/

      game.run();
    }
	
		

  return 0;
}
