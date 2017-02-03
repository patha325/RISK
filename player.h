//player.h
#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <string>
#include <vector>


class Player
{
public:
  Player(std::string, std::string);
  std::string get_name();
  std::string get_color();
  Card* get_card(int);
  void discard_card(Card*);
  void print_cards();
  int n_cards();
  void give_card(Card*);
private:
  std::string name;
  std::string color;
  std::vector<Card*> cards;
};

#endif
