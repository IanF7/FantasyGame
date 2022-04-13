#include "Armor.h"

//default constructor
Armor::Armor()
{
	//sets default strenght, defense, speed, and cost to 0, and name to an empty string
	str = def = spe = cost = 0;
	aName = "";
}

//parameterized constructor
Armor::Armor(int str, int def, int spe, int cost, string aName)
{
	this->str = str;
	this->def = def;
	this->spe = spe;
	this->cost = cost;
	this->aName = aName;
}

//getter for strength
int Armor::getStr() const
{
	return str;
}

//setter for strength
void Armor::setStr(int str)
{
	this->str = str;
}

//getter for defense
int Armor::getDef() const
{
	return def;
}

//setter for defense
void Armor::setDef(int def)
{
	this->def = def;
}

//getter for speed
int Armor::getSpe() const
{
	return spe;
}

//setter for speed
void Armor::setSpe(int spe)
{
	this->spe = spe;
}

//getter for cost
int Armor::getCost() const
{
	return cost;
}

//setter for cost
void Armor::setCost(int cost)
{
	this->cost = cost;
}

//getter for aName
string Armor::getAName() const
{
	return aName;
}

//setter for aName
void Armor::setAName(string aName)
{
	this->aName = aName;
}


