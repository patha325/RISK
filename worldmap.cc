//worldmap.cc
#include "worldmap.h"


#include <string>
#include <vector>
#include <map>
#include <cstdlib>


using namespace std;


Worldmap::Worldmap()
{
  //Australia
  vector<string> adj_w_aus { "eastern_australia", "indonesia", "new_guinea"};

  Territory*  western_australia = new Territory("red","western_australia", adj_w_aus);


  
  vector<string> adj_e_aus { "western_australia", "new_guinea "};

  Territory*  eastern_australia = new Territory("green","eastern_australia", adj_e_aus);


  vector<string> adj_new_gui { "western_australia", "eastern_australia", "indonesia"};

  Territory*  new_guinea = new Territory("red","new_guinea", adj_new_gui);


  vector<string> adj_indo { "western_australia", "new_guinea"};

  Territory* indonesia = new Territory("green","indonesia", adj_indo);

  australia["western_australia"] =western_australia;
  australia["eastern_australia"] =eastern_australia;
  australia["new_guinea"] = new_guinea;
  australia["indonesia"] = indonesia;



  //Asia osv osv



  world.insert(australia.begin(),australia.end());
  //Cards

   Card*  c1 = new Card("canon","western_australia"); // PATRIK

  Card* c2 = new Card("canon","eastern_australia");

  Card*  c3 = new Card("canon","indonesia");
 
  Card*  c4 = new Card("canon","new_guinea");

  stack = {c1, c2, c3, c4 };

}

int continental_bonus(string str)
{
  
} 

Card* Worldmap::pop_card()
{
  int i = rand() % stack.size();
  Card* card_tmp = stack[i];
  stack.erase(stack.begin() + i);
  return card_tmp;
}

void Worldmap::push_card(Card* card)
{

}

Territory* Worldmap::get_territory(string str)
{
  return world[str];
}

int Worldmap::get_reinforcements(string color)
{
  //  return continentalbonus(color) + 
}
