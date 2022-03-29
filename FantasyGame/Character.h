
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Character 
{
private:
	int str, spe, def, health, stamina, crit;
	int weaponIndex, armorIndex;

public:
	Character();
	Character(int str, int spe, int def, int health, int stamina, int crit,
		 int weaponIndex, int armorIndex);
	int getStr() const;
	void setStr(int str);
	int getSpe() const;
	void setSpe(int spe);
	int getDef() const;
	void setDef(int def);
	int getHealth() const;
	void setHealth(int Health);
	int getStamina() const;
	void setStamina(int stamina);
	int getCrit() const;
	void setCrit(int crit);
	int getWeaponIndex() const;
	virtual void setWeaponIndex(int weaponIndex, Weapon* weapons);
	int getArmorIndex() const;
	virtual void setArmorIndex(int armorIndex, Armor* armorSets);
	virtual void setStats(Weapon* weapons, Armor* armorSets, int weaponIndex, int armorIndex);
};
#endif



