#include "Armor.h"

Armor::Armor()
{
	str = def = spe = cost = 0;
	aName = "";
}

Armor::Armor(int str, int def, int spe, int cost, string aName)
{
	this->str = str;
	this->def = def;
	this->spe = spe;
	this->cost = cost;
	this->aName = aName;
}

int Armor::getStr() const
{
	return str;
}

void Armor::setStr(int str)
{
	this->str = str;
}

int Armor::getDef() const
{
	return def;
}

void Armor::setDef(int def)
{
	this->def = def;
}

int Armor::getSpe() const
{
	return spe;
}

void Armor::setSpe(int spe)
{
	this->spe = spe;
}

int Armor::getCost() const
{
	return cost;
}

void Armor::setCost(int cost)
{
	this->cost = cost;
}

string Armor::getAName() const
{
	return aName;
}

void Armor::setAName(string aName)
{
	this->aName = aName;
}


