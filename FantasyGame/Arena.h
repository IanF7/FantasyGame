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
	int playerDamage;
	int enemyDamage;
public:
	Arena();
	Arena(int playerDamage, int enemyDamage);
	void battle(Player player, Enemy enemy);
	void bossBattle(Player player, Dragon dragon);
	void setPlayerDamage(Player player, Enemy enemy);
	int getPlayerDamage() const;
	void setEnemyDamage(Enemy enemy, Player player);
	int getEnemyDamage() const;
	int checkCrit(int c);
};
#endif


