//battle.h

#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "territory.h"

class Battle
{
 public:
  Battle();
  bool new_battle(Territory*, Territory*);
  void attack(int);
  void retreat();
  void conquer(int);

  void set_battle();

  private:
  Territory* attacker;
  Territory* defender;

};

#endif
