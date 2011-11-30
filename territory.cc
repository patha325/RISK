//territory.cc
#include "territory.h"

#include <string>
#include <vector>
#include <algorithm>

using namespace std;



Territory::Territory(string init_owner,string str, vector <string> vect)
{
  owner=init_owner;
  name = str;
  adjacent = vect;  
  armies=5;
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

string Territory::get_name()
{
  return name;
}

bool Territory::is_adjacent(string ad_name)
{
  return (find(adjacent.begin(),adjacent.end(), ad_name) != adjacent.end());

}
