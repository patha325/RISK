
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
Tillägg i andra klasser

void add_armies(string,int = 1) (Territory) Kasta fel om fel ägare
void move_troops(int) (Territory) Kasta fel om ej connected eller fel ägare

int get_reinforcements(string) (World_Map) 
Territory* get_territory(string) (World_Map)
void push_card(Card*) (World_Map)

Card* get_card(int); (Player)
void discard_card(Card*) (Player)


Modifikationer i andra klasser

void new_battle(Territory*, Territory*) (Battle)

new battle skall returnera ett fel om av någon anledning territorium A inte kan anfalla territorium B (pga ej angränsande, för lite trupper eller pga av att fel spelare äger A / B)
annars initiera stridsparametrarna


int attack(int) (Battle)

returnerar 0 om anfallaren fick slut på trupper, 1 om striden fortsätter och 2 om anfallaren lyckades besegra försvararen

attack skall returnera falskt om striden tar slut (dvs om A eller B inte har trupper nog att fortsätta), annars sant

attack behöver inte returnera några felmeddelanden, kvarvarande attackers flyttas in i det erövrade territoriumet om anfallaren vinner 





 */
