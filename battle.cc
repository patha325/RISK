//battle.cc

#include "battle.h"
#include "territory.h"
#include "risk_error.h"
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
using namespace std;

Battle::Battle(){}

void Battle::new_battle(Territory* terr1 , Territory* terr2, string color)
{
  if (!(terr1->owned_by(color)) || terr1->get_armies() == 1 || terr2->owned_by(color) || !(terr1->is_adjacent(terr2->get_name())))
    {
      cout << "Player: " + terr1->get_owner() + " owns " + terr1->get_name() + " and Player: " + terr2->get_owner() + " owns " + terr2->get_name() <<endl; // PATRIK
    throw risk_error("Unable to initiate attack.");
    }
  attacker = terr1;
  defender = terr2;

  cout << attacker->get_armies() << " brave attackers face off against " << defender->get_armies() << " meagre defenders." << endl;
}

int Battle::attack(int attackers)
{ 
  if( attackers > 3 || attackers < 1)
    throw risk_error("Please attack with 1 to 3 troops.");
  if (attackers >= attacker->get_armies())
    throw risk_error("You don't have enough troops!");

  vector<int> a_rolls;
  vector<int> d_rolls;
  srand (time(NULL));

  a_rolls.push_back(diceroll());
  if (attackers >=2)
    a_rolls.push_back(diceroll());
  else 
    a_rolls.push_back(0);
  if (attackers == 3)
    a_rolls.push_back(diceroll());
  else 
    a_rolls.push_back(0);

  d_rolls.push_back(diceroll());
  if (defender->get_armies() >= 2)
    d_rolls.push_back(diceroll());
  else d_rolls.push_back(0);

  sort(a_rolls.begin(),a_rolls.end());
  sort(d_rolls.begin(),d_rolls.end());
  reverse(a_rolls.begin(),a_rolls.end());
  reverse(d_rolls.begin(),d_rolls.end());


  cout << "Attacker rolled " << a_rolls[0] << a_rolls[1] << a_rolls[2] << endl;
  cout << "Defender rolled " << d_rolls[0] << d_rolls[1] << endl;

  for (int i = 0; i < 2; ++i)
    {
      if (a_rolls[i] > d_rolls[i])
	defender->remove_armies();
      else attacker->remove_armies();
      if (defender->get_armies() == 0)
	return 2;	
      if (attacker->get_armies() == 1)	
	return 0;
      if ( i==0 && (a_rolls[i+1] == 0 || d_rolls[i+1]==0))
	break;
    }
  cout << "The battle is still raging! Attacker has "<<attacker->get_armies()<<" troops left and Defender has "<<defender->get_armies()<<" troops left."<<endl; 
  return 1;
}

void Battle::conquer(int attackers,int settlers)
{
  if (settlers  > (attacker->get_armies() - 1))
    throw risk_error("You don't have that many armies to transfer!");
  if (settlers < attackers)
    throw risk_error("You need to move more armies!");

  defender->set_owner(attacker->get_owner());
  attacker->remove_armies(settlers);
  defender->add_armies(attacker->get_owner(), settlers);
}

int Battle::diceroll()
{
    int i = rand() % 6 +1;

  return i;
}

