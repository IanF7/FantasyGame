#include "Weapon.h"

//default contructor
Weapon::Weapon()
{
	//sets default strenght, defense, speed, and cost to 0, and name to an empty string
	str = def = spe = cost = 0;
	wName = "";
}

//parameterized constructor
Weapon::Weapon(int str, int def, int spe, int cost, string wName)
{
	this->str = str;
	this->def = def;
	this->spe = spe;
	this->cost = cost;
	this->wName = wName;
}

//getter for strength
int Weapon::getStr() const
{
	return str;
}

//setter for strength
void Weapon::setStr(int str)
{
	this->str = str;
}

//getter for defense
int Weapon::getDef() const
{
	return def;
}

//setter for defense
void Weapon::setDef(int def)
{
	this->def = def;
}

//getter for speed
int Weapon::getSpe() const
{
	return spe;
}

//setter for speed
void Weapon::setSpe(int spe)
{
	this->spe = spe;
}

//getter for cost
int Weapon::getCost() const
{
	return cost;
}

//setter for cost
void Weapon::setCost(int cost)
{
	this->cost = cost;
}

//getter for wName
string Weapon::getWName() const
{
	return wName;
}

//setter for wName
void Weapon::setWName(string wName)
{
	this->wName = wName;
}



