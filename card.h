//card.h
#include <string>
#include <vector>

class Card
{
 public:
  Card(std::string, std::string);
  std::string get_type();
  std::string get_terr();

  private:
  std::string type;
  std::string terr;

};
