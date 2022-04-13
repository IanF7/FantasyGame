#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include <vector>

using namespace std;

//default constructor
Character::Character()
{
	//sets all default stats to 20
	str = spe = def = stamina = maxStamina = crit = 20;
	//sets default health to 50
	health = 50;
	//sets default weapon and armor index to 0
	weaponIndex = armorIndex = 0;
}

//parameterized constructor
Character::Character(int str, int spe, int def, int health, int stamina, int maxStamina, int crit, 
	 int weaponIndex, int armorIndex)
{
	this->str = str;
	this->spe = spe;
	this->def = def;
	this->health = health;
	this->stamina = stamina;
	this->maxStamina = maxStamina;
	this->crit = crit;
	this->weaponIndex = weaponIndex;
	this->armorIndex = armorIndex;
}

//getter for strength
int Character::getStr() const
{
	return this->str;
}

//setter for strength
void Character::setStr(int str)
{
	this->str = str;
}

//getter for speed
int Character::getSpe() const
{
	return this->spe;
}

//setter for speed
void Character::setSpe(int spe)
{
	this->spe = spe;
}

//getter for defense
int Character::getDef() const
{
	return this->def;
}

//setter for defense
void Character::setDef(int def)
{
	this->def = def;
}

//getter for health
int Character::getHealth() const
{
	return this->health;
}

//setter for health
void Character::setHealth(int health)
{
	this->health = health;
}

//getter for stamina
int Character::getStamina() const
{
	return stamina;
}

//setter for stamina
void Character::setStamina(int stamina)
{
	this->stamina = stamina;
}

//getter for maxStamina
int Character::getMaxStamina() const
{
	return maxStamina;
}

//setter for maxStamina
void Character::setMaxStamina(int maxStamina)
{
	this->maxStamina = maxStamina;
}

//getter for crit
int Character::getCrit() const
{
	return crit;
}

//setter for crit
void Character::setCrit(int crit)
{
	this->crit = crit;
}

//getter for weaponIndex
int Character::getWeaponIndex() const
{
	return weaponIndex;
}

//setter for weaponIndex
void Character::setWeaponIndex()
{
	this->weaponIndex = weaponIndex;
}

//getter for armorIndex
int Character::getArmorIndex() const
{
	return armorIndex;
}

//setter for armorIndex
void Character::setArmorIndex()
{
	this->armorIndex = armorIndex;
}

//setStats
void Character::setStats()
{
	//sets armor and weapon index to 0
	armorIndex = 0;
	weaponIndex = 0;
}

void Character::showStats()
{
	//displays basic stats with no values
	cout << "Health: " << endl;
	cout << "Str: " << endl;
	cout << "Def: " << endl;
	cout << "Spe: " << endl;
	cout << "Stamina: " << endl;
}


