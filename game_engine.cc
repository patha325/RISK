
#include"game_engine.h"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
using namespace std;



Game_Engine::Game_Engine(vector<Player> init_players)
{
  players=init_players;
  reinforcements=0;
  current_player=players.begin();
  
  battle = new Battle(); //New Variable
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

  cardmap.find(card1->r_type())->second()++;
  cardmap.find(card2->r_type())->second()++;
  cardmap.find(card3->r_type())->second()++;

  inf = cardmap.find("inf").find->second();
  cav = cardmap.find("cav").find->second();
  art = cardmap.find("art").find->second();
  jok = cardmap.find("jok").find->second();

  if (inf == 3 || (inf == 2 && jok == 1))
    r_value = 4;
  if (cav == 3 || (cav == 2 && jok == 1)) 
    r_value = 6;
  if (art == 3 || (art == 2 && jok == 1)) 
    r_value = 8;
  if ((inf == 1 && cav == 1 && art == 1) || jok >= 1) 
    r_value = 10;

  if (r_value == 0)
    throw risk_error("Invalid card combination");

  finish_card(card1);
  finish_card(card2);
  finish_card(card3);

  return r_value;
}

void Game_Engine::finish_card(Card* card)
{
  world_map->get_territory(card->get_terr())->add_armies(current_player->get_colour(), 2);
  current_player->discard_card(card);
  world_map->push_card(card);
}

void Game_Engine::next_player()
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
  // Use Cards

  while(true)
    {
      cout << "Type which cards you wish to use, or type 'pass'." << endl;
      try {
	cin >> arg;
	if (arg == "pass")
	  {
	    cout << "No cards were used this turn." << endl;
	    break;
	  }
	Card* card1 = current_player->get_card(stoi(arg));
	cin >> arg;
	Card* card2 = current_player->get_card(stoi(arg));
	cin >> arg;
	Card* card3 = current_player->get_card(stoi(arg));

	reinforcements = use_cards(card1, card2, card3);
      }
      catch(const risk_error& e) {
	cout << e.what() << endl;
      }
    }


  // Place reinforcements


  reinforcements += world_map->get_reinforcements(current_player->get_colour()); //unclear syntax

  while (reinforcements > 0)
    {
      cout << "Select reinforcement location" << endl;
      cin >> arg;

      try {
	world_map->get_territory(arg)->add_armies(current_player->get_colour());
	reinforcement--;
      }
      catch(const risk_error& e) {
	cout << e.what() << endl;
      }
    }

  cout << "You now have no more troops to place." << endl;

  // Attack
  while (cin >> arg && arg != "end")
    {
      cout << "Type in 'attacking from' 'attacking to' 'number of attackers' or 'end' if you wish to begin troop redeployment." << endl;

      string destination;
      cin >> destination;

      try {
	battle.new_battle(world_map->get_territory(arg), world_map->get_territory(destination), current_player->get_colour());
	
	while (true)
	  {
	    cout << "Press 'a n' to attack with n troops or 'r' to retreat." << endl;

	    cin >> arg;
	    if (arg == "r")
	      break;

	    cin >> arg;
	    int i = stoi(arg);
	   	   
	    attackers = battle.attack(i);
	    if (i == 2)
	      {
		extra_card = true;
		break;
	      }
	    if (i == 0)
	      break;
	    
	  } //Do we need to clear the battle object after a battle is finished?

      }
      catch(const risk_error& e) {
	cout << e.what() << endl;
      }

    } // end of while
 
    cout << "You can now move troops from one friendly area to another connected friendly area." << endl;

  //troop movement

  while(true){
    cout << "Type 'redeploying from' 'redeploying to' 'number of troops' or 'pass' to pass." << endl;
    try{
      cin >> arg;
      if (arg == "pass")
	break;

      string destination;
      cin >> destination;

      cin >> arg;
      int troops = stoi(arg);
    
      world_map->get_territory(arg)->move_troops(troops);
      cout << "You successfully moved " + troops + " from " + arg + " to " + destination "." << endl;
    }
    catch(const risk_error& e) {
      cout << e.what() << endl;
    }    
  }

  // give out cards if you successfully conquered a territory this turn

  extra_card = false;
  cout << "Your turn ended." << endl;
  next_player();
}