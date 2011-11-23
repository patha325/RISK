//territory.h
#ifndef TERRITORY_H
#define TERRITORY_H

#include <string>
#include <vector>

class Territory
{
 public:
  Territory(std::string, std::vector<std::string>);
  bool owned_by(std::string);
  void set_owner(); 
  void add_armies();
  void remove_armies();
 
 std::string get_owner();
  int get_armies();

  private:
  std::string name;
  int armies;
  std::string owner;
  std::vector<std::string> adjacent;

};
#endif
