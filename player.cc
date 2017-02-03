//player.cc
#include "player.h"
#include "risk_error.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


Player::Player(string in_name, string in_color)
{
  name= in_name;
  color = in_color;
}

string Player::get_name()
{
  return name;

}

string Player::get_color()
{
  return color;

}



Card* Player::get_card(int position)
{
  if ( position < 0 || position > cards.size())
    throw risk_error("Please select the card you own.");

  return cards[position];
}

void Player::discard_card(Card* card)
{
  for (vector<Card*>::iterator it = cards.begin() ; it < cards.end(); it++ )
    {
      if( (*it)->get_terr() == card->get_terr())
      	cards.erase(it);
    }
}

void Player::give_card(Card* card)
{
  cards.push_back(card);

}

void Player::print_cards()
{
  int i = 0;
  for (vector<Card*>::iterator it = cards.begin(); it != cards.end(); ++it)
    {
      
      cout << i++ << ": " << (*it)->get_type() << " " << (*it)->get_terr() << endl;
    }  
}

int Player::n_cards()
{
  return cards.size();
}
