
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Character.h"

using namespace std;

class Player : public Character
{
private:
	int gold, wCount, aCount;
	Weapon* weapons[10];
	Armor* armorSets[7];
public:
	Player();
	Player(int str, int spe, int def, int health, int stamina, int crit,
		int weaponIndex, int armorIndex, int gold, int wCount, int aCount);
	int getGold() const;
	void setGold(int gold);
	int getWCount() const;
	void setWCount(int wCount);
	int getACount() const;
	void setACount(int aCount);
	Weapon* getWeapons() const;
	void setWeapons(Weapon* weapons);
	Armor* getArmorSets() const;
	void setArmorSets(Armor* armorSets);
	void setWeaponIndex(int weaponIndex, Weapon* weapons);
	void setArmorIndex(int armorIndex, Armor* armorSets);
	void setStats(Weapon* weapons, Armor* armorSets, int weaponIndex, int armorIndex);
};
#endif
