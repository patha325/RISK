#include "game_ui.h"
#include"game_engine.h"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include <algorithm>
using namespace std;



Game_Engine::Game_Engine(vector<Player> init_players)
{
  players=init_players;
  random_shuffle(players.begin(), players.end());
  
  reinforcements=0;
  current_player=players.begin();
  
  battle = Battle(); //New Variable
  
  world_map = Worldmap(players);
}

string Game_Engine::get_owner(string terr_name)
{

  string strTest = "player" + world_map.get_territory(terr_name)->get_owner() + ".png";

  return strTest;
}

string Game_Engine::get_armies(string terr_name)
{
  stringstream sstr;
  sstr << world_map.get_territory(terr_name)->get_armies();
  string str = sstr.str();
 
  return str;
}

string Game_Engine::get_reinforcements()
{
  stringstream sstr;
  sstr << reinforcements;
  string str = sstr.str();
  
  return str;
}

void Game_Engine::crossreference(Game_UI* init_ui)
{
  ui = init_ui;
}

// control the cards, throw error if invalid combination. Return cards to world_map / delete cards in player if successful.
int Game_Engine::use_cards(Card* card1, Card* card2, Card* card3)
{
  int inf = 0;
  int cav = 0;
  int art = 0;
  int jok = 0;

  int r_value = 0;

  map<string,int> cardmap;

  cardmap["inf"] = 0;
  cardmap["cav"] = 0;
  cardmap["art"] = 0;
  cardmap["jok"] = 0;

  ++cardmap[card1->get_type()];
  ++cardmap[card2->get_type()];
  ++cardmap[card3->get_type()];

  inf = cardmap["inf"];
  cav = cardmap["cav"];
  art = cardmap["art"];
  jok = cardmap["jok"];

  cout << "You tried to play " << inf << " infantry, " << cav << " cavalry and " << art << " artillery." << endl;

  if (inf == 3 || (inf == 2 && jok == 1))
    r_value = 4;
  if (cav == 3 || (cav == 2 && jok == 1)) 
    r_value = 6;
  if (art == 3 || (art == 2 && jok == 1)) 
    r_value = 8;
  if ((inf == 1 && cav == 1 && art == 1) || jok >= 1) 
    r_value = 10;

  if (r_value == 0)
    throw risk_error("Invalid card combination");                     // SKA VARA GRAFISKT
  else 
    cout << "You recieve " << r_value << " extra troops!" << endl;
  finish_card(card1);
  finish_card(card2);
  finish_card(card3);
  
  return r_value;                     // SKA VARA GRAFISKT
}

void Game_Engine::finish_card(Card* card)
{
  try {
    Territory* card_terr = world_map.get_territory(card->get_terr());

    if (card->get_terr() != "joker")
      card_terr->add_armies(current_player->get_color(), 2);
    
    
    card_terr->add_armies(current_player->get_color(), 2);
    current_player->discard_card(card);
    world_map.push_card(card);
  }
  catch(const risk_error& e){}
}

void Game_Engine::next_player()// SKA VARA GRAFISKT
{
  if(++current_player == players.end())
    current_player = players.begin();
}

int Game_Engine::stoi(string s)
{
  int i;
  stringstream(s) >> i;
  return i;
}

