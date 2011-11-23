//player.cc
#include "player.h"

#include <string>
#include <vector>

using namespace std;


Player::Player(string in_name, string in_color)
{
  name= in_name;
  color = in_color;
}

string Player::get_name()
{
  return name;

}

string Player::get_color()
{
  return color;

}
