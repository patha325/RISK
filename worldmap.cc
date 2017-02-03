//worldmap.cc
#include "worldmap.h"

#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>


using namespace std;

Worldmap::Worldmap(){}

Worldmap::Worldmap(vector<Player> init_players)
{
 
//AUSTRALIA
  Territory* western_australia = new Territory("western_australia", vector<string> { "eastern_australia","indonesia"  ,"new_guinea"} );
  Territory*  eastern_australia = new Territory("eastern_australia", vector<string> { "western_australia", "new_guinea"});
  Territory*  new_guinea = new Territory("new_guinea", vector<string> { "western_australia", "eastern_australia", "indonesia"});
  Territory* indonesia = new Territory("indonesia", vector<string> { "siam", "western_australia", "new_guinea"});

  australia["western_australia"] = western_australia;
  australia["eastern_australia"] = eastern_australia;
  australia["new_guinea"] = new_guinea;
  australia["indonesia"] = indonesia;

  //ASIA
  Territory* kamchatka = new Territory("kamchatka", vector<string> {"yakutsk", "irkutsk","alaska","mongolia","japan"});
  Territory* yakutsk = new Territory("yakutsk", vector<string> {"siberia", "irkutsk","kamchatka"});
  Territory* irkutsk = new Territory("irkutsk", vector<string> {"yakutsk", "siberia","mongolia","kamchatka"});
  Territory* siberia = new Territory("siberia", vector<string> {"ural", "afghanistan","china","mongolia","irkutsk","yakutsk"});
  Territory* ural = new Territory("ural", vector<string> {"ukraine", "afghanistan","siberia"});
  Territory* afghanistan = new Territory("afghanistan", vector<string> {"ukraine", "middle_east","india","china","siberia","ural"});
  Territory* middle_east = new Territory("middle_east", vector<string> {"ukraine", "egypt","india","afghanistan"});
  Territory* india = new Territory("india", vector<string> {"middle_east", "siam","china","afghanistan"});
  Territory* siam = new Territory("siam", vector<string> {"india", "indonesia","china"});
  Territory* china = new Territory("china", vector<string> {"afghanistan", "india","siam","mongolia","siberia"});
  Territory* mongolia = new Territory("mongolia", vector<string> {"siberia", "china","japan","kamchatka","irkutsk"});
  Territory* japan = new Territory("japan", vector<string> {"mongolia", "kamchatka"});

  asia["kamchatka"] = kamchatka;
  asia["yakutsk"] = yakutsk;
  asia["irkutsk"] = irkutsk;
  asia["siberia"] = siberia;
  asia["ural"] = ural;
  asia["afghanistan"] = afghanistan;
  asia["middle_east"] = middle_east;
  asia["india"] = india;
  asia["siam"] = siam;
  asia["china"] = china;
  asia["mongolia"] = mongolia;
  asia["japan"] = japan;
 
  //EUROPE
  Territory* iceland = new Territory("iceland", vector<string> {"greenland","great_britain"});
  Territory* great_britain = new Territory("great_britain", vector<string> {"iceland","western_europe","scandinavia","northern_europe"});
  Territory* western_europe = new Territory("western_europe", vector<string> {"great_britain","north_africa","southern_europe","northern_europe"});
  Territory* scandinavia = new Territory("scandinavia", vector<string> {"great_britain","ukraine"});
  Territory* northern_europe = new Territory("northern_europe", vector<string> {"great_britain","western_europe","southern_europe","ukraine"});
  Territory* ukraine = new Territory("ukraine", vector<string> {"scandinavia","northern_europe","southern_europe","middle_east","afghanistan","ural"});
  Territory* southern_europe = new Territory("southern_europe", vector<string> {"western_europe","north_africa","egypt","ukraine","northern_europe"});

  europe["iceland"] = iceland;
  europe["great_britain"] = great_britain;
  europe["western_europe"] = western_europe;
  europe["scandinavia"] = scandinavia;
  europe["northern_europe"] = northern_europe;
  europe["ukraine"] = ukraine;
  europe["southern_europe"] = southern_europe;

  //AFRICA

  Territory* north_africa = new Territory("north_africa", vector<string> {"brazil","western_europe","southern_europe","egypt","congo"});
  Territory* egypt = new Territory("egypt", vector<string> {"north_africa","congo","east_africa","middle_east","southern_europe"});
  Territory* congo = new Territory("congo", vector<string> {"north_africa","south_africa","east_africa","egypt"});
  Territory* east_africa = new Territory("east_africa", vector<string> {"congo","south_africa","madagascar","egypt"});
  Territory* south_africa = new Territory("south_africa", vector<string> {"congo","east_africa","madagascar"});
  Territory* madagascar = new Territory("madagascar", vector<string> {"south_africa","east_africa"});

  africa["north_africa"] = north_africa;
  africa["egypt"] = egypt;
  africa["congo"] = congo;
  africa["east_africa"] = east_africa;
  africa["south_africa"] = south_africa;
  africa["madagascar"] = madagascar;
  
  //SOUTH AMERICA

  Territory* venezuela = new Territory("venezuela", vector<string> {"central_america", "peru","brazil"});
  Territory* brazil = new Territory("brazil", vector<string> {"venezuela", "peru","argentina","north_africa" });
  Territory* peru = new Territory("peru", vector<string> {"venezuela", "brazil","argentina"});
  Territory* argentina = new Territory("argentina", vector<string> {"peru", "brazil"});

  south_america["venezuela"] = venezuela;
  south_america["brazil"] = brazil;
  south_america["peru"] = peru;
  south_america["argentina"] = argentina;

  //NORTH AMERICA

  Territory* central_america = new Territory("central_america", vector<string> {"venezuela","western_united_states"});
  Territory* eastern_united_states = new Territory("eastern_united_states", vector<string> {"central_america", "ontario", "quebec","western_united_states"});
  Territory* western_united_states = new Territory("western_united_states", vector<string> {"central_america", "alberta", "quebec","eastern_united_states"});
  Territory* ontario = new Territory("ontario", vector<string> {"western_united_states", "alberta", "quebec","northwest_territory", "eastern_united_states", "greenland"});
  Territory* alberta = new Territory("alberta", vector<string> {"western_united_states", "ontario", "alaska","northwest_territory"});
  Territory* quebec = new Territory("quebec", vector<string> {"eastern_united_states", "ontario","greenland"});
  Territory* greenland = new Territory("greenland", vector<string> {"quebec", "ontario", "iceland", "northwest_territory"});
  Territory* northwest_territory = new Territory("northwest_territory", vector<string> {"alaska", "ontario", "greenland", "alberta"});
  Territory* alaska = new Territory("alaska", vector<string> {"northwest_territory", "alberta", "kamchatka"});
 
  north_america["central_america"] = central_america;
  north_america["eastern_united_states"] = eastern_united_states;
  north_america["western_united_states"] = western_united_states;
  north_america["ontario"] = ontario;
  north_america["alberta"] = alberta;
  north_america["quebec"] = quebec;
  north_america["greenland"] = greenland;
  north_america["northwest_territory"] = northwest_territory;
  north_america["alaska"] = alaska;

  //WORLD

  world.insert(australia.begin(),australia.end());
  world.insert(asia.begin(),asia.end());
  world.insert(europe.begin(),europe.end());
  world.insert(africa.begin(),africa.end());
  world.insert(south_america.begin(),south_america.end());
  world.insert(north_america.begin(),north_america.end());


  //CARDS

  Card*  c1 = new Card("inf","congo");
  Card*  c2 = new Card("inf","china");
  Card*  c3 = new Card("inf","alaska"); 
  Card*  c4 = new Card("inf","new_guinea");
  Card*  c5 = new Card("inf","peru"); 
  Card*  c6 = new Card("inf","kamchatka");
  Card*  c7 = new Card("inf","mongolia");
  Card*  c8 = new Card("inf","middle_east");
  Card*  c9 = new Card("inf","siam");
  Card*  c10 = new Card("inf","venezuela");
  Card*  c11 = new Card("inf","east_africa");
  Card*  c12 = new Card("inf","iceland");
  Card*  c13 = new Card("inf","egypt");
  Card*  c14 = new Card("inf","argentina");

  Card*  c15 = new Card("cav","siberia");
  Card*  c16 = new Card("cav","madagascar");
  Card*  c17 = new Card("cav","afghanistan");
  Card*  c18 = new Card("cav","greenland");
  Card*  c19 = new Card("cav","alberta");
  Card*  c20 = new Card("cav","north_africa");
  Card*  c21 = new Card("cav","quebec");
  Card*  c22 = new Card("cav","scandinavia");
  Card*  c23 = new Card("cav","ontario");
  Card*  c24 = new Card("cav","irkutsk");
  Card*  c25 = new Card("cav","india");
  Card*  c26 = new Card("cav","ural");
  Card*  c27 = new Card("cav","yakutsk");
  Card*  c28 = new Card("cav","ukraine");

  Card*  c29 = new Card("art","great_britain");
  Card*  c30 = new Card("art","western_united_states");
  Card*  c31 = new Card("art","southern_europe");
  Card*  c32 = new Card("art","northwest_territory");
  Card*  c33 = new Card("art","eastern_united_states");
  Card*  c34 = new Card("art","brazil");
  Card*  c35 = new Card("art","western_europe");
  Card*  c36 = new Card("art","south_africa");
  Card*  c37 = new Card("art","indonesia");
  Card*  c38 = new Card("art","japan");
  Card*  c39 = new Card("art","western_australia");
  Card*  c40 = new Card("art","central_america");
  Card*  c41 = new Card("art","northern_europe");
  Card*  c42 = new Card("art","eastern_australia");
  Card* c43 = new Card("jok","");
  Card* c44 = new Card("jok","");

  stack = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32, c33, c34, c35, c36, c37, c38, c39, c40, c41, c42,c43,c44};

  random_shuffle(stack.begin(), stack.end());

    //Distribute areas to players:
  
   vector<Player>::iterator player = init_players.begin();

   for (vector<Card*>::iterator card = stack.begin(); card != stack.end(); ++card)
     {
       if ((*card)->get_terr() != "")
	 {
	   if (player == init_players.end())
	     player = init_players.begin();

	   get_territory((*card)->get_terr())->set_owner(player->get_color());
	   cout << (*card)->get_terr() + " is now owned by " + player->get_name() <<endl;
      
	    player++;
	 }
     }
  
  cout << "World initiated, territories distributed. Begin combat." << endl; 
}

