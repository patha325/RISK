//territory.cc
#include "territory.h"

#include <string>
#include <vector>


using namespace std;



Territory::Territory(string str, vector <string> vect)
{
  name = str;
  adjacent = vect;  
}


bool Territory::owned_by(string str)
{
  return(str == owner);
}

void Territory::set_owner(string color)
{
  owner = color;
}


string Territory::get_owner()
{
  return owner;
}


void Territory::add_armies(string color, int troop)
{
  if (color != owner)
    throw risk_error("Cannot reinforce territory not owned by you");
    
      armies = armies + troop;
}


void Territory::remove_armies(int troop)
{
  
      armies = armies - troop;
}


int Territory::get_armies()
{
  return armies;

}


void Territory::move_armies(string color, Territory* dest, int troops)
{  
if (color != owner)
    throw risk_error("Cannot reinforce territory not owned by you");

}