void Game_Engine::run()
{
  while(true)
    {
      // Players turn
      cout<<endl;
      cout << "It is now " + current_player->get_name() +"s turn." <<endl;// SKA VARA GRAFISKT
      cout << "You are color: " + current_player->get_color() <<endl; // PATRIK

      // Print available cards?

      cout << "You have the following cards: " <<endl;

      current_player->print_cards();

      // Use Cards
      if (current_player->n_cards() >= 3)
	{
	  while(true)
	    {
	      cout << "Type which cards you wish to use, or type 'pass'." << endl;// SKA VARA GRAFISKT
	      try {
		cin >> arg;                            // SKA VARA GRAFISKT
		if (arg == "pass")                                // SKA VARA GRAFISKT
		  {
		    cout << "No cards were used this turn." << endl;// SKA VARA GRAFISKT
		    break;
		  }
		Card* card1 = current_player->get_card(stoi(arg));
		cin >> arg;                              // SKA VARA GRAFISKT
		Card* card2 = current_player->get_card(stoi(arg));
		cin >> arg;                                       // SKA VARA GRAFISKT
		Card* card3 = current_player->get_card(stoi(arg));
		// SKA VARA GRAFISKT
		reinforcements = use_cards(card1, card2, card3);
		break;
	      }
	      catch(const risk_error& e) {
		cout << e.what() << endl;                               // SKA VARA GRAFISKT
	      }
	    }
	}
      else 
	cout << "You don't have enough cards to combine." << endl;
	    
      // Place reinforcements

      reinforcements  += world_map.get_reinforcements(current_player->get_color()); 
      ui->update_game_ui();

      cout << "You recieve " << reinforcements << " troops to place. Click on the territory you wish to reinforce." << endl;
      while (reinforcements > 0)                               
	{
	  string territory;
	  territory = ui->get_argument("reinforcement")[0];
	  try {
	    world_map.get_territory(territory)->add_armies(current_player->get_color());      
	    reinforcements --;
	    ui->update_game_ui();
	  }
	  catch(const risk_error& e) {
	    cout << e.what() << endl;                               // SKA VARA GRAFISKT
	  }
	}

      cout << "You now have no more troops to place." << endl;                               // SKA VARA GRAFISKT
ui->update_game_ui();
      // Attack
      while (true)
	{
	  cout << "Left-click to choose attacker, right-click defender." << endl;                   // SKA VARA GRAFISKT

	  
	
	  string* r_pair = ui->get_argument("attack");
	  string destination;
	  
	  if (r_pair[0] == "end")
	    break;

	  arg = r_pair[0];
	  destination = r_pair[1];
	  
	  try {
	    battle.new_battle(world_map.get_territory(arg), world_map.get_territory(destination), current_player->get_color());         // SKA VARA GRAFISKT
	    ui->update_game_ui();
	    cout << arg +" is attacking " +destination <<endl;
	    while (true)
	      {
		int attackers=0;
		int result=1;
		while(true)
		  {

		    try{
		      cout << "Choose number of troops." << endl;      
                  
		      arg = ui->get_argument("attack")[0];
		      if (arg == "end")
			{
			  cout << "Chickenshit." << endl;
			  break;
			}	 
		
		      attackers=stoi(arg);
		      result=battle.attack(attackers);
		      ui->update_game_ui();
		      break; 	   
		    }
		    catch(const risk_error& e)
		      {
			cout << e.what() << endl;
		      }		  
		  }
		if(arg == "end")
		  break;
		if (result == 2)
		  {
		    while(true)
		      {
			                         
			ui->update_game_ui();
			try{
			  cout << "Defender lost."<<endl; 
			  cout << "How many troops do you wish to transfer to your new territory?" << endl;
			  arg = ui->get_argument("attack")[0];
			  int settlers=stoi(arg);
			  string color = world_map.get_territory(destination)->get_owner();
			  battle.conquer(attackers,settlers);
			  ui->update_game_ui();
			  cout << "You succesfully conquered " + destination + " from player " + color  +"."<<endl;
			  extra_card = true;
			  break;
			}
			catch(const risk_error& e){
			  cout << e.what() << endl;
			}
		      }
		    break;
		  }
		if (result == 0){
		  cout<< "Could not keep attacking."<<endl;                                // SKA VARA GRAFISKT
		  break;
		}
	      } //Do we need to clear the battle object after a battle is finished?
	  }
	  catch(const risk_error& e) {
	    cout << e.what() << endl;                               // SKA VARA GRAFISKT
	  }

	} // end of while
 
      cout << "You can now move troops from one friendly area to another connected friendly area." << endl;                               // SKA VARA GRAFISKT
      ui->update_game_ui();
      //troop movement

      while(true){
	cout << "Click 'redeploying from' 'redeploying to'." << endl;                               // SKA VARA GRAFISKT
	try{
	  string* r_pair = ui->get_argument("movement");
	  
	  if (r_pair[0] == "end")
	    break;

	  string destination;
	  arg = r_pair[0];
	  destination = r_pair[1];

	  cout << arg << " to " << destination << endl;

	  cout << "Choose the number of troops" <<endl;

	  string troops_s =  ui->get_argument("movement")[0];
	  int troops = stoi(troops_s);
    
	  world_map.move_armies(world_map.get_territory(arg),world_map.get_territory(destination),troops);           // SKA VARA GRAFISKT
	  cout << "You successfully moved "<< troops<< " from "+ arg + " to "+ destination + "." << endl;             // SKA VARA GRAFISKT
	  break;
	}
	catch(const risk_error& e) {
	  cout << e.what() << endl;                               // SKA VARA GRAFISKT
	}    
      }
      ui->update_game_ui();

      // give out cards if you successfully conquered a territory this turn

      if (current_player->n_cards() < 5 && extra_card)
	{
	  Card* t_card = world_map.pop_card();
	  cout << "You got a new card: " << t_card->get_type() << " " << t_card->get_terr() << endl;
	  current_player->give_card(t_card);
	}

      extra_card = false;

      cout << "Your turn ended." << endl;                               // SKA VARA GRAFISKT
      if( world_map.game_over(current_player->get_color()))
	{ cout << "YOU WON" <<endl;
	  // VICTORY TEXT


	  break;
	}
  
      next_player();

      if (world_map.is_dead(current_player->get_color()))
	{
	  cout << current_player->get_name() << " is eliminated from the game!" << endl;
	  current_player = players.erase(current_player);
	  if (current_player == players.end())
	    current_player = players.begin();
	}
    } //a break; ends the game.
}

