//battle.cc

#include "battle.h"
#include "territory.h"
#include <string>
using namespace std;

Battle::Battle(){}

bool Battle::new_battle(Territory* terr1 , Territory* terr2, string color)
{
  // if (!(terr1->owned_by(color)) || terr1->get_armies() == 1 || terr2->owned_by(color))
    //  throw risk_error("Unable to initiate attack.");

  attacker = terr1;
  defender = terr2;
}

int  Battle::attack(int attackers)
{
  // if (attackers >= attacker->get_armies())
  //  throw risk_error("You don't have enough troops!");


}

void Battle::retreat()
{

}


void conquer(int i)
{

}
