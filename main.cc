
#include <vector>
#include <string>
#include "game_engine.h"
using namespace std;

int main()
{
  Player p1 = Player("patrik", "red");
  Player p2 = Player("hans","green");
  vector<Player> players;
  players.push_back(p1);
  players.push_back(p2);

  Game_Engine game =Game_Engine(players);
  game.run();

  return 0;
}
