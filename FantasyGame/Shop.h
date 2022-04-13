#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Shop 
{
private:
	vector<Weapon*>weaponShop;
	vector<Armor*>armorShop;
	bool easterEgg;
public:
	Shop();
	Shop(vector<Weapon*>weaponShop, vector<Armor*>armorShop, bool easterEgg);
	void menu(Player &player);
	void buyWeapon(Player &player);
	void buyArmor(Player &player);
};
#endif