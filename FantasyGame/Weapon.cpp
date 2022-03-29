#include "Weapon.h"

Weapon::Weapon()
{
	str = def = spe = cost = 0;
	wName = "";
}

Weapon::Weapon(int str, int def, int spe, int cost, string wName)
{
	this->str = str;
	this->def = def;
	this->spe = spe;
	this->cost = cost;
	this->wName = wName;
}

int Weapon::getStr() const
{
	return str;
}

void Weapon::setStr(int str)
{
	this->str = str;
}

int Weapon::getDef() const
{
	return def;
}

void Weapon::setDef(int def)
{
	this->def = def;
}

int Weapon::getSpe() const
{
	return spe;
}

void Weapon::setSpe(int spe)
{
	this->spe = spe;
}

int Weapon::getCost() const
{
	return cost;
}

void Weapon::setCost(int cost)
{
	this->cost = cost;
}

string Weapon::getWName() const
{
	return wName;
}

void Weapon::setWName(string wName)
{
	this->wName = wName;
}