int Worldmap::continental_bonus(string color)
{
  return own_asia(color)+ own_africa(color) + own_europe(color) + own_north_america(color) + own_south_america(color) + own_australia(color);
} 

Card* Worldmap::pop_card()
{
  if(stack.empty())
    {
      stack=discards;
      discards.clear();
      if (stack.empty())
	cerr << "Stack is empty!!!" << endl;
      random_shuffle(stack.begin(), stack.end());
    } 
  Card* r_card = stack[0];
  stack.erase(stack.begin());
  return r_card;

  /*
    int i = rand() % stack.size();
    Card* card_tmp = stack[i];
    stack.erase(stack.begin() + i);
    return card_tmp;
  */
}



void Worldmap::push_card(Card* card)
{
  discards.push_back(card);
}

Territory* Worldmap::get_territory(string str)
{
  Territory* test = world[str];
  if(test == 0)
    throw risk_error("Can't find: " + str);
  return test;
}

int Worldmap::get_reinforcements(string color)
{ 
  map<string, Territory*>::iterator it;
  int  count= 0;

  for ( it=world.begin() ; it != world.end(); ++it )
    {
      if( ((*it).second)->owned_by(color))
	{
	  //cout << (*it).second->owned_by(color) <<endl;
	  count++;
	}
    }
   
  return continental_bonus(color) + count/3;
}

