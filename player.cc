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
  Card*  c1 = new Card("canon","western_australia"); // PATRIK
  cards.push_back(c1); // PATRIK

  if(cards.size() < position) // PATRIK
    throw risk_error("You don't have that many cards");
  return cards[position];

}

void Player::discard_card(Card* card)
{
  vector<Card*>::iterator it;

  for ( it=cards.begin() ; it < cards.end(); it++ )
    {
      if( (*it)->get_terr() == card->get_terr())
      	cards.erase(it);
    }

}
