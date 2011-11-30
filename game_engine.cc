
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
  
  battle = Battle(); //New Variable
  world_map = Worldmap();
  
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

  ++cardmap["inf"];
  ++cardmap["cav"];
  ++cardmap["art"];
  ++cardmap["jok"];

  inf = cardmap["inf"];
  cav = cardmap["cav"];
  art = cardmap["art"];
  jok = cardmap["jok"];

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

      // Print available cards?

      cout << "You have the following cards: " <<endl;
      // for(int i=0 : i<
      int i =0;
      Card* current_card = current_player->get_card(0); // PATRIK
      cout << "Number " <<i<< " Type: "+current_card->get_type() << " Territory: " +current_card->get_terr() <<endl; // PATRIK

  // Use Cards
  while(true)
    {
      cout << "Type which cards you wish to use, or type 'pass'." << endl;// SKA VARA GRAFISKT
      try {
	cin >> arg;                               // SKA VARA GRAFISKT
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
      }
      catch(const risk_error& e) {
	cout << e.what() << endl;                               // SKA VARA GRAFISKT
      }
    }


  // Place reinforcements


   reinforcements += world_map.get_reinforcements(current_player->get_color()); //unclear syntax

  while (reinforcements > 0)                               // SKA VARA GRAFISKT
    {
      cout << "You have " << reinforcements << " troops left to place. Select reinforcement location" << endl;                               // SKA VARA GRAFISKT
      cin >> arg;                               // SKA VARA GRAFISKT

      try {
	world_map.get_territory(arg)->add_armies(current_player->get_color());                               // SKA VARA GRAFISKT
	reinforcements--;
      }
      catch(const risk_error& e) {
	cout << e.what() << endl;                               // SKA VARA GRAFISKT
      }
    }

  cout << "You now have no more troops to place." << endl;                               // SKA VARA GRAFISKT

  // Attack
  while (true)
    {
      cout << "Type in 'attacking from' 'attacking to'  or 'end' if you wish to begin troop redeployment." << endl;                               // SKA VARA GRAFISKT

      cin >> arg;
      if (arg == "end")
	break;

      string destination;
      cin >> destination;

      try {
	battle.new_battle(world_map.get_territory(arg), world_map.get_territory(destination), current_player->get_color());                               // SKA VARA GRAFISKT
	
	while (true)
	  {
	    int attackers=0;
	    int result=1;
	    while(true)
	      {
		try{
		  cout << "Press 'a n' to attack with n troops or 'r' to retreat." << endl;                               // SKA VARA GRAFISKT

		  cin >> arg;                               // SKA VARA GRAFISKT
		  if (arg != "a")
		    {
		      cout << "Chickenshit." << endl;
		      break;
		      break;
		    }

		  cin >> arg;   // SKA VARA GRAFISKT
		  attackers=stoi(arg);
		  result=battle.attack(attackers);	  
		  break; 	   
		}
		catch(const risk_error& e)
		  {
		    cout << e.what() << endl;
		  }
		if (arg == "r")
		  break;
	      }

	    if (result == 2)
	      {
		while(true)
		  {
		    cout << "Defender lost."<<endl;                               // SKA VARA GRAFISKT
		    try{
		      cout << "How many troops do you wish to transfer to your new territory?" << endl;
		      cin >> arg;
		      int settlers;
		      settlers = stoi(arg);
		      battle.conquer(attackers,settlers);
		      cout << "You succesfully conquered " + destination + " from player " + world_map.get_territory(destination)->get_owner() +"."<<endl;
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

  //troop movement

  while(true){
    cout << "Type 'redeploying from' 'redeploying to' 'number of troops' or 'pass' to pass." << endl;                               // SKA VARA GRAFISKT
    try{
      cin >> arg;                               // SKA VARA GRAFISKT
      if (arg == "pass")
	break;

      string destination;
      cin >> destination;

      cin >> arg;
      int troops = stoi(arg);
    
      world_map.get_territory(arg)->move_armies(current_player->get_color(), world_map.get_territory(destination), troops);                               // SKA VARA GRAFISKT
      cout << "You successfully moved "<< troops<< " from "+ arg + " to "+ destination + "." << endl;                               // SKA VARA GRAFISKT
    }
    catch(const risk_error& e) {
      cout << e.what() << endl;                               // SKA VARA GRAFISKT
    }    
  }

  // give out cards if you successfully conquered a territory this turn

  extra_card = false;
  cout << "Your turn ended." << endl;                               // SKA VARA GRAFISKT
  next_player();
    } //a break; ends the game.
}

