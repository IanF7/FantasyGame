#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include "Character.h"

using namespace std;

class Arena 
{
private:
	Character player, enemy;
public:
	Arena();
	Arena(Character player, Character enemy);
	void fight(Character &player, Character &enemy);
	void attackP(Character &player, Character &enemy);
	void attackE(Character &enemy, Character &player);
};
#endif


