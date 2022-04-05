#include "Dragon.h"

Dragon::Dragon() {}

Dragon::Dragon(int str, int spe, int def, int health, int stamina, int crit, 
	int weaponIndex, int armorIndex, int wCount, int aCount) {}

void Dragon::setStats()
{
	string difficulty = "";
	int strRand = 0;
	int speRand = 0;
	int defRand = 0;
	cout << "Select difficulty: " << endl;
	cout << "EASY    MEDIUM    HARD    EXTREME" << endl;
	do
	{
		cin >> difficulty;
		for (int i = 0; i < difficulty.length(); i++)
		{
			difficulty[i] = tolower(difficulty[i]);
		}
	} while (difficulty != "easy" && difficulty != "medium" && difficulty != "hard" &&
		difficulty != "extreme");
	if (difficulty == "easy")
	{
		setHealth(70);
		setReward(100);
	}
	else if (difficulty == "medium")
	{
		setHealth(80);
		setReward(120);
	}
	else if (difficulty == "hard")
	{
		setHealth(90);
		setReward(140);
	}
	else if (difficulty == "extreme")
	{
		setHealth(100);
		setReward(160);
	}
	setCrit(20);
	setStr(0);
	setDef(0);
	setSpe(0);
	setStamina(0);
	cout << "" << endl;
	cout << "Enemy Stats: " << endl;
}


