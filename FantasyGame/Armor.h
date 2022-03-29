#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>

using namespace std;

class Armor
{
private:
	int str, def, spe, cost;
	string aName;
public:
	Armor();
	Armor(int str, int def, int spe, int cost, string aName);
	int getStr() const;
	void setStr(int str);
	int getDef() const;
	void setDef(int def);
	int getSpe() const;
	void setSpe(int spe);
	int getCost() const;
	void setCost(int cost);
	string getAName() const;
	void setAName(string aName);
};

#endif