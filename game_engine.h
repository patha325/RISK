
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include<vector>
#include<string>
#include "worldmap.h"
#include "battle.h"
#include "territory.h"
#include "card.h"
#include "player.h"

class Game_Engine
{
 public:
  Game_Engine(std::vector<Player>);


 private:
  std::vector<Player> players;
  int reinforcements;
  std::vector<Player>::iterator current_player;
  bool extra_card;

  //functions
  int use_cards(Card*,Card*,Card*);
  void next_player();
  int stoi(std::string);

  // Amendments
  std::string arg;
  void run();
  void finish_card(Card*);

  Battle battle;
  Worldmap world_map;

};

#endif


/*
Till�gg i andra klasser

void add_armies(string,int = 1) (Territory) Kasta fel om fel �gare
void move_troops(int) (Territory) Kasta fel om ej connected eller fel �gare

int get_reinforcements(string) (World_Map) 
Territory* get_territory(string) (World_Map)
void push_card(Card*) (World_Map)

Card* get_card(int); (Player)
void discard_card(Card*) (Player)


Modifikationer i andra klasser

void new_battle(Territory*, Territory*) (Battle)

new battle skall returnera ett fel om av n�gon anledning territorium A inte kan anfalla territorium B (pga ej angr�nsande, f�r lite trupper eller pga av att fel spelare �ger A / B)
annars initiera stridsparametrarna


int attack(int) (Battle)

returnerar 0 om anfallaren fick slut p� trupper, 1 om striden forts�tter och 2 om anfallaren lyckades besegra f�rsvararen

attack skall returnera falskt om striden tar slut (dvs om A eller B inte har trupper nog att forts�tta), annars sant

attack beh�ver inte returnera n�gra felmeddelanden, kvarvarande attackers flyttas in i det er�vrade territoriumet om anfallaren vinner 





 */