//Owned continents
int Worldmap::own_asia(string color)
{
  map<string, Territory*>::iterator it;
  for ( it=asia.begin() ; it != asia.end(); it++ )
    {
      if(!((*it).second->owned_by(color)))
	{
	  return 0; 
	}
     }
return 7; //Kolla upp
}


int Worldmap::own_africa(string color)
{
   map<string, Territory*>::iterator it;
 for ( it=africa.begin() ; it != africa.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
return 3; //Kolla upp
}

int Worldmap::own_europe(string color)
{
   map<string, Territory*>::iterator it;
 for ( it=europe.begin() ; it !=europe.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
return 5; //Kolla upp
}


int Worldmap::own_north_america(string color)
{
   map<string, Territory*>::iterator it;
 for ( it=north_america.begin() ; it !=north_america.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
return 5; //Kolla upp
}

int Worldmap::own_south_america(string color)
{
   map<string, Territory*>::iterator it;
 for ( it=south_america.begin() ; it !=south_america.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
return 2; //Kolla upp
}



int Worldmap::own_australia(string color)
{
   map<string, Territory*>::iterator it;
 for ( it=australia.begin() ; it !=australia.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
return 2; //Kolla upp
}

bool Worldmap::game_over(string color)
{
map<string, Territory*>::iterator it;
 for ( it=world.begin() ; it !=world.end(); it++ )
     {
       if(!((*it).second->owned_by(color)))
       {
	 return 0; 
	}
     }
 return 1;
}

bool Worldmap::is_dead(string color)
{
  for (map<string, Territory*>::iterator it = world.begin() ; it != world.end(); it++)
    {
      if ( (*it).second->owned_by(color) )
	return false;
    }    
      return true;
}


void Worldmap::move_armies(Territory* curr, Territory* dest, int troops)
{  
    
  if (curr->get_owner() != dest->get_owner())
    {
      throw risk_error("Cannot reinforce territory not owned by you");
    }
  else if (curr->is_adjacent(dest->get_name()))
    {
      if(curr->get_armies() - troops >= 1)
	{
	  curr->remove_armies(troops);
	  dest->add_armies(dest->get_owner(), troops);
	  
	}
      else
	{
	  throw risk_error("Not enough troops to move");
	}
    }
  else
    {
      throw risk_error("Cannot move troops to a non-adjecent territory");
    }	 
}

