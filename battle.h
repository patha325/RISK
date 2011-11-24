//battle.h

#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "territory.h"

class Battle
{
 public:
  Battle();
  bool new_battle(Territory*, Territory*, std::string);
  int attack(int);
  void retreat();
  void conquer(int);

  private:
  Territory* attacker;
  Territory* defender;
};
#endif
