#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Dragon.h"

using namespace std;

class Arena 
{
private:
	Player p1;
	Enemy e1;
	Dragon d1;
public:
	Arena();
	Arena(Player p1, Enemy e1);
	void fight(Player &p1, Enemy &e1);
	void bossFight(Player& p1, Dragon& d1);
	int attackP(Player &p1, Enemy &e1);
	int attackE(Enemy &e1, Player &p1);
	int pAttackD(Player& p1, Dragon& d1);
};
#endif


