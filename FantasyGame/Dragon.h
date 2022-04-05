#ifndef DRAGON_H
#define DRAGON_H

#include <iostream>
#include "Enemy.h"

using namespace std;

class Dragon : public Enemy
{
public:
	Dragon();
	Dragon(int str, int spe, int def, int health, int stamina, int crit,
		int weaponIndex, int armorIndex, int wCount, int aCount);
	void setStats();
};

#endif