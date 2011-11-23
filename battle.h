//battle.h
#include <string>


class Battle
{
 public:
  Battle();
  bool new_battle(Territory*, Territory*);
  void attack(int);
  void retreat;
  void conquer(int);

  void set_battle();

  private:
  Territory* attacker;
  Territory* defender;

};
