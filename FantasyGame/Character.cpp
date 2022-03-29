#include <iostream>
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"

using namespace std;

Character::Character()
{
	str = spe = def = stamina = crit = 20;
	health = 50;
	weaponIndex = armorIndex = 0;
}

Character::Character(int str, int spe, int def, int health, int stamina, int crit, 
	 int weaponIndex, int armorIndex)
{
	this->str = str;
	this->spe = spe;
	this->def = def;
	this->health = health;
	this->stamina = stamina;
	this->crit = crit;
	this->weaponIndex = weaponIndex;
	this->armorIndex = armorIndex;
}


int Character::getStr() const
{
	return this->str;
}

void Character::setStr(int str)
{
	this->str = str;
}

int Character::getSpe() const
{
	return this->spe;
}

void Character::setSpe(int spe)
{
	this->spe = spe;
}

int Character::getDef() const
{
	return this->def;
}

void Character::setDef(int def)
{
	this->def = def;
}

int Character::getHealth() const
{
	return this->health;
}

void Character::setHealth(int health)
{
	this->health = health;
}

int Character::getStamina() const
{
	return stamina;
}

void Character::setStamina(int stamina)
{
	this->stamina = stamina;
}

int Character::getCrit() const
{
	return crit;
}

void Character::setCrit(int crit)
{
	this->crit = crit;
}

int Character::getWeaponIndex() const
{
	return weaponIndex;
}

void Character::setWeaponIndex(int weaponIndex, Weapon* weapons)
{
	this->weaponIndex = weaponIndex;
}

int Character::getArmorIndex() const
{
	return armorIndex;
}

void Character::setArmorIndex(int armorIndex, Armor* armorSets)
{
	this->armorIndex = armorIndex;
}

void Character::setStats(Weapon* weapons, Armor* armorSets, int weaponIndex, int armorIndex)
{
	weaponIndex = armorIndex = 0;
}


