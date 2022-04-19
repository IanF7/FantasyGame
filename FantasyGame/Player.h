
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include "Character.h"

using namespace std;

class Player : public Character
{
private:
	int gold, wCount, aCount, level;
	Weapon* weapons[12];
	Armor* armorSets[7];

public:
	Player();
	Player(int str, int spe, int def, int health, int stamina, int crit, int maxStamina,
		int weaponIndex, int armorIndex, int gold, int wCount, int aCount, int level);
	int getGold() const;
	void setGold(int gold);
	int getWCount() const;
	void setWCount(int wCount);
	int getACount() const;
	void setACount(int aCount);
	int getLevel() const;
	void setLevel(int level);
	void setWeaponIndex();
	void setArmorIndex();
	void setStats();
	void showStats();
	void updateWeapons(Weapon* weapon);
	void updateArmor(Armor* armor);
	bool compareWName(string compare);
	bool compareAName(string compare);
	void saveCharacter();
	void loadCharacter();
};
#endif
