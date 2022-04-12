#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"

using namespace std;

class Enemy : public Character
{
private:
	int wCount, aCount, reward;
	Weapon* weapons[10];
	Armor* armorSets[7];
public:
	Enemy();
	Enemy(int str, int spe, int def, int health, int stamina, int maxStamina, int crit,
		int weaponIndex, int armorIndex, int wCount, int aCount, int reward);
	int getWCount() const;
	void setWCount(int wCount);
	int getACount() const;
	void setACount(int aCount);
	void setWeaponIndex();
	void setArmorIndex();
	void setStats();
	void showStats();
	int getReward() const;
	void setReward(int reward);
};

#endif
