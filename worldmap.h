//worldmap.h
#include "card.h"
#include "territory.h"

#include <string>
#include <vector>
#include <map>


class Worldmap
{
 public:
  Worldmap();
  int continental_bonus(std::string);
  Card pop_card();
  void push_card(Card);
  
 private:
  std::map<std::string, Territory> world;
  std::map<std::string, Territory> asia;
  std::map<std::string, Territory> africa;
  std::map<std::string, Territory> europe;
  std::map<std::string, Territory> australia;
  std::map<std::string, Territory> america;
  std::map<std::string, Territory> south_america;
  std::vector <Card> stack;
  std::vector<Card> discards;
};