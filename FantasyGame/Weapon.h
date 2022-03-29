#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

using namespace std;

class Weapon 
{
private:
	int str, def, spe, cost;
	string wName;
public:
	Weapon();
	Weapon(int str, int def, int spe, int cost, string wName);
	int getStr() const;
	void setStr(int str);
	int getDef() const;
	void setDef(int def);
	int getSpe() const;
	void setSpe(int spe);
	int getCost() const;
	void setCost(int cost);
	string getWName() const;
	void setWName(string wName);
};

#endif