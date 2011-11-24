//territory.h
#ifndef TERRITORY_H
#define TERRITORY_H
#include <string>
#include <vector>
#include "risk_error.h"

class Territory
{
 public:
  Territory(std::string, std::vector<std::string>);
  bool owned_by(std::string);
  void set_owner(std::string); 
  void add_armies(std::string, int=1);
  void remove_armies(int);
  void move_armies(std::string, Territory*, int); //fixa till så att trupper förflyttas!
 
 
 std::string get_owner();
  int get_armies();

  private:
  std::string name;
  int armies;
  std::string owner;
  std::vector<std::string> adjacent;

};

#endif
