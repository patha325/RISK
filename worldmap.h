//worldmap.h
#include "card.h"
#include "territory.h"
#include "player.h"

#include <string>
#include <vector>
#include <map>

class Worldmap
{
 public:
  Worldmap();
  Worldmap(std::vector<Player>);
  int continental_bonus(std::string);
  Card* pop_card();
  void push_card(Card*);
  Territory* get_territory(std::string);
  int get_reinforcements(std::string);
  int own_asia(std::string);
  int own_africa(std::string);
  int own_europe(std::string);
  int own_australia(std::string);
  int own_north_america(std::string);
  int own_south_america(std::string);
  void move_armies(Territory*, Territory*, int); 
    bool game_over(std::string);
  bool is_dead(std::string);

 private:
  
  std::map<std::string, Territory*> asia;
  std::map<std::string, Territory*> africa;
  std::map<std::string, Territory*> europe;
  std::map<std::string, Territory*> australia;
  std::map<std::string, Territory*> north_america;

  std::map<std::string, Territory*> america;
  std::map<std::string, Territory*> south_america;
  std::map<std::string, Territory*> world;
  std::vector <Card*> stack;
  std::vector<Card*> discards;

  

};
