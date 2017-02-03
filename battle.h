//battle.h

#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "territory.h"

class Battle
{
 public:
  Battle();
  void new_battle(Territory*, Territory*, std::string);
  int attack(int);
  void conquer(int,int);

  private:
  Territory* attacker;
  Territory* defender;
  int diceroll();
};
#endif
