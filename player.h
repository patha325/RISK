//player.h
#include "card.h"
#include <string>
#include <vector>


class Player
{
public:
  Player(std::string, std::string);
  std::string get_name();
  std::string get_color();

private:
  std::string name;
  std::string color;
  std::vector<Card> cards;
};
