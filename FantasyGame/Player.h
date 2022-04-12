
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include "Character.h"

using namespace std;

class Player : public Character
{
private:
	int gold, wCount, aCount;
	Weapon* weapons[12];
	Armor* armorSets[7];

public:
	Player();
	Player(int str, int spe, int def, int health, int stamina, int crit, int maxStamina,
		int weaponIndex, int armorIndex, int gold, int wCount, int aCount);
	int getGold() const;
	void setGold(int gold);
	int getWCount() const;
	void setWCount(int wCount);
	int getACount() const;
	void setACount(int aCount);
	void setWeaponIndex();
	void setArmorIndex();
	void setStats();
	void showStats();
	void updateWeapons(Weapon* weapon);
	void updateArmor(Armor* armor);
	friend ostream& operator<<(ostream& out, const Player& rhs);
	friend istream& operator>>(istream& in, Player& rhs);
};
#endif
